/* Generated code for Python source for module 'PyQt5.QtCore-postLoad'
 * created by Nuitka version 0.6.0
 *
 * This code is in part copyright 2018 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "__helpers.h"

/* The _module_PyQt5$QtCore$$45$postLoad is a Python object pointer of module type. */

/* Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_PyQt5$QtCore$$45$postLoad;
PyDictObject *moduledict_PyQt5$QtCore$$45$postLoad;

/* The module constants used, if any. */
extern PyObject *const_str_plain___file__;
static PyObject *const_str_digest_290c56598c73b37e7d25661969d99f1a;
static PyObject *const_str_plain_join;
static PyObject *const_str_digest_25183c642d8a288a2b3f9f4eef10be19;
extern PyObject *const_int_0;
extern PyObject *const_str_plain_os;
static PyObject *const_str_plain_setLibraryPaths;
extern PyObject *const_str_plain_path;
extern PyObject *const_str_plain_dirname;
static PyObject *const_str_digest_06d9d32adb8f056def0a1782b8baaf83;
static PyObject *const_tuple_str_plain_QCoreApplication_tuple;
extern PyObject *const_tuple_empty;
extern PyObject *const_str_plain___doc__;
extern PyObject *const_str_plain___cached__;
extern PyObject *const_str_plain_QCoreApplication;
static PyObject *const_str_digest_2b0090a9d0b3dd8bd9caeeaf842d8373;
extern PyObject *const_str_digest_98de5bc41c0485ecbec0e675e0740b32;
static PyObject *module_filename_obj;

static bool constants_created = false;

static void createModuleConstants( void )
{
    const_str_digest_290c56598c73b37e7d25661969d99f1a = UNSTREAM_STRING( &constant_bin[ 168 ], 30, 0 );
    const_str_plain_join = UNSTREAM_STRING( &constant_bin[ 198 ], 4, 1 );
    const_str_digest_25183c642d8a288a2b3f9f4eef10be19 = UNSTREAM_STRING( &constant_bin[ 176 ], 21, 0 );
    const_str_plain_setLibraryPaths = UNSTREAM_STRING( &constant_bin[ 202 ], 15, 1 );
    const_str_digest_06d9d32adb8f056def0a1782b8baaf83 = UNSTREAM_STRING( &constant_bin[ 217 ], 10, 0 );
    const_tuple_str_plain_QCoreApplication_tuple = PyTuple_New( 1 );
    PyTuple_SET_ITEM( const_tuple_str_plain_QCoreApplication_tuple, 0, const_str_plain_QCoreApplication ); Py_INCREF( const_str_plain_QCoreApplication );
    const_str_digest_2b0090a9d0b3dd8bd9caeeaf842d8373 = UNSTREAM_STRING( &constant_bin[ 227 ], 25, 0 );

    constants_created = true;
}

