// This file contains helper functions that are automatically created from
// templates.

#include "nuitka/prelude.h"

extern PyObject *callPythonFunction( PyObject *func, PyObject **args, int count );


PyObject *CALL_FUNCTION_WITH_ARGS1( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 1; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 1 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 1; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 1 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 1 * sizeof(PyObject *) );
            memcpy( python_pars + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 1 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 1 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 1; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 1 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 1 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 1 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 1 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (1 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 1 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (1 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 1 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 1, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 1 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            1
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 1 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS2( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 2; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 2 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 2; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 2 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 2 * sizeof(PyObject *) );
            memcpy( python_pars + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 2 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 2 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 2; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 2 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 2 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 2 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 2 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (2 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 2 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (2 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 2 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 2, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 2 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            2
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 2 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS3( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 3; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 3 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 3; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 3 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 3 * sizeof(PyObject *) );
            memcpy( python_pars + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 3 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 3 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 3; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 3 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 3 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 3 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 3 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (3 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 3 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (3 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 3 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 3, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 3 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            3
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 3 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS4( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 4; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 4 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 4; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 4 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 4 * sizeof(PyObject *) );
            memcpy( python_pars + 4, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 4 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 4 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 4; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 4 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 4 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 4, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 4 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 4 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (4 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 4 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (4 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 4 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 4, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 4 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            4
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 4 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS5( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 5; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 5 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 5; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 5 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 5 * sizeof(PyObject *) );
            memcpy( python_pars + 5, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 5 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        struct Nuitka_MethodObject *method = (struct Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            struct Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 5 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 5; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 5 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 5 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 5, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 5 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called ) & ~(METH_CLASS | METH_STATIC | METH_COEXIST);

        if ( flags & METH_NOARGS )
        {
#if 5 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (5 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 5 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (5 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_VARARGS )
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 5 );

            PyObject *result;

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

#if PYTHON_VERSION < 360
            if ( flags & METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#else
            if ( flags == ( METH_VARARGS | METH_KEYWORDS ) )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else if ( flags == METH_FASTCALL )
            {
#if PYTHON_VERSION < 370
                result = (*(_PyCFunctionFast)method)( self, &PyTuple_GET_ITEM( pos_args, 0 ), 5, NULL );;
#else
                result = (*(_PyCFunctionFast)method)( self, &pos_args, 5 );;
#endif
            }
            else
            {
                result = (*method)( self, pos_args );
            }
#endif

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
                // Some buggy C functions do set an error, but do not indicate it
                // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            5
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 5 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_METHOD_WITH_ARGS1( PyObject *source, PyObject *attr_name, PyObject **args )
{
    CHECK_OBJECT( source );
    CHECK_OBJECT( attr_name );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 1; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    PyTypeObject *type = Py_TYPE( source );

    if ( type->tp_getattro == PyObject_GenericGetAttr )
    {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely( type->tp_dict == NULL ))
        {
            if (unlikely( PyType_Ready( type ) < 0 ))
            {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup( type, attr_name );
        descrgetfunc func = NULL;

        if ( descr != NULL )
        {
            Py_INCREF( descr );

#if PYTHON_VERSION < 300
            if ( PyType_HasFeature( Py_TYPE( descr ), Py_TPFLAGS_HAVE_CLASS ) )
            {
#endif
                func = Py_TYPE( descr )->tp_descr_get;

                if ( func != NULL && PyDescr_IsData( descr ) )
                {
                    PyObject *called_object = func( descr, source, (PyObject *)type );
                    Py_DECREF( descr );

                    PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                        called_object,
                        args
                    );
                    Py_DECREF( called_object );
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if ( dict != NULL )
        {
            CHECK_OBJECT( dict );

            Py_INCREF( dict );

            PyObject *called_object = PyDict_GetItem( dict, attr_name );

            if ( called_object != NULL )
            {
                Py_INCREF( called_object );
                Py_XDECREF( descr );
                Py_DECREF( dict );

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF( called_object );
                return result;
            }

            Py_DECREF( dict );
        }

        if ( func != NULL )
        {
            if ( func == Nuitka_Function_Type.tp_descr_get )
            {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    1
                );

                Py_DECREF( descr );

                return result;
            }
            else
            {
                PyObject *called_object = func( descr, source, (PyObject *)type );
                CHECK_OBJECT( called_object );

                Py_DECREF( descr );

                PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                    called_object,
                    args
                );
                Py_DECREF( called_object );

                return result;
            }
        }

        if ( descr != NULL )
        {
            CHECK_OBJECT( descr );

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                descr,
                args
            );
            Py_DECREF( descr );

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if ( type == &PyInstance_Type )
    {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert( attr_name != const_str_plain___dict__ );
        assert( attr_name != const_str_plain___class__ );

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            return CALL_FUNCTION_WITH_ARGS1( called_object, args );
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            descrgetfunc descr_get = Py_TYPE( called_object )->tp_descr_get;

            if ( descr_get == Nuitka_Function_Type.tp_descr_get )
            {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    1
                );
            }
            else if ( descr_get != NULL )
            {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely( method == NULL ))
                {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS1( method, args );
                Py_DECREF( method );
                return result;
            }
            else
            {
                return CALL_FUNCTION_WITH_ARGS1( called_object, args );
            }

        }
        else if (unlikely( source_instance->in_class->cl_getattr == NULL ))
        {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        }
        else
        {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely( called_object == NULL ))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS1(
                called_object,
                args
            );
            Py_DECREF( called_object );
            return result;
        }
    }
#endif
    else if ( type->tp_getattro != NULL )
    {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else if ( type->tp_getattr != NULL )
    {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked( attr_name )
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS1(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else
    {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked( attr_name )
        );

        return NULL;
    }
}

PyObject *CALL_METHOD_WITH_ARGS2( PyObject *source, PyObject *attr_name, PyObject **args )
{
    CHECK_OBJECT( source );
    CHECK_OBJECT( attr_name );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 2; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    PyTypeObject *type = Py_TYPE( source );

    if ( type->tp_getattro == PyObject_GenericGetAttr )
    {
        // Unfortunately this is required, although of cause rarely necessary.
        if (unlikely( type->tp_dict == NULL ))
        {
            if (unlikely( PyType_Ready( type ) < 0 ))
            {
                return NULL;
            }
        }

        PyObject *descr = _PyType_Lookup( type, attr_name );
        descrgetfunc func = NULL;

        if ( descr != NULL )
        {
            Py_INCREF( descr );

#if PYTHON_VERSION < 300
            if ( PyType_HasFeature( Py_TYPE( descr ), Py_TPFLAGS_HAVE_CLASS ) )
            {
#endif
                func = Py_TYPE( descr )->tp_descr_get;

                if ( func != NULL && PyDescr_IsData( descr ) )
                {
                    PyObject *called_object = func( descr, source, (PyObject *)type );
                    Py_DECREF( descr );

                    PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                        called_object,
                        args
                    );
                    Py_DECREF( called_object );
                    return result;
                }
#if PYTHON_VERSION < 300
            }
#endif
        }

        Py_ssize_t dictoffset = type->tp_dictoffset;
        PyObject *dict = NULL;

        if ( dictoffset != 0 )
        {
            // Negative dictionary offsets have special meaning.
            if ( dictoffset < 0 )
            {
                Py_ssize_t tsize;
                size_t size;

                tsize = ((PyVarObject *)source)->ob_size;
                if (tsize < 0)
                    tsize = -tsize;
                size = _PyObject_VAR_SIZE( type, tsize );

                dictoffset += (long)size;
            }

            PyObject **dictptr = (PyObject **) ((char *)source + dictoffset);
            dict = *dictptr;
        }

        if ( dict != NULL )
        {
            CHECK_OBJECT( dict );

            Py_INCREF( dict );

            PyObject *called_object = PyDict_GetItem( dict, attr_name );

            if ( called_object != NULL )
            {
                Py_INCREF( called_object );
                Py_XDECREF( descr );
                Py_DECREF( dict );

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF( called_object );
                return result;
            }

            Py_DECREF( dict );
        }

        if ( func != NULL )
        {
            if ( func == Nuitka_Function_Type.tp_descr_get )
            {
                PyObject *result = Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)descr,
                    source,
                    args,
                    2
                );

                Py_DECREF( descr );

                return result;
            }
            else
            {
                PyObject *called_object = func( descr, source, (PyObject *)type );
                CHECK_OBJECT( called_object );

                Py_DECREF( descr );

                PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                    called_object,
                    args
                );
                Py_DECREF( called_object );

                return result;
            }
        }

        if ( descr != NULL )
        {
            CHECK_OBJECT( descr );

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                descr,
                args
            );
            Py_DECREF( descr );

            return result;
        }

#if PYTHON_VERSION < 300
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            PyString_AS_STRING( attr_name )
        );
#else
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%U'",
            type->tp_name,
            attr_name
        );
#endif
        return NULL;
    }
#if PYTHON_VERSION < 300
    else if ( type == &PyInstance_Type )
    {
        PyInstanceObject *source_instance = (PyInstanceObject *)source;

        // The special cases have their own variant on the code generation level
        // as we are called with constants only.
        assert( attr_name != const_str_plain___dict__ );
        assert( attr_name != const_str_plain___class__ );

        // Try the instance dict first.
        PyObject *called_object = GET_STRING_DICT_VALUE(
            (PyDictObject *)source_instance->in_dict,
            (PyStringObject *)attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            return CALL_FUNCTION_WITH_ARGS2( called_object, args );
        }

        // Then check the class dictionaries.
        called_object = FIND_ATTRIBUTE_IN_CLASS(
            source_instance->in_class,
            attr_name
        );

        // Note: The "called_object" was found without taking a reference,
        // so we need not release it in this branch.
        if ( called_object != NULL )
        {
            descrgetfunc descr_get = Py_TYPE( called_object )->tp_descr_get;

            if ( descr_get == Nuitka_Function_Type.tp_descr_get )
            {
                return Nuitka_CallMethodFunctionPosArgs(
                    (struct Nuitka_FunctionObject const *)called_object,
                    source,
                    args,
                    2
                );
            }
            else if ( descr_get != NULL )
            {
                PyObject *method = descr_get(
                    called_object,
                    source,
                    (PyObject *)source_instance->in_class
                );

                if (unlikely( method == NULL ))
                {
                    return NULL;
                }

                PyObject *result = CALL_FUNCTION_WITH_ARGS2( method, args );
                Py_DECREF( method );
                return result;
            }
            else
            {
                return CALL_FUNCTION_WITH_ARGS2( called_object, args );
            }

        }
        else if (unlikely( source_instance->in_class->cl_getattr == NULL ))
        {
            PyErr_Format(
                PyExc_AttributeError,
                "%s instance has no attribute '%s'",
                PyString_AS_STRING( source_instance->in_class->cl_name ),
                PyString_AS_STRING( attr_name )
            );

            return NULL;
        }
        else
        {
            // Finally allow the "__getattr__" override to provide it or else
            // it's an error.

            PyObject *args2[] = {
                source,
                attr_name
            };

            called_object = CALL_FUNCTION_WITH_ARGS2(
                source_instance->in_class->cl_getattr,
                args2
            );

            if (unlikely( called_object == NULL ))
            {
                return NULL;
            }

            PyObject *result = CALL_FUNCTION_WITH_ARGS2(
                called_object,
                args
            );
            Py_DECREF( called_object );
            return result;
        }
    }
#endif
    else if ( type->tp_getattro != NULL )
    {
        PyObject *called_object = (*type->tp_getattro)(
            source,
            attr_name
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else if ( type->tp_getattr != NULL )
    {
        PyObject *called_object = (*type->tp_getattr)(
            source,
            (char *)Nuitka_String_AsString_Unchecked( attr_name )
        );

        if (unlikely( called_object == NULL ))
        {
            return NULL;
        }

        PyObject *result = CALL_FUNCTION_WITH_ARGS2(
            called_object,
            args
        );
        Py_DECREF( called_object );
        return result;
    }
    else
    {
        PyErr_Format(
            PyExc_AttributeError,
            "'%s' object has no attribute '%s'",
            type->tp_name,
            Nuitka_String_AsString_Unchecked( attr_name )
        );

        return NULL;
    }
}
/* Code to register embedded modules for meta path based loading if any. */

#include "nuitka/unfreezing.h"

/* Table for lookup to find compiled or bytecode modules included in this
 * binary or module, or put along this binary as extension modules. We do
 * our own loading for each of these.
 */
MOD_INIT_DECL( PyQt5 );
MOD_INIT_DECL( PyQt5$QtCore$$45$postLoad );
MOD_INIT_DECL( __main__ );
static struct Nuitka_MetaPathBasedLoaderEntry meta_path_loader_entries[] =
{
    { "PyQt5", MOD_INIT_NAME( PyQt5 ), 0, 0, NUITKA_PACKAGE_FLAG },
    { "PyQt5.QtCore", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.QtCore-postLoad", MOD_INIT_NAME( PyQt5$QtCore$$45$postLoad ), 0, 0, NUITKA_COMPILED_MODULE },
    { "PyQt5.QtGui", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.QtMultimedia", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.QtMultimediaWidgets", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.QtNetwork", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.QtWidgets", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "PyQt5.sip", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "__main__", MOD_INIT_NAME( __main__ ), 0, 0, NUITKA_COMPILED_MODULE },
    { "_asyncio", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_bz2", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_ctypes", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_decimal", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_elementtree", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_hashlib", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_lzma", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_msi", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_multiprocessing", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_overlapped", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_socket", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_sqlite3", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_ssl", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "_tkinter", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "pyexpat", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "select", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "unicodedata", NULL, 0, 0, NUITKA_SHLIB_FLAG },
    { "__future__", NULL, 2510, 4202, NUITKA_BYTECODE_FLAG },
    { "_bootlocale", NULL, 6712, 1015, NUITKA_BYTECODE_FLAG },
    { "_compat_pickle", NULL, 7727, 6601, NUITKA_BYTECODE_FLAG },
    { "_dummy_thread", NULL, 14328, 4886, NUITKA_BYTECODE_FLAG },
    { "_markupbase", NULL, 19214, 8026, NUITKA_BYTECODE_FLAG },
    { "_osx_support", NULL, 27240, 9741, NUITKA_BYTECODE_FLAG },
    { "_pyio", NULL, 36981, 71421, NUITKA_BYTECODE_FLAG },
    { "_sitebuiltins", NULL, 108402, 3470, NUITKA_BYTECODE_FLAG },
    { "_strptime", NULL, 111872, 15998, NUITKA_BYTECODE_FLAG },
    { "_threading_local", NULL, 127870, 6460, NUITKA_BYTECODE_FLAG },
    { "aifc", NULL, 134330, 25978, NUITKA_BYTECODE_FLAG },
    { "argparse", NULL, 160308, 60225, NUITKA_BYTECODE_FLAG },
    { "asynchat", NULL, 220533, 6850, NUITKA_BYTECODE_FLAG },
    { "asyncio", NULL, 227383, 813, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "asyncio.base_events", NULL, 228196, 39380, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_futures", NULL, 267576, 2082, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_subprocess", NULL, 269658, 9297, NUITKA_BYTECODE_FLAG },
    { "asyncio.base_tasks", NULL, 278955, 1896, NUITKA_BYTECODE_FLAG },
    { "asyncio.compat", NULL, 280851, 767, NUITKA_BYTECODE_FLAG },
    { "asyncio.constants", NULL, 281618, 286, NUITKA_BYTECODE_FLAG },
    { "asyncio.coroutines", NULL, 281904, 8587, NUITKA_BYTECODE_FLAG },
    { "asyncio.events", NULL, 290491, 25373, NUITKA_BYTECODE_FLAG },
    { "asyncio.futures", NULL, 315864, 13782, NUITKA_BYTECODE_FLAG },
    { "asyncio.locks", NULL, 329646, 15483, NUITKA_BYTECODE_FLAG },
    { "asyncio.log", NULL, 345129, 253, NUITKA_BYTECODE_FLAG },
    { "asyncio.proactor_events", NULL, 345382, 16857, NUITKA_BYTECODE_FLAG },
    { "asyncio.protocols", NULL, 362239, 6012, NUITKA_BYTECODE_FLAG },
    { "asyncio.queues", NULL, 368251, 8439, NUITKA_BYTECODE_FLAG },
    { "asyncio.selector_events", NULL, 376690, 29602, NUITKA_BYTECODE_FLAG },
    { "asyncio.sslproto", NULL, 406292, 20378, NUITKA_BYTECODE_FLAG },
    { "asyncio.streams", NULL, 426670, 19950, NUITKA_BYTECODE_FLAG },
    { "asyncio.subprocess", NULL, 446620, 6859, NUITKA_BYTECODE_FLAG },
    { "asyncio.tasks", NULL, 453479, 19128, NUITKA_BYTECODE_FLAG },
    { "asyncio.test_utils", NULL, 472607, 17716, NUITKA_BYTECODE_FLAG },
    { "asyncio.transports", NULL, 490323, 12095, NUITKA_BYTECODE_FLAG },
    { "asyncio.windows_events", NULL, 502418, 21529, NUITKA_BYTECODE_FLAG },
    { "asyncio.windows_utils", NULL, 523947, 5417, NUITKA_BYTECODE_FLAG },
    { "asyncore", NULL, 529364, 15873, NUITKA_BYTECODE_FLAG },
    { "bdb", NULL, 545237, 17068, NUITKA_BYTECODE_FLAG },
    { "binhex", NULL, 562305, 12121, NUITKA_BYTECODE_FLAG },
    { "bisect", NULL, 574426, 2711, NUITKA_BYTECODE_FLAG },
    { "cProfile", NULL, 577137, 4329, NUITKA_BYTECODE_FLAG },
    { "calendar", NULL, 581466, 25917, NUITKA_BYTECODE_FLAG },
    { "cgi", NULL, 607383, 28451, NUITKA_BYTECODE_FLAG },
    { "cgitb", NULL, 635834, 10115, NUITKA_BYTECODE_FLAG },
    { "chunk", NULL, 645949, 4935, NUITKA_BYTECODE_FLAG },
    { "cmd", NULL, 650884, 12610, NUITKA_BYTECODE_FLAG },
    { "code", NULL, 663494, 9871, NUITKA_BYTECODE_FLAG },
    { "codeop", NULL, 673365, 6305, NUITKA_BYTECODE_FLAG },
    { "colorsys", NULL, 679670, 3346, NUITKA_BYTECODE_FLAG },
    { "compileall", NULL, 683016, 8313, NUITKA_BYTECODE_FLAG },
    { "concurrent", NULL, 691329, 159, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "concurrent.futures", NULL, 691488, 675, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "concurrent.futures._base", NULL, 692163, 20667, NUITKA_BYTECODE_FLAG },
    { "concurrent.futures.process", NULL, 712830, 15864, NUITKA_BYTECODE_FLAG },
    { "concurrent.futures.thread", NULL, 728694, 3947, NUITKA_BYTECODE_FLAG },
    { "configparser", NULL, 732641, 45279, NUITKA_BYTECODE_FLAG },
    { "contextlib", NULL, 777920, 11193, NUITKA_BYTECODE_FLAG },
    { "copy", NULL, 789113, 7114, NUITKA_BYTECODE_FLAG },
    { "csv", NULL, 796227, 11890, NUITKA_BYTECODE_FLAG },
    { "ctypes", NULL, 808117, 16095, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "ctypes._endian", NULL, 824212, 1959, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib", NULL, 826171, 326, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "ctypes.macholib.dyld", NULL, 826497, 4366, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib.dylib", NULL, 830863, 1953, NUITKA_BYTECODE_FLAG },
    { "ctypes.macholib.framework", NULL, 832816, 2233, NUITKA_BYTECODE_FLAG },
    { "ctypes.util", NULL, 835049, 7261, NUITKA_BYTECODE_FLAG },
    { "ctypes.wintypes", NULL, 842310, 5130, NUITKA_BYTECODE_FLAG },
    { "datetime", NULL, 847440, 54546, NUITKA_BYTECODE_FLAG },
    { "dbm", NULL, 901986, 4204, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "dbm.dumb", NULL, 906190, 8248, NUITKA_BYTECODE_FLAG },
    { "decimal", NULL, 914438, 163437, NUITKA_BYTECODE_FLAG },
    { "difflib", NULL, 1077875, 59677, NUITKA_BYTECODE_FLAG },
    { "distutils", NULL, 1137552, 411, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "distutils._msvccompiler", NULL, 1137963, 13595, NUITKA_BYTECODE_FLAG },
    { "distutils.archive_util", NULL, 1151558, 6560, NUITKA_BYTECODE_FLAG },
    { "distutils.bcppcompiler", NULL, 1158118, 6514, NUITKA_BYTECODE_FLAG },
    { "distutils.ccompiler", NULL, 1164632, 33380, NUITKA_BYTECODE_FLAG },
    { "distutils.cmd", NULL, 1198012, 15021, NUITKA_BYTECODE_FLAG },
    { "distutils.command", NULL, 1213033, 568, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "distutils.command.bdist", NULL, 1213601, 3814, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_dumb", NULL, 1217415, 3776, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_msi", NULL, 1221191, 19800, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_rpm", NULL, 1240991, 13103, NUITKA_BYTECODE_FLAG },
    { "distutils.command.bdist_wininst", NULL, 1254094, 8363, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build", NULL, 1262457, 4098, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_clib", NULL, 1266555, 5004, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_ext", NULL, 1271559, 16591, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_py", NULL, 1288150, 10551, NUITKA_BYTECODE_FLAG },
    { "distutils.command.build_scripts", NULL, 1298701, 4367, NUITKA_BYTECODE_FLAG },
    { "distutils.command.check", NULL, 1303068, 5258, NUITKA_BYTECODE_FLAG },
    { "distutils.command.clean", NULL, 1308326, 2212, NUITKA_BYTECODE_FLAG },
    { "distutils.command.config", NULL, 1310538, 10347, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install", NULL, 1320885, 14101, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_data", NULL, 1334986, 2357, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_egg_info", NULL, 1337343, 3018, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_headers", NULL, 1340361, 1757, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_lib", NULL, 1342118, 5209, NUITKA_BYTECODE_FLAG },
    { "distutils.command.install_scripts", NULL, 1347327, 2223, NUITKA_BYTECODE_FLAG },
    { "distutils.command.register", NULL, 1349550, 8445, NUITKA_BYTECODE_FLAG },
    { "distutils.command.sdist", NULL, 1357995, 13142, NUITKA_BYTECODE_FLAG },
    { "distutils.command.upload", NULL, 1371137, 5083, NUITKA_BYTECODE_FLAG },
    { "distutils.config", NULL, 1376220, 3520, NUITKA_BYTECODE_FLAG },
    { "distutils.core", NULL, 1379740, 6836, NUITKA_BYTECODE_FLAG },
    { "distutils.cygwinccompiler", NULL, 1386576, 8541, NUITKA_BYTECODE_FLAG },
    { "distutils.debug", NULL, 1395117, 221, NUITKA_BYTECODE_FLAG },
    { "distutils.dep_util", NULL, 1395338, 2737, NUITKA_BYTECODE_FLAG },
    { "distutils.dir_util", NULL, 1398075, 5837, NUITKA_BYTECODE_FLAG },
    { "distutils.dist", NULL, 1403912, 34246, NUITKA_BYTECODE_FLAG },
    { "distutils.errors", NULL, 1438158, 5507, NUITKA_BYTECODE_FLAG },
    { "distutils.extension", NULL, 1443665, 6983, NUITKA_BYTECODE_FLAG },
    { "distutils.fancy_getopt", NULL, 1450648, 10686, NUITKA_BYTECODE_FLAG },
    { "distutils.file_util", NULL, 1461334, 5930, NUITKA_BYTECODE_FLAG },
    { "distutils.filelist", NULL, 1467264, 9898, NUITKA_BYTECODE_FLAG },
    { "distutils.log", NULL, 1477162, 2332, NUITKA_BYTECODE_FLAG },
    { "distutils.msvc9compiler", NULL, 1479494, 17477, NUITKA_BYTECODE_FLAG },
    { "distutils.msvccompiler", NULL, 1496971, 14601, NUITKA_BYTECODE_FLAG },
    { "distutils.spawn", NULL, 1511572, 5026, NUITKA_BYTECODE_FLAG },
    { "distutils.sysconfig", NULL, 1516598, 11912, NUITKA_BYTECODE_FLAG },
    { "distutils.text_file", NULL, 1528510, 8491, NUITKA_BYTECODE_FLAG },
    { "distutils.unixccompiler", NULL, 1537001, 6563, NUITKA_BYTECODE_FLAG },
    { "distutils.util", NULL, 1543564, 15556, NUITKA_BYTECODE_FLAG },
    { "distutils.version", NULL, 1559120, 7387, NUITKA_BYTECODE_FLAG },
    { "distutils.versionpredicate", NULL, 1566507, 5116, NUITKA_BYTECODE_FLAG },
    { "doctest", NULL, 1571623, 75624, NUITKA_BYTECODE_FLAG },
    { "dummy_threading", NULL, 1647247, 1137, NUITKA_BYTECODE_FLAG },
    { "email", NULL, 1648384, 1704, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "email._encoded_words", NULL, 1650088, 5619, NUITKA_BYTECODE_FLAG },
    { "email._header_value_parser", NULL, 1655707, 76029, NUITKA_BYTECODE_FLAG },
    { "email._parseaddr", NULL, 1731736, 12475, NUITKA_BYTECODE_FLAG },
    { "email._policybase", NULL, 1744211, 14863, NUITKA_BYTECODE_FLAG },
    { "email.base64mime", NULL, 1759074, 3253, NUITKA_BYTECODE_FLAG },
    { "email.charset", NULL, 1762327, 11546, NUITKA_BYTECODE_FLAG },
    { "email.contentmanager", NULL, 1773873, 7323, NUITKA_BYTECODE_FLAG },
    { "email.encoders", NULL, 1781196, 1675, NUITKA_BYTECODE_FLAG },
    { "email.errors", NULL, 1782871, 6204, NUITKA_BYTECODE_FLAG },
    { "email.feedparser", NULL, 1789075, 10679, NUITKA_BYTECODE_FLAG },
    { "email.generator", NULL, 1799754, 12548, NUITKA_BYTECODE_FLAG },
    { "email.header", NULL, 1812302, 16515, NUITKA_BYTECODE_FLAG },
    { "email.headerregistry", NULL, 1828817, 21313, NUITKA_BYTECODE_FLAG },
    { "email.iterators", NULL, 1850130, 1945, NUITKA_BYTECODE_FLAG },
    { "email.message", NULL, 1852075, 38027, NUITKA_BYTECODE_FLAG },
    { "email.mime", NULL, 1890102, 159, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "email.mime.application", NULL, 1890261, 1470, NUITKA_BYTECODE_FLAG },
    { "email.mime.audio", NULL, 1891731, 2629, NUITKA_BYTECODE_FLAG },
    { "email.mime.base", NULL, 1894360, 1095, NUITKA_BYTECODE_FLAG },
    { "email.mime.image", NULL, 1895455, 1915, NUITKA_BYTECODE_FLAG },
    { "email.mime.message", NULL, 1897370, 1344, NUITKA_BYTECODE_FLAG },
    { "email.mime.multipart", NULL, 1898714, 1566, NUITKA_BYTECODE_FLAG },
    { "email.mime.nonmultipart", NULL, 1900280, 781, NUITKA_BYTECODE_FLAG },
    { "email.mime.text", NULL, 1901061, 1328, NUITKA_BYTECODE_FLAG },
    { "email.parser", NULL, 1902389, 5760, NUITKA_BYTECODE_FLAG },
    { "email.policy", NULL, 1908149, 9653, NUITKA_BYTECODE_FLAG },
    { "email.quoprimime", NULL, 1917802, 7715, NUITKA_BYTECODE_FLAG },
    { "email.utils", NULL, 1925517, 9909, NUITKA_BYTECODE_FLAG },
    { "filecmp", NULL, 1935426, 8340, NUITKA_BYTECODE_FLAG },
    { "fileinput", NULL, 1943766, 13187, NUITKA_BYTECODE_FLAG },
    { "fnmatch", NULL, 1956953, 2909, NUITKA_BYTECODE_FLAG },
    { "formatter", NULL, 1959862, 17614, NUITKA_BYTECODE_FLAG },
    { "fractions", NULL, 1977476, 18461, NUITKA_BYTECODE_FLAG },
    { "ftplib", NULL, 1995937, 28234, NUITKA_BYTECODE_FLAG },
    { "getopt", NULL, 2024171, 6252, NUITKA_BYTECODE_FLAG },
    { "getpass", NULL, 2030423, 4212, NUITKA_BYTECODE_FLAG },
    { "gettext", NULL, 2034635, 14232, NUITKA_BYTECODE_FLAG },
    { "glob", NULL, 2048867, 4294, NUITKA_BYTECODE_FLAG },
    { "gzip", NULL, 2053161, 16261, NUITKA_BYTECODE_FLAG },
    { "hashlib", NULL, 2069422, 6727, NUITKA_BYTECODE_FLAG },
    { "hmac", NULL, 2076149, 4871, NUITKA_BYTECODE_FLAG },
    { "html", NULL, 2081020, 3412, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "html.entities", NULL, 2084432, 50482, NUITKA_BYTECODE_FLAG },
    { "html.parser", NULL, 2134914, 11199, NUITKA_BYTECODE_FLAG },
    { "http", NULL, 2146113, 6562, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "http.client", NULL, 2152675, 34381, NUITKA_BYTECODE_FLAG },
    { "http.cookiejar", NULL, 2187056, 53940, NUITKA_BYTECODE_FLAG },
    { "http.cookies", NULL, 2240996, 16187, NUITKA_BYTECODE_FLAG },
    { "http.server", NULL, 2257183, 32253, NUITKA_BYTECODE_FLAG },
    { "imaplib", NULL, 2289436, 42173, NUITKA_BYTECODE_FLAG },
    { "imghdr", NULL, 2331609, 4185, NUITKA_BYTECODE_FLAG },
    { "imp", NULL, 2335794, 9731, NUITKA_BYTECODE_FLAG },
    { "importlib.abc", NULL, 2345525, 11328, NUITKA_BYTECODE_FLAG },
    { "importlib.util", NULL, 2356853, 8935, NUITKA_BYTECODE_FLAG },
    { "ipaddress", NULL, 2365788, 62407, NUITKA_BYTECODE_FLAG },
    { "json", NULL, 2428195, 12676, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "json.decoder", NULL, 2440871, 9990, NUITKA_BYTECODE_FLAG },
    { "json.encoder", NULL, 2450861, 11292, NUITKA_BYTECODE_FLAG },
    { "json.scanner", NULL, 2462153, 2005, NUITKA_BYTECODE_FLAG },
    { "json.tool", NULL, 2464158, 1580, NUITKA_BYTECODE_FLAG },
    { "lib2to3", NULL, 2465738, 156, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.btm_matcher", NULL, 2465894, 4967, NUITKA_BYTECODE_FLAG },
    { "lib2to3.btm_utils", NULL, 2470861, 6166, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixer_base", NULL, 2477027, 6258, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixer_util", NULL, 2483285, 12071, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes", NULL, 2495356, 162, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.fixes.fix_apply", NULL, 2495518, 1710, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_asserts", NULL, 2497228, 1285, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_basestring", NULL, 2498513, 675, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_buffer", NULL, 2499188, 820, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_dict", NULL, 2500008, 3343, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_except", NULL, 2503351, 2830, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_exec", NULL, 2506181, 1161, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_execfile", NULL, 2507342, 1717, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_exitfunc", NULL, 2509059, 2308, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_filter", NULL, 2511367, 2373, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_funcattrs", NULL, 2513740, 986, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_future", NULL, 2514726, 796, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_getcwdu", NULL, 2515522, 800, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_has_key", NULL, 2516322, 2930, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_idioms", NULL, 2519252, 3915, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_import", NULL, 2523167, 2802, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_imports", NULL, 2525969, 4361, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_imports2", NULL, 2530330, 560, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_input", NULL, 2530890, 962, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_intern", NULL, 2531852, 1174, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_isinstance", NULL, 2533026, 1572, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_itertools", NULL, 2534598, 1566, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_itertools_imports", NULL, 2536164, 1621, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_long", NULL, 2537785, 717, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_map", NULL, 2538502, 3105, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_metaclass", NULL, 2541607, 5388, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_methodattrs", NULL, 2546995, 948, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_ne", NULL, 2547943, 819, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_next", NULL, 2548762, 3072, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_nonzero", NULL, 2551834, 935, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_numliterals", NULL, 2552769, 1041, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_operator", NULL, 2553810, 4249, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_paren", NULL, 2558059, 1402, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_print", NULL, 2559461, 2342, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_raise", NULL, 2561803, 2261, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_raw_input", NULL, 2564064, 807, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_reduce", NULL, 2564871, 1142, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_reload", NULL, 2566013, 1174, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_renames", NULL, 2567187, 2005, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_repr", NULL, 2569192, 857, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_set_literal", NULL, 2570049, 1699, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_standarderror", NULL, 2571748, 732, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_sys_exc", NULL, 2572480, 1413, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_throw", NULL, 2573893, 1814, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_tuple_params", NULL, 2575707, 4608, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_types", NULL, 2580315, 1841, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_unicode", NULL, 2582156, 1555, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_urllib", NULL, 2583711, 6000, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_ws_comma", NULL, 2589711, 1135, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_xrange", NULL, 2590846, 2550, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_xreadlines", NULL, 2593396, 1129, NUITKA_BYTECODE_FLAG },
    { "lib2to3.fixes.fix_zip", NULL, 2594525, 1593, NUITKA_BYTECODE_FLAG },
    { "lib2to3.main", NULL, 2596118, 8565, NUITKA_BYTECODE_FLAG },
    { "lib2to3.patcomp", NULL, 2604683, 5637, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2", NULL, 2610320, 192, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "lib2to3.pgen2.driver", NULL, 2610512, 5161, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.grammar", NULL, 2615673, 7090, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.literals", NULL, 2622763, 1567, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.parse", NULL, 2624330, 6362, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.pgen", NULL, 2630692, 9818, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.token", NULL, 2640510, 1885, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pgen2.tokenize", NULL, 2642395, 15419, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pygram", NULL, 2657814, 1211, NUITKA_BYTECODE_FLAG },
    { "lib2to3.pytree", NULL, 2659025, 25169, NUITKA_BYTECODE_FLAG },
    { "lib2to3.refactor", NULL, 2684194, 20824, NUITKA_BYTECODE_FLAG },
    { "logging", NULL, 2705018, 60430, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "logging.config", NULL, 2765448, 23423, NUITKA_BYTECODE_FLAG },
    { "logging.handlers", NULL, 2788871, 43287, NUITKA_BYTECODE_FLAG },
    { "lzma", NULL, 2832158, 12027, NUITKA_BYTECODE_FLAG },
    { "macpath", NULL, 2844185, 5676, NUITKA_BYTECODE_FLAG },
    { "macurl2path", NULL, 2849861, 1902, NUITKA_BYTECODE_FLAG },
    { "mailbox", NULL, 2851763, 63787, NUITKA_BYTECODE_FLAG },
    { "mailcap", NULL, 2915550, 6513, NUITKA_BYTECODE_FLAG },
    { "mimetypes", NULL, 2922063, 15588, NUITKA_BYTECODE_FLAG },
    { "modulefinder", NULL, 2937651, 15401, NUITKA_BYTECODE_FLAG },
    { "msilib", NULL, 2953052, 15975, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "msilib.schema", NULL, 2969027, 54234, NUITKA_BYTECODE_FLAG },
    { "msilib.sequence", NULL, 3023261, 3903, NUITKA_BYTECODE_FLAG },
    { "msilib.text", NULL, 3027164, 10047, NUITKA_BYTECODE_FLAG },
    { "multiprocessing", NULL, 3037211, 540, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "multiprocessing.connection", NULL, 3037751, 24837, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.context", NULL, 3062588, 13131, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.dummy", NULL, 3075719, 3750, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "multiprocessing.dummy.connection", NULL, 3079469, 2530, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.forkserver", NULL, 3081999, 6871, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.heap", NULL, 3088870, 6112, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.managers", NULL, 3094982, 33355, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.pool", NULL, 3128337, 20856, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.popen_spawn_win32", NULL, 3149193, 2793, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.process", NULL, 3151986, 8174, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.queues", NULL, 3160160, 8980, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.reduction", NULL, 3169140, 7992, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.resource_sharer", NULL, 3177132, 5189, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.semaphore_tracker", NULL, 3182321, 3702, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.sharedctypes", NULL, 3186023, 6909, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.spawn", NULL, 3192932, 6476, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.synchronize", NULL, 3199408, 11601, NUITKA_BYTECODE_FLAG },
    { "multiprocessing.util", NULL, 3211009, 9833, NUITKA_BYTECODE_FLAG },
    { "netrc", NULL, 3220842, 3871, NUITKA_BYTECODE_FLAG },
    { "nntplib", NULL, 3224713, 33815, NUITKA_BYTECODE_FLAG },
    { "nturl2path", NULL, 3258528, 1534, NUITKA_BYTECODE_FLAG },
    { "numbers", NULL, 3260062, 12177, NUITKA_BYTECODE_FLAG },
    { "optparse", NULL, 3272239, 48089, NUITKA_BYTECODE_FLAG },
    { "pathlib", NULL, 3320328, 42042, NUITKA_BYTECODE_FLAG },
    { "pdb", NULL, 3362370, 46129, NUITKA_BYTECODE_FLAG },
    { "pickle", NULL, 3408499, 42726, NUITKA_BYTECODE_FLAG },
    { "pickletools", NULL, 3451225, 66055, NUITKA_BYTECODE_FLAG },
    { "pipes", NULL, 3517280, 7843, NUITKA_BYTECODE_FLAG },
    { "pkgutil", NULL, 3525123, 16296, NUITKA_BYTECODE_FLAG },
    { "platform", NULL, 3541419, 28666, NUITKA_BYTECODE_FLAG },
    { "plistlib", NULL, 3570085, 27653, NUITKA_BYTECODE_FLAG },
    { "poplib", NULL, 3597738, 13364, NUITKA_BYTECODE_FLAG },
    { "posixpath", NULL, 3611102, 10458, NUITKA_BYTECODE_FLAG },
    { "pprint", NULL, 3621560, 15859, NUITKA_BYTECODE_FLAG },
    { "profile", NULL, 3637419, 13936, NUITKA_BYTECODE_FLAG },
    { "pstats", NULL, 3651355, 21892, NUITKA_BYTECODE_FLAG },
    { "py_compile", NULL, 3673247, 6579, NUITKA_BYTECODE_FLAG },
    { "pyclbr", NULL, 3679826, 8400, NUITKA_BYTECODE_FLAG },
    { "pydoc", NULL, 3688226, 84266, NUITKA_BYTECODE_FLAG },
    { "pydoc_data", NULL, 3772492, 159, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "pydoc_data.topics", NULL, 3772651, 400547, NUITKA_BYTECODE_FLAG },
    { "queue", NULL, 4173198, 8790, NUITKA_BYTECODE_FLAG },
    { "random", NULL, 4181988, 19365, NUITKA_BYTECODE_FLAG },
    { "rlcompleter", NULL, 4201353, 5815, NUITKA_BYTECODE_FLAG },
    { "runpy", NULL, 4207168, 8017, NUITKA_BYTECODE_FLAG },
    { "sched", NULL, 4215185, 6599, NUITKA_BYTECODE_FLAG },
    { "secrets", NULL, 4221784, 2197, NUITKA_BYTECODE_FLAG },
    { "selectors", NULL, 4223981, 17732, NUITKA_BYTECODE_FLAG },
    { "shelve", NULL, 4241713, 9493, NUITKA_BYTECODE_FLAG },
    { "shlex", NULL, 4251206, 7005, NUITKA_BYTECODE_FLAG },
    { "shutil", NULL, 4258211, 30739, NUITKA_BYTECODE_FLAG },
    { "signal", NULL, 4288950, 2550, NUITKA_BYTECODE_FLAG },
    { "site", NULL, 4291500, 12722, NUITKA_BYTECODE_FLAG },
    { "smtpd", NULL, 4304222, 26718, NUITKA_BYTECODE_FLAG },
    { "smtplib", NULL, 4330940, 35375, NUITKA_BYTECODE_FLAG },
    { "sndhdr", NULL, 4366315, 6948, NUITKA_BYTECODE_FLAG },
    { "socket", NULL, 4373263, 22048, NUITKA_BYTECODE_FLAG },
    { "socketserver", NULL, 4395311, 24285, NUITKA_BYTECODE_FLAG },
    { "sqlite3", NULL, 4419596, 187, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "sqlite3.dbapi2", NULL, 4419783, 2506, NUITKA_BYTECODE_FLAG },
    { "sqlite3.dump", NULL, 4422289, 1949, NUITKA_BYTECODE_FLAG },
    { "ssl", NULL, 4424238, 36537, NUITKA_BYTECODE_FLAG },
    { "statistics", NULL, 4460775, 18209, NUITKA_BYTECODE_FLAG },
    { "string", NULL, 4478984, 7999, NUITKA_BYTECODE_FLAG },
    { "subprocess", NULL, 4486983, 35520, NUITKA_BYTECODE_FLAG },
    { "sunau", NULL, 4522503, 16973, NUITKA_BYTECODE_FLAG },
    { "symbol", NULL, 4539476, 2552, NUITKA_BYTECODE_FLAG },
    { "symtable", NULL, 4542028, 10463, NUITKA_BYTECODE_FLAG },
    { "sysconfig", NULL, 4552491, 15866, NUITKA_BYTECODE_FLAG },
    { "tabnanny", NULL, 4568357, 7010, NUITKA_BYTECODE_FLAG },
    { "tarfile", NULL, 4575367, 62682, NUITKA_BYTECODE_FLAG },
    { "telnetlib", NULL, 4638049, 18132, NUITKA_BYTECODE_FLAG },
    { "tempfile", NULL, 4656181, 22262, NUITKA_BYTECODE_FLAG },
    { "test", NULL, 4678443, 153, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "test.support", NULL, 4678596, 78830, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "test.support.testresult", NULL, 4757426, 7801, NUITKA_BYTECODE_FLAG },
    { "textwrap", NULL, 4765227, 13719, NUITKA_BYTECODE_FLAG },
    { "this", NULL, 4778946, 1300, NUITKA_BYTECODE_FLAG },
    { "timeit", NULL, 4780246, 11638, NUITKA_BYTECODE_FLAG },
    { "tkinter", NULL, 4791884, 179676, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "tkinter.colorchooser", NULL, 4971560, 1152, NUITKA_BYTECODE_FLAG },
    { "tkinter.commondialog", NULL, 4972712, 1131, NUITKA_BYTECODE_FLAG },
    { "tkinter.constants", NULL, 4973843, 1681, NUITKA_BYTECODE_FLAG },
    { "tkinter.dialog", NULL, 4975524, 1476, NUITKA_BYTECODE_FLAG },
    { "tkinter.dnd", NULL, 4977000, 11199, NUITKA_BYTECODE_FLAG },
    { "tkinter.filedialog", NULL, 4988199, 12310, NUITKA_BYTECODE_FLAG },
    { "tkinter.font", NULL, 5000509, 6195, NUITKA_BYTECODE_FLAG },
    { "tkinter.messagebox", NULL, 5006704, 3065, NUITKA_BYTECODE_FLAG },
    { "tkinter.scrolledtext", NULL, 5009769, 2192, NUITKA_BYTECODE_FLAG },
    { "tkinter.simpledialog", NULL, 5011961, 10564, NUITKA_BYTECODE_FLAG },
    { "tkinter.tix", NULL, 5022525, 83688, NUITKA_BYTECODE_FLAG },
    { "tkinter.ttk", NULL, 5106213, 56978, NUITKA_BYTECODE_FLAG },
    { "trace", NULL, 5163191, 19530, NUITKA_BYTECODE_FLAG },
    { "tracemalloc", NULL, 5182721, 17264, NUITKA_BYTECODE_FLAG },
    { "turtle", NULL, 5199985, 131786, NUITKA_BYTECODE_FLAG },
    { "typing", NULL, 5331771, 73341, NUITKA_BYTECODE_FLAG },
    { "unittest", NULL, 5405112, 3024, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "unittest.case", NULL, 5408136, 47684, NUITKA_BYTECODE_FLAG },
    { "unittest.loader", NULL, 5455820, 13901, NUITKA_BYTECODE_FLAG },
    { "unittest.main", NULL, 5469721, 7047, NUITKA_BYTECODE_FLAG },
    { "unittest.mock", NULL, 5476768, 61821, NUITKA_BYTECODE_FLAG },
    { "unittest.result", NULL, 5538589, 7261, NUITKA_BYTECODE_FLAG },
    { "unittest.runner", NULL, 5545850, 6891, NUITKA_BYTECODE_FLAG },
    { "unittest.signals", NULL, 5552741, 2207, NUITKA_BYTECODE_FLAG },
    { "unittest.suite", NULL, 5554948, 9206, NUITKA_BYTECODE_FLAG },
    { "unittest.util", NULL, 5564154, 4788, NUITKA_BYTECODE_FLAG },
    { "urllib", NULL, 5568942, 155, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "urllib.error", NULL, 5569097, 2789, NUITKA_BYTECODE_FLAG },
    { "urllib.parse", NULL, 5571886, 29903, NUITKA_BYTECODE_FLAG },
    { "urllib.request", NULL, 5601789, 72650, NUITKA_BYTECODE_FLAG },
    { "urllib.response", NULL, 5674439, 3262, NUITKA_BYTECODE_FLAG },
    { "urllib.robotparser", NULL, 5677701, 7086, NUITKA_BYTECODE_FLAG },
    { "uu", NULL, 5684787, 3533, NUITKA_BYTECODE_FLAG },
    { "uuid", NULL, 5688320, 20953, NUITKA_BYTECODE_FLAG },
    { "venv", NULL, 5709273, 13671, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "wave", NULL, 5722944, 17920, NUITKA_BYTECODE_FLAG },
    { "webbrowser", NULL, 5740864, 15832, NUITKA_BYTECODE_FLAG },
    { "wsgiref", NULL, 5756696, 751, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "wsgiref.handlers", NULL, 5757447, 16183, NUITKA_BYTECODE_FLAG },
    { "wsgiref.headers", NULL, 5773630, 7772, NUITKA_BYTECODE_FLAG },
    { "wsgiref.simple_server", NULL, 5781402, 5228, NUITKA_BYTECODE_FLAG },
    { "wsgiref.util", NULL, 5786630, 5227, NUITKA_BYTECODE_FLAG },
    { "wsgiref.validate", NULL, 5791857, 14835, NUITKA_BYTECODE_FLAG },
    { "xdrlib", NULL, 5806692, 8337, NUITKA_BYTECODE_FLAG },
    { "xml", NULL, 5815029, 719, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.dom", NULL, 5815748, 5466, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.dom.NodeFilter", NULL, 5821214, 986, NUITKA_BYTECODE_FLAG },
    { "xml.dom.domreg", NULL, 5822200, 2856, NUITKA_BYTECODE_FLAG },
    { "xml.dom.expatbuilder", NULL, 5825056, 27179, NUITKA_BYTECODE_FLAG },
    { "xml.dom.minicompat", NULL, 5852235, 2824, NUITKA_BYTECODE_FLAG },
    { "xml.dom.minidom", NULL, 5855059, 55881, NUITKA_BYTECODE_FLAG },
    { "xml.dom.pulldom", NULL, 5910940, 10570, NUITKA_BYTECODE_FLAG },
    { "xml.dom.xmlbuilder", NULL, 5921510, 13586, NUITKA_BYTECODE_FLAG },
    { "xml.etree", NULL, 5935096, 158, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.etree.ElementInclude", NULL, 5935254, 1594, NUITKA_BYTECODE_FLAG },
    { "xml.etree.ElementPath", NULL, 5936848, 6170, NUITKA_BYTECODE_FLAG },
    { "xml.etree.ElementTree", NULL, 5943018, 44763, NUITKA_BYTECODE_FLAG },
    { "xml.etree.cElementTree", NULL, 5987781, 200, NUITKA_BYTECODE_FLAG },
    { "xml.parsers", NULL, 5987981, 332, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.parsers.expat", NULL, 5988313, 361, NUITKA_BYTECODE_FLAG },
    { "xml.sax", NULL, 5988674, 3195, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xml.sax._exceptions", NULL, 5991869, 5500, NUITKA_BYTECODE_FLAG },
    { "xml.sax.expatreader", NULL, 5997369, 12428, NUITKA_BYTECODE_FLAG },
    { "xml.sax.handler", NULL, 6009797, 12348, NUITKA_BYTECODE_FLAG },
    { "xml.sax.saxutils", NULL, 6022145, 12842, NUITKA_BYTECODE_FLAG },
    { "xml.sax.xmlreader", NULL, 6034987, 16957, NUITKA_BYTECODE_FLAG },
    { "xmlrpc", NULL, 6051944, 155, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { "xmlrpc.client", NULL, 6052099, 34698, NUITKA_BYTECODE_FLAG },
    { "xmlrpc.server", NULL, 6086797, 29589, NUITKA_BYTECODE_FLAG },
    { "zipapp", NULL, 6116386, 5569, NUITKA_BYTECODE_FLAG },
    { "zipfile", NULL, 6121955, 48705, NUITKA_BYTECODE_FLAG },
    { NULL, NULL, 0, 0, 0 }
};

void setupMetaPathBasedLoader( void )
{
    static bool init_done = false;

    if ( init_done == false )
    {
        registerMetaPathBasedUnfreezer( meta_path_loader_entries );
        init_done = true;
    }
}