#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_PyQt5$QtCore$$45$postLoad( void )
{
    // The module may not have been used at all.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_f9ad5cf54f5f154859736c9c3e914580;

static void createModuleCodeObjects(void)
{
    module_filename_obj = MAKE_RELATIVE_PATH( const_str_digest_2b0090a9d0b3dd8bd9caeeaf842d8373 );
    codeobj_f9ad5cf54f5f154859736c9c3e914580 = MAKE_CODEOBJ( module_filename_obj, const_str_digest_290c56598c73b37e7d25661969d99f1a, 1, const_tuple_empty, 0, 0, CO_NOFREE );
}

// The module function declarations.


// The module function definitions.



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef_PyQt5$QtCore$$45$postLoad =
{
    PyModuleDef_HEAD_INIT,
    "PyQt5.QtCore-postLoad",   /* m_name */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#endif

extern PyObject *const_str_plain___package__;

#if PYTHON_VERSION >= 300
extern PyObject *const_str_dot;

extern PyObject *const_str_plain___loader__;
extern PyObject *metapath_based_loader;
#endif

#if PYTHON_VERSION >= 340
extern PyObject *const_str_plain___spec__;
extern PyObject *const_str_plain__initializing;
#endif

extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();
#if PYTHON_VERSION >= 350
extern void _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
extern void _initCompiledAsyncgenTypes();
#endif

// The exported interface to CPython. On import of the module, this function
// gets called. It has to have an exact function name, in cases it's a shared
// library export. This is hidden behind the MOD_INIT_DECL.

MOD_INIT_DECL( PyQt5$QtCore$$45$postLoad )
{
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if ( _init_done )
    {
        return MOD_RETURN_VALUE( module_PyQt5$QtCore$$45$postLoad );
    }
    else
    {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    /* Initialize the compiled types of Nuitka. */
    _initCompiledCellType();
    _initCompiledGeneratorType();
    _initCompiledFunctionType();
    _initCompiledMethodType();
    _initCompiledFrameType();
#if PYTHON_VERSION >= 350
    _initCompiledCoroutineTypes();
#endif
#if PYTHON_VERSION >= 360
    _initCompiledAsyncgenTypes();
#endif

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
    puts("PyQt5.QtCore-postLoad: Calling setupMetaPathBasedLoader().");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("PyQt5.QtCore-postLoad: Calling createModuleConstants().");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("PyQt5.QtCore-postLoad: Calling createModuleCodeObjects().");
#endif
    createModuleCodeObjects();

    // puts( "in initPyQt5$QtCore$$45$postLoad" );

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module_PyQt5$QtCore$$45$postLoad = Py_InitModule4(
        "PyQt5.QtCore-postLoad",       // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else

    module_PyQt5$QtCore$$45$postLoad = PyModule_Create( &mdef_PyQt5$QtCore$$45$postLoad );
#endif

    moduledict_PyQt5$QtCore$$45$postLoad = MODULE_DICT( module_PyQt5$QtCore$$45$postLoad );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___name__ );

        UPDATE_STRING_DICT1(
            moduledict_PyQt5$QtCore$$45$postLoad,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );

#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___name__ );
        char const *module_name_cstr = PyString_AS_STRING( module_name );

        char const *last_dot = strrchr( module_name_cstr, '.' );

        if ( last_dot != NULL )
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5$QtCore$$45$postLoad,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize( module_name_cstr, last_dot - module_name_cstr )
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___name__ );
        Py_ssize_t dot_index = PyUnicode_Find( module_name, const_str_dot, 0, PyUnicode_GetLength( module_name ), -1 );

        if ( dot_index != -1 )
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5$QtCore$$45$postLoad,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring( module_name, 0, dot_index )
            );
        }
#endif
#endif
    }

    CHECK_OBJECT( module_PyQt5$QtCore$$45$postLoad );

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyObject_SetItem( PySys_GetObject( (char *)"modules" ), const_str_digest_25183c642d8a288a2b3f9f4eef10be19, module_PyQt5$QtCore$$45$postLoad );

        assert( r != -1 );
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if ( GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___builtins__ ) == NULL )
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !0
        value = PyModule_GetDict( value );
#endif

        UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___builtins__, value );
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___loader__, metapath_based_loader );
#endif

#if PYTHON_VERSION >= 340
#if 0
    UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___spec__, Py_None );
#else
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT( bootstrap_module );
        PyObject *module_spec_class = PyObject_GetAttrString( bootstrap_module, "ModuleSpec" );
        Py_DECREF( bootstrap_module );

        PyObject *args[] = {
            GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___name__ ),
            metapath_based_loader
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );

        SET_ATTRIBUTE( spec_value, const_str_plain__initializing, Py_True );

        UPDATE_STRING_DICT1( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___spec__, spec_value );

        Py_DECREF( module_spec_class );
    }
#endif
#endif


    // Temp variables if any
    struct Nuitka_FrameObject *frame_f9ad5cf54f5f154859736c9c3e914580;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    NUITKA_MAY_BE_UNUSED PyObject *tmp_unused;

    // Module code.
    {
    PyObject *tmp_assign_source_1;
    tmp_assign_source_1 = Py_None;
    UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1 );
    }
    {
    PyObject *tmp_assign_source_2;
    tmp_assign_source_2 = module_filename_obj;
    UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2 );
    }
    {
    PyObject *tmp_assign_source_3;
    tmp_assign_source_3 = Py_None;
    UPDATE_STRING_DICT0( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___cached__, tmp_assign_source_3 );
    }
    // Frame without reuse.
    frame_f9ad5cf54f5f154859736c9c3e914580 = MAKE_MODULE_FRAME( codeobj_f9ad5cf54f5f154859736c9c3e914580, module_PyQt5$QtCore$$45$postLoad );

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack( frame_f9ad5cf54f5f154859736c9c3e914580 );
    assert( Py_REFCNT( frame_f9ad5cf54f5f154859736c9c3e914580 ) == 2 );

    // Framed code:
    {
    PyObject *tmp_assign_source_4;
    PyObject *tmp_import_name_from_1;
    PyObject *tmp_name_name_1;
    PyObject *tmp_globals_name_1;
    PyObject *tmp_locals_name_1;
    PyObject *tmp_fromlist_name_1;
    PyObject *tmp_level_name_1;
    tmp_name_name_1 = const_str_digest_98de5bc41c0485ecbec0e675e0740b32;
    tmp_globals_name_1 = (PyObject *)moduledict_PyQt5$QtCore$$45$postLoad;
    tmp_locals_name_1 = Py_None;
    tmp_fromlist_name_1 = const_tuple_str_plain_QCoreApplication_tuple;
    tmp_level_name_1 = const_int_0;
    frame_f9ad5cf54f5f154859736c9c3e914580->m_frame.f_lineno = 1;
    tmp_import_name_from_1 = IMPORT_MODULE5( tmp_name_name_1, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1, tmp_level_name_1 );
    if ( tmp_import_name_from_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    tmp_assign_source_4 = IMPORT_NAME( tmp_import_name_from_1, const_str_plain_QCoreApplication );
    Py_DECREF( tmp_import_name_from_1 );
    if ( tmp_assign_source_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain_QCoreApplication, tmp_assign_source_4 );
    }
    {
    PyObject *tmp_assign_source_5;
    PyObject *tmp_name_name_2;
    PyObject *tmp_globals_name_2;
    PyObject *tmp_locals_name_2;
    PyObject *tmp_fromlist_name_2;
    PyObject *tmp_level_name_2;
    tmp_name_name_2 = const_str_plain_os;
    tmp_globals_name_2 = (PyObject *)moduledict_PyQt5$QtCore$$45$postLoad;
    tmp_locals_name_2 = Py_None;
    tmp_fromlist_name_2 = Py_None;
    tmp_level_name_2 = const_int_0;
    frame_f9ad5cf54f5f154859736c9c3e914580->m_frame.f_lineno = 2;
    tmp_assign_source_5 = IMPORT_MODULE5( tmp_name_name_2, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2, tmp_level_name_2 );
    if ( tmp_assign_source_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 2;

        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain_os, tmp_assign_source_5 );
    }
    {
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_list_element_1;
    PyObject *tmp_called_name_2;
    PyObject *tmp_source_name_2;
    PyObject *tmp_source_name_3;
    PyObject *tmp_mvar_value_2;
    PyObject *tmp_args_element_name_2;
    PyObject *tmp_called_name_3;
    PyObject *tmp_source_name_4;
    PyObject *tmp_source_name_5;
    PyObject *tmp_mvar_value_3;
    PyObject *tmp_args_element_name_3;
    PyObject *tmp_mvar_value_4;
    PyObject *tmp_args_element_name_4;
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain_QCoreApplication );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_QCoreApplication );
    }

    CHECK_OBJECT( tmp_mvar_value_1 );
    tmp_source_name_1 = tmp_mvar_value_1;
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_setLibraryPaths );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 4;

        goto frame_exception_exit_1;
    }
    tmp_mvar_value_2 = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain_os );

    if (unlikely( tmp_mvar_value_2 == NULL ))
    {
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_os );
    }

    if ( tmp_mvar_value_2 == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 6;

        goto frame_exception_exit_1;
    }

    tmp_source_name_3 = tmp_mvar_value_2;
    tmp_source_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_3, const_str_plain_path );
    if ( tmp_source_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 6;

        goto frame_exception_exit_1;
    }
    tmp_called_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_2, const_str_plain_join );
    Py_DECREF( tmp_source_name_2 );
    if ( tmp_called_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 6;

        goto frame_exception_exit_1;
    }
    tmp_mvar_value_3 = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain_os );

    if (unlikely( tmp_mvar_value_3 == NULL ))
    {
        tmp_mvar_value_3 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_os );
    }

    if ( tmp_mvar_value_3 == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_called_name_2 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 7;

        goto frame_exception_exit_1;
    }

    tmp_source_name_5 = tmp_mvar_value_3;
    tmp_source_name_4 = LOOKUP_ATTRIBUTE( tmp_source_name_5, const_str_plain_path );
    if ( tmp_source_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_called_name_2 );

        exception_lineno = 7;

        goto frame_exception_exit_1;
    }
    tmp_called_name_3 = LOOKUP_ATTRIBUTE( tmp_source_name_4, const_str_plain_dirname );
    Py_DECREF( tmp_source_name_4 );
    if ( tmp_called_name_3 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_called_name_2 );

        exception_lineno = 7;

        goto frame_exception_exit_1;
    }
    tmp_mvar_value_4 = GET_STRING_DICT_VALUE( moduledict_PyQt5$QtCore$$45$postLoad, (Nuitka_StringObject *)const_str_plain___file__ );

    if (unlikely( tmp_mvar_value_4 == NULL ))
    {
        tmp_mvar_value_4 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain___file__ );
    }

    if ( tmp_mvar_value_4 == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_called_name_2 );
        Py_DECREF( tmp_called_name_3 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "__file__" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 7;

        goto frame_exception_exit_1;
    }

    tmp_args_element_name_3 = tmp_mvar_value_4;
    frame_f9ad5cf54f5f154859736c9c3e914580->m_frame.f_lineno = 7;
    {
        PyObject *call_args[] = { tmp_args_element_name_3 };
        tmp_args_element_name_2 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_3, call_args );
    }

    Py_DECREF( tmp_called_name_3 );
    if ( tmp_args_element_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_called_name_2 );

        exception_lineno = 7;

        goto frame_exception_exit_1;
    }
    tmp_args_element_name_4 = const_str_digest_06d9d32adb8f056def0a1782b8baaf83;
    frame_f9ad5cf54f5f154859736c9c3e914580->m_frame.f_lineno = 6;
    {
        PyObject *call_args[] = { tmp_args_element_name_2, tmp_args_element_name_4 };
        tmp_list_element_1 = CALL_FUNCTION_WITH_ARGS2( tmp_called_name_2, call_args );
    }

    Py_DECREF( tmp_called_name_2 );
    Py_DECREF( tmp_args_element_name_2 );
    if ( tmp_list_element_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 6;

        goto frame_exception_exit_1;
    }
    tmp_args_element_name_1 = PyList_New( 1 );
    PyList_SET_ITEM( tmp_args_element_name_1, 0, tmp_list_element_1 );
    frame_f9ad5cf54f5f154859736c9c3e914580->m_frame.f_lineno = 4;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    Py_DECREF( tmp_args_element_name_1 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 4;

        goto frame_exception_exit_1;
    }
    Py_DECREF( tmp_unused );
    }

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION( frame_f9ad5cf54f5f154859736c9c3e914580 );
#endif
    popFrameStack();

    assertFrameObject( frame_f9ad5cf54f5f154859736c9c3e914580 );

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_f9ad5cf54f5f154859736c9c3e914580 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_f9ad5cf54f5f154859736c9c3e914580, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_f9ad5cf54f5f154859736c9c3e914580->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_f9ad5cf54f5f154859736c9c3e914580, exception_lineno );
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;

    return MOD_RETURN_VALUE( module_PyQt5$QtCore$$45$postLoad );
    module_exception_exit:
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );
    return MOD_RETURN_VALUE( NULL );
}
