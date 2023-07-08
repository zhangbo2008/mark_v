/* Generated code for Python source for module 'PyQt5'
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

/* The _module_PyQt5 is a Python object pointer of module type. */

/* Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_PyQt5;
PyDictObject *moduledict_PyQt5;

/* The module constants used, if any. */
static PyObject *const_str_plain_split;
static PyObject *const_str_plain_add_dll_directory;
static PyObject *const_str_plain_environ;
static PyObject *const_str_plain_extend_path;
extern PyObject *const_str_plain_sys;
static PyObject *const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
static PyObject *const_str_plain_NUITKA_PACKAGE_PyQt5;
extern PyObject *const_str_plain___file__;
static PyObject *const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple;
extern PyObject *const_str_plain_PyQt5;
static PyObject *const_str_plain_find_qt;
static PyObject *const_str_digest_df1974ff46a1ff9194857455559dddee;
extern PyObject *const_int_0;
extern PyObject *const_str_plain_path;
static PyObject *const_str_plain_dll_dir;
static PyObject *const_str_digest_5bfaf90dbd407b4fc29090c8f6415242;
extern PyObject *const_str_plain_os;
static PyObject *const_str_digest_67a461519065c1aaea2197009f924ab7;
extern PyObject *const_str_plain___path__;
static PyObject *const_str_chr_59;
extern PyObject *const_tuple_empty;
static PyObject *const_str_plain_get;
static PyObject *const_tuple_155cab72512ae194310e44a187a6c664_tuple;
static PyObject *const_str_plain_qtcore_dll;
static PyObject *const_tuple_str_chr_59_tuple;
static PyObject *const_str_plain_isfile;
static PyObject *const_str_plain_pkgutil;
static PyObject *const_str_digest_368391e872f8da88440a18c88b4d98e1;
static PyObject *const_str_plain_PATH;
extern PyObject *const_str_plain_dirname;
static PyObject *const_str_plain_executable;
extern PyObject *const_str_plain___doc__;
extern PyObject *const_str_plain___cached__;
static PyObject *module_filename_obj;

static bool constants_created = false;

static void createModuleConstants( void )
{
    const_str_plain_split = UNSTREAM_STRING( &constant_bin[ 0 ], 5, 1 );
    const_str_plain_add_dll_directory = UNSTREAM_STRING( &constant_bin[ 5 ], 17, 1 );
    const_str_plain_environ = UNSTREAM_STRING( &constant_bin[ 22 ], 7, 1 );
    const_str_plain_extend_path = UNSTREAM_STRING( &constant_bin[ 29 ], 11, 1 );
    const_str_digest_26cc7f045e3ae69df059a1cc13576df3 = UNSTREAM_STRING( &constant_bin[ 40 ], 12, 0 );
    const_str_plain_NUITKA_PACKAGE_PyQt5 = UNSTREAM_STRING( &constant_bin[ 52 ], 20, 1 );
    const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple = PyTuple_New( 2 );
    PyTuple_SET_ITEM( const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple, 0, const_str_plain_NUITKA_PACKAGE_PyQt5 ); Py_INCREF( const_str_plain_NUITKA_PACKAGE_PyQt5 );
    const_str_digest_5bfaf90dbd407b4fc29090c8f6415242 = UNSTREAM_STRING( &constant_bin[ 72 ], 9, 0 );
    PyTuple_SET_ITEM( const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple, 1, const_str_digest_5bfaf90dbd407b4fc29090c8f6415242 ); Py_INCREF( const_str_digest_5bfaf90dbd407b4fc29090c8f6415242 );
    const_str_plain_find_qt = UNSTREAM_STRING( &constant_bin[ 81 ], 7, 1 );
    const_str_digest_df1974ff46a1ff9194857455559dddee = UNSTREAM_STRING( &constant_bin[ 88 ], 14, 0 );
    const_str_plain_dll_dir = UNSTREAM_STRING( &constant_bin[ 9 ], 7, 1 );
    const_str_digest_67a461519065c1aaea2197009f924ab7 = UNSTREAM_STRING( &constant_bin[ 102 ], 8, 0 );
    const_str_chr_59 = UNSTREAM_STRING( &constant_bin[ 110 ], 1, 0 );
    const_str_plain_get = UNSTREAM_STRING( &constant_bin[ 111 ], 3, 1 );
    const_tuple_155cab72512ae194310e44a187a6c664_tuple = PyTuple_New( 5 );
    PyTuple_SET_ITEM( const_tuple_155cab72512ae194310e44a187a6c664_tuple, 0, const_str_plain_os ); Py_INCREF( const_str_plain_os );
    PyTuple_SET_ITEM( const_tuple_155cab72512ae194310e44a187a6c664_tuple, 1, const_str_plain_sys ); Py_INCREF( const_str_plain_sys );
    const_str_plain_qtcore_dll = UNSTREAM_STRING( &constant_bin[ 114 ], 10, 1 );
    PyTuple_SET_ITEM( const_tuple_155cab72512ae194310e44a187a6c664_tuple, 2, const_str_plain_qtcore_dll ); Py_INCREF( const_str_plain_qtcore_dll );
    PyTuple_SET_ITEM( const_tuple_155cab72512ae194310e44a187a6c664_tuple, 3, const_str_plain_dll_dir ); Py_INCREF( const_str_plain_dll_dir );
    PyTuple_SET_ITEM( const_tuple_155cab72512ae194310e44a187a6c664_tuple, 4, const_str_plain_path ); Py_INCREF( const_str_plain_path );
    const_tuple_str_chr_59_tuple = PyTuple_New( 1 );
    PyTuple_SET_ITEM( const_tuple_str_chr_59_tuple, 0, const_str_chr_59 ); Py_INCREF( const_str_chr_59 );
    const_str_plain_isfile = UNSTREAM_STRING( &constant_bin[ 124 ], 6, 1 );
    const_str_plain_pkgutil = UNSTREAM_STRING( &constant_bin[ 130 ], 7, 1 );
    const_str_digest_368391e872f8da88440a18c88b4d98e1 = UNSTREAM_STRING( &constant_bin[ 137 ], 17, 0 );
    const_str_plain_PATH = UNSTREAM_STRING( &constant_bin[ 154 ], 4, 1 );
    const_str_plain_executable = UNSTREAM_STRING( &constant_bin[ 158 ], 10, 1 );

    constants_created = true;
}

#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_PyQt5( void )
{
    // The module may not have been used at all.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_fd6748feb365784677e2abac97d6061d;
static PyCodeObject *codeobj_7eb84fb2c2491434ba0b78e554038a52;

static void createModuleCodeObjects(void)
{
    module_filename_obj = MAKE_RELATIVE_PATH( const_str_digest_368391e872f8da88440a18c88b4d98e1 );
    codeobj_fd6748feb365784677e2abac97d6061d = MAKE_CODEOBJ( module_filename_obj, const_str_digest_df1974ff46a1ff9194857455559dddee, 1, const_tuple_empty, 0, 0, CO_NOFREE );
    codeobj_7eb84fb2c2491434ba0b78e554038a52 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_find_qt, 23, const_tuple_155cab72512ae194310e44a187a6c664_tuple, 0, 0, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
}

// The module function declarations.
static PyObject *MAKE_FUNCTION_PyQt5$$$function_1_find_qt(  );


// The module function definitions.
static PyObject *impl_PyQt5$$$function_1_find_qt( struct Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *var_os = NULL;
    PyObject *var_sys = NULL;
    PyObject *var_qtcore_dll = NULL;
    PyObject *var_dll_dir = NULL;
    PyObject *var_path = NULL;
    nuitka_bool tmp_for_loop_1__break_indicator = NUITKA_BOOL_UNASSIGNED;
    PyObject *tmp_for_loop_1__for_iterator = NULL;
    PyObject *tmp_for_loop_1__iter_value = NULL;
    struct Nuitka_FrameObject *frame_7eb84fb2c2491434ba0b78e554038a52;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    int tmp_res;
    bool tmp_result;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    PyObject *tmp_return_value = NULL;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    NUITKA_MAY_BE_UNUSED PyObject *tmp_unused;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;
    PyObject *exception_preserved_type_1;
    PyObject *exception_preserved_value_1;
    PyTracebackObject *exception_preserved_tb_1;
    PyObject *exception_keeper_type_5;
    PyObject *exception_keeper_value_5;
    PyTracebackObject *exception_keeper_tb_5;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_5;
    static struct Nuitka_FrameObject *cache_frame_7eb84fb2c2491434ba0b78e554038a52 = NULL;
    PyObject *exception_keeper_type_6;
    PyObject *exception_keeper_value_6;
    PyTracebackObject *exception_keeper_tb_6;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_6;

    // Actual function code.
    {
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_7eb84fb2c2491434ba0b78e554038a52, codeobj_7eb84fb2c2491434ba0b78e554038a52, module_PyQt5, sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *)+sizeof(void *) );
    frame_7eb84fb2c2491434ba0b78e554038a52 = cache_frame_7eb84fb2c2491434ba0b78e554038a52;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_7eb84fb2c2491434ba0b78e554038a52 );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    assert( Py_REFCNT( frame_7eb84fb2c2491434ba0b78e554038a52 ) == 2 ); // Frame stack

    // Framed code:
    {
    PyObject *tmp_assign_source_1;
    PyObject *tmp_name_name_1;
    PyObject *tmp_globals_name_1;
    PyObject *tmp_locals_name_1;
    PyObject *tmp_fromlist_name_1;
    PyObject *tmp_level_name_1;
    tmp_name_name_1 = const_str_plain_os;
    tmp_globals_name_1 = (PyObject *)moduledict_PyQt5;
    tmp_locals_name_1 = Py_None;
    tmp_fromlist_name_1 = Py_None;
    tmp_level_name_1 = const_int_0;
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 24;
    tmp_assign_source_1 = IMPORT_MODULE5( tmp_name_name_1, tmp_globals_name_1, tmp_locals_name_1, tmp_fromlist_name_1, tmp_level_name_1 );
    if ( tmp_assign_source_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 24;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    assert( var_os == NULL );
    var_os = tmp_assign_source_1;

    }
    {
    PyObject *tmp_assign_source_2;
    PyObject *tmp_name_name_2;
    PyObject *tmp_globals_name_2;
    PyObject *tmp_locals_name_2;
    PyObject *tmp_fromlist_name_2;
    PyObject *tmp_level_name_2;
    tmp_name_name_2 = const_str_plain_sys;
    tmp_globals_name_2 = (PyObject *)moduledict_PyQt5;
    tmp_locals_name_2 = Py_None;
    tmp_fromlist_name_2 = Py_None;
    tmp_level_name_2 = const_int_0;
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 24;
    tmp_assign_source_2 = IMPORT_MODULE5( tmp_name_name_2, tmp_globals_name_2, tmp_locals_name_2, tmp_fromlist_name_2, tmp_level_name_2 );
    assert( !(tmp_assign_source_2 == NULL) );
    assert( var_sys == NULL );
    var_sys = tmp_assign_source_2;

    }
    {
    PyObject *tmp_assign_source_3;
    tmp_assign_source_3 = const_str_digest_26cc7f045e3ae69df059a1cc13576df3;
    assert( var_qtcore_dll == NULL );
    Py_INCREF( tmp_assign_source_3 );
    var_qtcore_dll = tmp_assign_source_3;

    }
    {
    PyObject *tmp_assign_source_4;
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_source_name_2;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_source_name_3;
    CHECK_OBJECT( var_os );
    tmp_source_name_2 = var_os;
    tmp_source_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_2, const_str_plain_path );
    if ( tmp_source_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 28;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_dirname );
    Py_DECREF( tmp_source_name_1 );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 28;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    if ( var_sys == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "sys" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 28;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_3 = var_sys;
    tmp_args_element_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_3, const_str_plain_executable );
    if ( tmp_args_element_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 28;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 28;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_assign_source_4 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    Py_DECREF( tmp_args_element_name_1 );
    if ( tmp_assign_source_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 28;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    assert( var_dll_dir == NULL );
    var_dll_dir = tmp_assign_source_4;

    }
    {
    nuitka_bool tmp_condition_result_1;
    PyObject *tmp_operand_name_1;
    PyObject *tmp_called_name_2;
    PyObject *tmp_source_name_4;
    PyObject *tmp_source_name_5;
    PyObject *tmp_args_element_name_2;
    PyObject *tmp_left_name_1;
    PyObject *tmp_right_name_1;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_5 = var_os;
    tmp_source_name_4 = LOOKUP_ATTRIBUTE( tmp_source_name_5, const_str_plain_path );
    if ( tmp_source_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_called_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_4, const_str_plain_isfile );
    Py_DECREF( tmp_source_name_4 );
    if ( tmp_called_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    if ( var_dll_dir == NULL )
    {
        Py_DECREF( tmp_called_name_2 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "dll_dir" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_left_name_1 = var_dll_dir;
    if ( var_qtcore_dll == NULL )
    {
        Py_DECREF( tmp_called_name_2 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "qtcore_dll" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_right_name_1 = var_qtcore_dll;
    tmp_args_element_name_2 = BINARY_OPERATION_ADD( tmp_left_name_1, tmp_right_name_1 );
    if ( tmp_args_element_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_2 );

        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 29;
    {
        PyObject *call_args[] = { tmp_args_element_name_2 };
        tmp_operand_name_1 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_2, call_args );
    }

    Py_DECREF( tmp_called_name_2 );
    Py_DECREF( tmp_args_element_name_2 );
    if ( tmp_operand_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_res = CHECK_IF_TRUE( tmp_operand_name_1 );
    Py_DECREF( tmp_operand_name_1 );
    if ( tmp_res == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 29;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_condition_result_1 = ( tmp_res == 0 ) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    if ( tmp_condition_result_1 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_1;
    }
    else
    {
        goto branch_no_1;
    }
    branch_yes_1:;
    {
    PyObject *tmp_assign_source_5;
    PyObject *tmp_subscribed_name_1;
    PyObject *tmp_source_name_6;
    PyObject *tmp_subscript_name_1;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 30;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_6 = var_os;
    tmp_subscribed_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_6, const_str_plain_environ );
    if ( tmp_subscribed_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 30;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_subscript_name_1 = const_str_plain_PATH;
    tmp_assign_source_5 = LOOKUP_SUBSCRIPT( tmp_subscribed_name_1, tmp_subscript_name_1 );
    Py_DECREF( tmp_subscribed_name_1 );
    if ( tmp_assign_source_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 30;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    assert( var_path == NULL );
    var_path = tmp_assign_source_5;

    }
    {
    PyObject *tmp_assign_source_6;
    PyObject *tmp_left_name_2;
    PyObject *tmp_called_name_3;
    PyObject *tmp_source_name_7;
    PyObject *tmp_source_name_8;
    PyObject *tmp_args_element_name_3;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_right_name_2;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_8 = var_os;
    tmp_source_name_7 = LOOKUP_ATTRIBUTE( tmp_source_name_8, const_str_plain_path );
    if ( tmp_source_name_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_called_name_3 = LOOKUP_ATTRIBUTE( tmp_source_name_7, const_str_plain_dirname );
    Py_DECREF( tmp_source_name_7 );
    if ( tmp_called_name_3 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___file__ );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain___file__ );
    }

    if ( tmp_mvar_value_1 == NULL )
    {
        Py_DECREF( tmp_called_name_3 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "__file__" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_3 = tmp_mvar_value_1;
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 32;
    {
        PyObject *call_args[] = { tmp_args_element_name_3 };
        tmp_left_name_2 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_3, call_args );
    }

    Py_DECREF( tmp_called_name_3 );
    if ( tmp_left_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_right_name_2 = const_str_digest_67a461519065c1aaea2197009f924ab7;
    tmp_assign_source_6 = BINARY_OPERATION_ADD( tmp_left_name_2, tmp_right_name_2 );
    Py_DECREF( tmp_left_name_2 );
    if ( tmp_assign_source_6 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 32;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    {
        PyObject *old = var_dll_dir;
        var_dll_dir = tmp_assign_source_6;
        Py_XDECREF( old );
    }

    }
    {
    nuitka_bool tmp_condition_result_2;
    PyObject *tmp_called_name_4;
    PyObject *tmp_source_name_9;
    PyObject *tmp_source_name_10;
    PyObject *tmp_call_result_1;
    PyObject *tmp_args_element_name_4;
    PyObject *tmp_left_name_3;
    PyObject *tmp_right_name_3;
    int tmp_truth_name_1;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_10 = var_os;
    tmp_source_name_9 = LOOKUP_ATTRIBUTE( tmp_source_name_10, const_str_plain_path );
    if ( tmp_source_name_9 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_called_name_4 = LOOKUP_ATTRIBUTE( tmp_source_name_9, const_str_plain_isfile );
    Py_DECREF( tmp_source_name_9 );
    if ( tmp_called_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    if ( var_dll_dir == NULL )
    {
        Py_DECREF( tmp_called_name_4 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "dll_dir" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_left_name_3 = var_dll_dir;
    if ( var_qtcore_dll == NULL )
    {
        Py_DECREF( tmp_called_name_4 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "qtcore_dll" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_right_name_3 = var_qtcore_dll;
    tmp_args_element_name_4 = BINARY_OPERATION_ADD( tmp_left_name_3, tmp_right_name_3 );
    if ( tmp_args_element_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_4 );

        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 33;
    {
        PyObject *call_args[] = { tmp_args_element_name_4 };
        tmp_call_result_1 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_4, call_args );
    }

    Py_DECREF( tmp_called_name_4 );
    Py_DECREF( tmp_args_element_name_4 );
    if ( tmp_call_result_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_truth_name_1 = CHECK_IF_TRUE( tmp_call_result_1 );
    if ( tmp_truth_name_1 == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_call_result_1 );

        exception_lineno = 33;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_condition_result_2 = tmp_truth_name_1 == 1 ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    Py_DECREF( tmp_call_result_1 );
    if ( tmp_condition_result_2 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_2;
    }
    else
    {
        goto branch_no_2;
    }
    branch_yes_2:;
    {
    PyObject *tmp_assign_source_7;
    PyObject *tmp_left_name_4;
    PyObject *tmp_left_name_5;
    PyObject *tmp_right_name_4;
    PyObject *tmp_right_name_5;
    if ( var_dll_dir == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "dll_dir" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 34;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_left_name_5 = var_dll_dir;
    tmp_right_name_4 = const_str_chr_59;
    tmp_left_name_4 = BINARY_OPERATION_ADD( tmp_left_name_5, tmp_right_name_4 );
    if ( tmp_left_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 34;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    if ( var_path == NULL )
    {
        Py_DECREF( tmp_left_name_4 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "path" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 34;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_right_name_5 = var_path;
    tmp_assign_source_7 = BINARY_OPERATION_ADD( tmp_left_name_4, tmp_right_name_5 );
    Py_DECREF( tmp_left_name_4 );
    if ( tmp_assign_source_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 34;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    {
        PyObject *old = var_path;
        var_path = tmp_assign_source_7;
        Py_XDECREF( old );
    }

    }
    {
    PyObject *tmp_ass_subvalue_1;
    PyObject *tmp_ass_subscribed_1;
    PyObject *tmp_source_name_11;
    PyObject *tmp_ass_subscript_1;
    CHECK_OBJECT( var_path );
    tmp_ass_subvalue_1 = var_path;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 35;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }

    tmp_source_name_11 = var_os;
    tmp_ass_subscribed_1 = LOOKUP_ATTRIBUTE( tmp_source_name_11, const_str_plain_environ );
    if ( tmp_ass_subscribed_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 35;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    tmp_ass_subscript_1 = const_str_plain_PATH;
    tmp_result = SET_SUBSCRIPT( tmp_ass_subscribed_1, tmp_ass_subscript_1, tmp_ass_subvalue_1 );
    Py_DECREF( tmp_ass_subscribed_1 );
    if ( tmp_result == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 35;
        type_description_1 = "ooooo";
        goto frame_exception_exit_1;
    }
    }
    goto branch_end_2;
    branch_no_2:;
    {
    nuitka_bool tmp_assign_source_8;
    tmp_assign_source_8 = NUITKA_BOOL_FALSE;
    tmp_for_loop_1__break_indicator = tmp_assign_source_8;
    }
    {
    // Tried code:
    {
    PyObject *tmp_assign_source_9;
    PyObject *tmp_iter_arg_1;
    PyObject *tmp_called_instance_1;
    if ( var_path == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "path" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 37;
        type_description_1 = "ooooo";
        goto try_except_handler_2;
    }

    tmp_called_instance_1 = var_path;
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 37;
    tmp_iter_arg_1 = CALL_METHOD_WITH_ARGS1( tmp_called_instance_1, const_str_plain_split, &PyTuple_GET_ITEM( const_tuple_str_chr_59_tuple, 0 ) );

    if ( tmp_iter_arg_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 37;
        type_description_1 = "ooooo";
        goto try_except_handler_2;
    }
    tmp_assign_source_9 = MAKE_ITERATOR( tmp_iter_arg_1 );
    Py_DECREF( tmp_iter_arg_1 );
    if ( tmp_assign_source_9 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 37;
        type_description_1 = "ooooo";
        goto try_except_handler_2;
    }
    assert( tmp_for_loop_1__for_iterator == NULL );
    tmp_for_loop_1__for_iterator = tmp_assign_source_9;

    }
    {
    // Tried code:
    {
    loop_start_1:;
    {
    // Tried code:
    {
    PyObject *tmp_assign_source_10;
    PyObject *tmp_value_name_1;
    CHECK_OBJECT( tmp_for_loop_1__for_iterator );
    tmp_value_name_1 = tmp_for_loop_1__for_iterator;
    tmp_assign_source_10 = ITERATOR_NEXT( tmp_value_name_1 );
    if ( tmp_assign_source_10 == NULL )
    {
        if ( !ERROR_OCCURRED() )
        {
            exception_type = PyExc_StopIteration;
            Py_INCREF( exception_type );
            exception_value = NULL;
            exception_tb = NULL;
        }
        else
        {
            FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        }


        type_description_1 = "ooooo";
        exception_lineno = 37;
        goto try_except_handler_4;
    }
    {
        PyObject *old = tmp_for_loop_1__iter_value;
        tmp_for_loop_1__iter_value = tmp_assign_source_10;
        Py_XDECREF( old );
    }

    }
    goto try_end_1;
    // Exception handler code:
    try_except_handler_4:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    nuitka_bool tmp_condition_result_3;
    PyObject *tmp_compexpr_left_1;
    PyObject *tmp_compexpr_right_1;
    tmp_compexpr_left_1 = exception_keeper_type_1;
    tmp_compexpr_right_1 = PyExc_StopIteration;
    tmp_res = EXCEPTION_MATCH_BOOL( tmp_compexpr_left_1, tmp_compexpr_right_1 );
    if ( tmp_res == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );

        Py_DECREF( exception_keeper_type_1 );
        Py_XDECREF( exception_keeper_value_1 );
        Py_XDECREF( exception_keeper_tb_1 );

        exception_lineno = 37;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    tmp_condition_result_3 = ( tmp_res != 0 ) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    if ( tmp_condition_result_3 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_3;
    }
    else
    {
        goto branch_no_3;
    }
    branch_yes_3:;
    {
    nuitka_bool tmp_assign_source_11;
    tmp_assign_source_11 = NUITKA_BOOL_TRUE;
    tmp_for_loop_1__break_indicator = tmp_assign_source_11;
    }
    {
    Py_DECREF( exception_keeper_type_1 );
    Py_XDECREF( exception_keeper_value_1 );
    Py_XDECREF( exception_keeper_tb_1 );
    goto loop_end_1;
    }
    goto branch_end_3;
    branch_no_3:;
    {
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto try_except_handler_3;
    }
    branch_end_3:;
    }
    // End of try:
    try_end_1:;
    }
    {
    PyObject *tmp_assign_source_12;
    CHECK_OBJECT( tmp_for_loop_1__iter_value );
    tmp_assign_source_12 = tmp_for_loop_1__iter_value;
    {
        PyObject *old = var_dll_dir;
        var_dll_dir = tmp_assign_source_12;
        Py_INCREF( var_dll_dir );
        Py_XDECREF( old );
    }

    }
    {
    nuitka_bool tmp_condition_result_4;
    PyObject *tmp_called_name_5;
    PyObject *tmp_source_name_12;
    PyObject *tmp_source_name_13;
    PyObject *tmp_call_result_2;
    PyObject *tmp_args_element_name_5;
    PyObject *tmp_left_name_6;
    PyObject *tmp_right_name_6;
    int tmp_truth_name_2;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }

    tmp_source_name_13 = var_os;
    tmp_source_name_12 = LOOKUP_ATTRIBUTE( tmp_source_name_13, const_str_plain_path );
    if ( tmp_source_name_12 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    tmp_called_name_5 = LOOKUP_ATTRIBUTE( tmp_source_name_12, const_str_plain_isfile );
    Py_DECREF( tmp_source_name_12 );
    if ( tmp_called_name_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    if ( var_dll_dir == NULL )
    {
        Py_DECREF( tmp_called_name_5 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "dll_dir" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }

    tmp_left_name_6 = var_dll_dir;
    if ( var_qtcore_dll == NULL )
    {
        Py_DECREF( tmp_called_name_5 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "qtcore_dll" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }

    tmp_right_name_6 = var_qtcore_dll;
    tmp_args_element_name_5 = BINARY_OPERATION_ADD( tmp_left_name_6, tmp_right_name_6 );
    if ( tmp_args_element_name_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_5 );

        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 38;
    {
        PyObject *call_args[] = { tmp_args_element_name_5 };
        tmp_call_result_2 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_5, call_args );
    }

    Py_DECREF( tmp_called_name_5 );
    Py_DECREF( tmp_args_element_name_5 );
    if ( tmp_call_result_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    tmp_truth_name_2 = CHECK_IF_TRUE( tmp_call_result_2 );
    if ( tmp_truth_name_2 == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_call_result_2 );

        exception_lineno = 38;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    tmp_condition_result_4 = tmp_truth_name_2 == 1 ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    Py_DECREF( tmp_call_result_2 );
    if ( tmp_condition_result_4 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_4;
    }
    else
    {
        goto branch_no_4;
    }
    branch_yes_4:;
    {
    goto loop_end_1;
    }
    branch_no_4:;
    }
    if ( CONSIDER_THREADING() == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 37;
        type_description_1 = "ooooo";
        goto try_except_handler_3;
    }
    goto loop_start_1;
    loop_end_1:;
    }
    goto try_end_2;
    // Exception handler code:
    try_except_handler_3:;
    exception_keeper_type_2 = exception_type;
    exception_keeper_value_2 = exception_value;
    exception_keeper_tb_2 = exception_tb;
    exception_keeper_lineno_2 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( tmp_for_loop_1__iter_value );
    tmp_for_loop_1__iter_value = NULL;

    }
    {
    CHECK_OBJECT( (PyObject *)tmp_for_loop_1__for_iterator );
    Py_DECREF( tmp_for_loop_1__for_iterator );
    tmp_for_loop_1__for_iterator = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_2;
    exception_value = exception_keeper_value_2;
    exception_tb = exception_keeper_tb_2;
    exception_lineno = exception_keeper_lineno_2;

    goto try_except_handler_2;
    }
    // End of try:
    try_end_2:;
    }
    {
    Py_XDECREF( tmp_for_loop_1__iter_value );
    tmp_for_loop_1__iter_value = NULL;

    }
    {
    CHECK_OBJECT( (PyObject *)tmp_for_loop_1__for_iterator );
    Py_DECREF( tmp_for_loop_1__for_iterator );
    tmp_for_loop_1__for_iterator = NULL;

    }
    {
    nuitka_bool tmp_condition_result_5;
    PyObject *tmp_compexpr_left_2;
    PyObject *tmp_compexpr_right_2;
    assert( tmp_for_loop_1__break_indicator != NUITKA_BOOL_UNASSIGNED);
    tmp_compexpr_left_2 = ( tmp_for_loop_1__break_indicator == NUITKA_BOOL_TRUE ) ? Py_True : Py_False;
    tmp_compexpr_right_2 = Py_True;
    tmp_condition_result_5 = ( tmp_compexpr_left_2 == tmp_compexpr_right_2 ) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    if ( tmp_condition_result_5 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_5;
    }
    else
    {
        goto branch_no_5;
    }
    branch_yes_5:;
    {
    tmp_return_value = Py_None;
    Py_INCREF( tmp_return_value );
    goto try_return_handler_2;
    }
    branch_no_5:;
    }
    goto try_end_3;
    // Return handler code:
    try_return_handler_2:;
    {
    }
    {
    goto frame_return_exit_1;
    }
    // Exception handler code:
    try_except_handler_2:;
    exception_keeper_type_3 = exception_type;
    exception_keeper_value_3 = exception_value;
    exception_keeper_tb_3 = exception_tb;
    exception_keeper_lineno_3 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_3;
    exception_value = exception_keeper_value_3;
    exception_tb = exception_keeper_tb_3;
    exception_lineno = exception_keeper_lineno_3;

    goto frame_exception_exit_1;
    }
    // End of try:
    try_end_3:;
    }
    {
    }
    branch_end_2:;
    }
    branch_no_1:;
    }
    {
    // Tried code:
    {
    PyObject *tmp_called_name_6;
    PyObject *tmp_source_name_14;
    PyObject *tmp_args_element_name_6;
    if ( var_os == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "os" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 44;
        type_description_1 = "ooooo";
        goto try_except_handler_5;
    }

    tmp_source_name_14 = var_os;
    tmp_called_name_6 = LOOKUP_ATTRIBUTE( tmp_source_name_14, const_str_plain_add_dll_directory );
    if ( tmp_called_name_6 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 44;
        type_description_1 = "ooooo";
        goto try_except_handler_5;
    }
    if ( var_dll_dir == NULL )
    {
        Py_DECREF( tmp_called_name_6 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "local variable '%s' referenced before assignment", "dll_dir" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 44;
        type_description_1 = "ooooo";
        goto try_except_handler_5;
    }

    tmp_args_element_name_6 = var_dll_dir;
    frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = 44;
    {
        PyObject *call_args[] = { tmp_args_element_name_6 };
        tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_6, call_args );
    }

    Py_DECREF( tmp_called_name_6 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 44;
        type_description_1 = "ooooo";
        goto try_except_handler_5;
    }
    Py_DECREF( tmp_unused );
    }
    goto try_end_4;
    // Exception handler code:
    try_except_handler_5:;
    exception_keeper_type_4 = exception_type;
    exception_keeper_value_4 = exception_value;
    exception_keeper_tb_4 = exception_tb;
    exception_keeper_lineno_4 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    // Preserve existing published exception.
    exception_preserved_type_1 = EXC_TYPE(PyThreadState_GET());
    Py_XINCREF( exception_preserved_type_1 );
    exception_preserved_value_1 = EXC_VALUE(PyThreadState_GET());
    Py_XINCREF( exception_preserved_value_1 );
    exception_preserved_tb_1 = (PyTracebackObject *)EXC_TRACEBACK(PyThreadState_GET());
    Py_XINCREF( exception_preserved_tb_1 );

    }
    {
    if ( exception_keeper_tb_4 == NULL )
    {
        exception_keeper_tb_4 = MAKE_TRACEBACK( frame_7eb84fb2c2491434ba0b78e554038a52, exception_keeper_lineno_4 );
    }
    else if ( exception_keeper_lineno_4 != 0 )
    {
        exception_keeper_tb_4 = ADD_TRACEBACK( exception_keeper_tb_4, frame_7eb84fb2c2491434ba0b78e554038a52, exception_keeper_lineno_4 );
    }

    NORMALIZE_EXCEPTION( &exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4 );
    PyException_SetTraceback( exception_keeper_value_4, (PyObject *)exception_keeper_tb_4 );
    PUBLISH_EXCEPTION( &exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4 );
    }
    {
    // Tried code:
    {
    nuitka_bool tmp_condition_result_6;
    PyObject *tmp_operand_name_2;
    PyObject *tmp_compexpr_left_3;
    PyObject *tmp_compexpr_right_3;
    tmp_compexpr_left_3 = EXC_TYPE(PyThreadState_GET());
    tmp_compexpr_right_3 = PyExc_AttributeError;
    tmp_res = EXCEPTION_MATCH_BOOL( tmp_compexpr_left_3, tmp_compexpr_right_3 );
    if ( tmp_res == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 45;
        type_description_1 = "ooooo";
        goto try_except_handler_6;
    }
    tmp_operand_name_2 = ( tmp_res != 0 ) ? Py_True : Py_False;
    tmp_res = CHECK_IF_TRUE( tmp_operand_name_2 );
    if ( tmp_res == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 45;
        type_description_1 = "ooooo";
        goto try_except_handler_6;
    }
    tmp_condition_result_6 = ( tmp_res == 0 ) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
    if ( tmp_condition_result_6 == NUITKA_BOOL_TRUE )
    {
        goto branch_yes_6;
    }
    else
    {
        goto branch_no_6;
    }
    branch_yes_6:;
    {
    tmp_result = RERAISE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
    if (unlikely( tmp_result == false ))
    {
        exception_lineno = 43;
    }

    if (exception_tb && exception_tb->tb_frame == &frame_7eb84fb2c2491434ba0b78e554038a52->m_frame) frame_7eb84fb2c2491434ba0b78e554038a52->m_frame.f_lineno = exception_tb->tb_lineno;
    type_description_1 = "ooooo";
    goto try_except_handler_6;
    }
    branch_no_6:;
    }
    goto try_end_5;
    // Exception handler code:
    try_except_handler_6:;
    exception_keeper_type_5 = exception_type;
    exception_keeper_value_5 = exception_value;
    exception_keeper_tb_5 = exception_tb;
    exception_keeper_lineno_5 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    // Restore previous exception.
    SET_CURRENT_EXCEPTION( exception_preserved_type_1, exception_preserved_value_1, exception_preserved_tb_1 );
    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_5;
    exception_value = exception_keeper_value_5;
    exception_tb = exception_keeper_tb_5;
    exception_lineno = exception_keeper_lineno_5;

    goto frame_exception_exit_1;
    }
    // End of try:
    try_end_5:;
    }
    {
    // Restore previous exception.
    SET_CURRENT_EXCEPTION( exception_preserved_type_1, exception_preserved_value_1, exception_preserved_tb_1 );
    }
    goto try_end_4;
    // exception handler codes exits in all cases
    NUITKA_CANNOT_GET_HERE( PyQt5$$$function_1_find_qt );
    return NULL;
    // End of try:
    try_end_4:;
    }

#if 0
    RESTORE_FRAME_EXCEPTION( frame_7eb84fb2c2491434ba0b78e554038a52 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_1;

    frame_return_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_7eb84fb2c2491434ba0b78e554038a52 );
#endif

    // Put the previous frame back on top.
    popFrameStack();

    goto try_return_handler_1;

    frame_exception_exit_1:;

#if 0
    RESTORE_FRAME_EXCEPTION( frame_7eb84fb2c2491434ba0b78e554038a52 );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_7eb84fb2c2491434ba0b78e554038a52, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_7eb84fb2c2491434ba0b78e554038a52->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_7eb84fb2c2491434ba0b78e554038a52, exception_lineno );
    }

    // Attachs locals to frame if any.
    Nuitka_Frame_AttachLocals(
        (struct Nuitka_FrameObject *)frame_7eb84fb2c2491434ba0b78e554038a52,
        type_description_1,
        var_os,
        var_sys,
        var_qtcore_dll,
        var_dll_dir,
        var_path
    );


    // Release cached frame.
    if ( frame_7eb84fb2c2491434ba0b78e554038a52 == cache_frame_7eb84fb2c2491434ba0b78e554038a52 )
    {
        Py_DECREF( frame_7eb84fb2c2491434ba0b78e554038a52 );
    }
    cache_frame_7eb84fb2c2491434ba0b78e554038a52 = NULL;

    assertFrameObject( frame_7eb84fb2c2491434ba0b78e554038a52 );

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;
    {
    tmp_return_value = Py_None;
    Py_INCREF( tmp_return_value );
    goto try_return_handler_1;
    }
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( PyQt5$$$function_1_find_qt );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    {
    Py_XDECREF( var_os );
    var_os = NULL;

    }
    {
    Py_XDECREF( var_sys );
    var_sys = NULL;

    }
    {
    Py_XDECREF( var_qtcore_dll );
    var_qtcore_dll = NULL;

    }
    {
    Py_XDECREF( var_dll_dir );
    var_dll_dir = NULL;

    }
    {
    Py_XDECREF( var_path );
    var_path = NULL;

    }
    {
    goto function_return_exit;
    }
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_6 = exception_type;
    exception_keeper_value_6 = exception_value;
    exception_keeper_tb_6 = exception_tb;
    exception_keeper_lineno_6 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    {
    Py_XDECREF( var_os );
    var_os = NULL;

    }
    {
    Py_XDECREF( var_sys );
    var_sys = NULL;

    }
    {
    Py_XDECREF( var_qtcore_dll );
    var_qtcore_dll = NULL;

    }
    {
    Py_XDECREF( var_dll_dir );
    var_dll_dir = NULL;

    }
    {
    Py_XDECREF( var_path );
    var_path = NULL;

    }
    {
    // Re-raise.
    exception_type = exception_keeper_type_6;
    exception_value = exception_keeper_value_6;
    exception_tb = exception_keeper_tb_6;
    exception_lineno = exception_keeper_lineno_6;

    goto function_exception_exit;
    }
    // End of try:
    }

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( PyQt5$$$function_1_find_qt );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
function_return_exit:

CHECK_OBJECT( tmp_return_value );
assert( had_error || !ERROR_OCCURRED() );
return tmp_return_value;

}



static PyObject *MAKE_FUNCTION_PyQt5$$$function_1_find_qt(  )
{
    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        impl_PyQt5$$$function_1_find_qt,
        const_str_plain_find_qt,
#if PYTHON_VERSION >= 300
        NULL,
#endif
        codeobj_7eb84fb2c2491434ba0b78e554038a52,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        NULL,
#endif
        module_PyQt5,
        NULL,
        0
    );

    return (PyObject *)result;
}



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef_PyQt5 =
{
    PyModuleDef_HEAD_INIT,
    "PyQt5",   /* m_name */
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

MOD_INIT_DECL( PyQt5 )
{
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if ( _init_done )
    {
        return MOD_RETURN_VALUE( module_PyQt5 );
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
    puts("PyQt5: Calling setupMetaPathBasedLoader().");
#endif
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("PyQt5: Calling createModuleConstants().");
#endif
    createModuleConstants();

    /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
    puts("PyQt5: Calling createModuleCodeObjects().");
#endif
    createModuleCodeObjects();

    // puts( "in initPyQt5" );

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module_PyQt5 = Py_InitModule4(
        "PyQt5",       // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No "__doc__" is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else

    module_PyQt5 = PyModule_Create( &mdef_PyQt5 );
#endif

    moduledict_PyQt5 = MODULE_DICT( module_PyQt5 );

    // Update "__package__" value to what it ought to be.
    {
#if 1
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__ );

        UPDATE_STRING_DICT1(
            moduledict_PyQt5,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );

#else

#if PYTHON_VERSION < 300
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__ );
        char const *module_name_cstr = PyString_AS_STRING( module_name );

        char const *last_dot = strrchr( module_name_cstr, '.' );

        if ( last_dot != NULL )
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize( module_name_cstr, last_dot - module_name_cstr )
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__ );
        Py_ssize_t dot_index = PyUnicode_Find( module_name, const_str_dot, 0, PyUnicode_GetLength( module_name ), -1 );

        if ( dot_index != -1 )
        {
            UPDATE_STRING_DICT1(
                moduledict_PyQt5,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring( module_name, 0, dot_index )
            );
        }
#endif
#endif
    }

    CHECK_OBJECT( module_PyQt5 );

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyObject_SetItem( PySys_GetObject( (char *)"modules" ), const_str_plain_PyQt5, module_PyQt5 );

        assert( r != -1 );
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if ( GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___builtins__ ) == NULL )
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if !defined(_NUITKA_EXE) || !0
        value = PyModule_GetDict( value );
#endif

        UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___builtins__, value );
    }

#if PYTHON_VERSION >= 300
    UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___loader__, metapath_based_loader );
#endif

#if PYTHON_VERSION >= 340
#if 0
    UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__, Py_None );
#else
    {
        PyObject *bootstrap_module = PyImport_ImportModule("importlib._bootstrap");
        CHECK_OBJECT( bootstrap_module );
        PyObject *module_spec_class = PyObject_GetAttrString( bootstrap_module, "ModuleSpec" );
        Py_DECREF( bootstrap_module );

        PyObject *args[] = {
            GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___name__ ),
            metapath_based_loader
        };

        PyObject *spec_value = CALL_FUNCTION_WITH_ARGS2(
            module_spec_class,
            args
        );

        SET_ATTRIBUTE( spec_value, const_str_plain__initializing, Py_True );

        UPDATE_STRING_DICT1( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___spec__, spec_value );

        Py_DECREF( module_spec_class );
    }
#endif
#endif


    // Temp variables if any
    struct Nuitka_FrameObject *frame_fd6748feb365784677e2abac97d6061d;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    NUITKA_MAY_BE_UNUSED PyObject *tmp_unused;
    bool tmp_result;
    int tmp_res;

    // Module code.
    {
    PyObject *tmp_assign_source_1;
    tmp_assign_source_1 = Py_None;
    UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1 );
    }
    {
    PyObject *tmp_assign_source_2;
    tmp_assign_source_2 = module_filename_obj;
    UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2 );
    }
    // Frame without reuse.
    frame_fd6748feb365784677e2abac97d6061d = MAKE_MODULE_FRAME( codeobj_fd6748feb365784677e2abac97d6061d, module_PyQt5 );

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack( frame_fd6748feb365784677e2abac97d6061d );
    assert( Py_REFCNT( frame_fd6748feb365784677e2abac97d6061d ) == 2 );

    // Framed code:
    {
    PyObject *tmp_assign_source_3;
    PyObject *tmp_list_element_1;
    PyObject *tmp_called_name_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_called_instance_1;
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 1;
    {
        PyObject *module = PyImport_ImportModule("os");
        if (likely( module != NULL ))
        {
            tmp_source_name_1 = PyObject_GetAttr( module, const_str_plain_path );
        }
        else
        {
            tmp_source_name_1 = NULL;
        }
    }

    if ( tmp_source_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_dirname );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    tmp_args_element_name_1 = module_filename_obj;
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 1;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_list_element_1 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_list_element_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    tmp_assign_source_3 = PyList_New( 2 );
    PyList_SET_ITEM( tmp_assign_source_3, 0, tmp_list_element_1 );
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 1;
    {
        PyObject *module = PyImport_ImportModule("os");
        if (likely( module != NULL ))
        {
            tmp_called_instance_1 = PyObject_GetAttr( module, const_str_plain_environ );
        }
        else
        {
            tmp_called_instance_1 = NULL;
        }
    }

    if ( tmp_called_instance_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_assign_source_3 );

        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 1;
    tmp_list_element_1 = CALL_METHOD_WITH_ARGS2( tmp_called_instance_1, const_str_plain_get, &PyTuple_GET_ITEM( const_tuple_8b1fd1016da3eaee3145814dfe4be59a_tuple, 0 ) );

    if ( tmp_list_element_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_assign_source_3 );

        exception_lineno = 1;

        goto frame_exception_exit_1;
    }
    PyList_SET_ITEM( tmp_assign_source_3, 1, tmp_list_element_1 );
    UPDATE_STRING_DICT1( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___path__, tmp_assign_source_3 );
    }
    {
    PyObject *tmp_assign_source_4;
    tmp_assign_source_4 = Py_None;
    UPDATE_STRING_DICT0( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___cached__, tmp_assign_source_4 );
    }
    {
    PyObject *tmp_assign_source_5;
    PyObject *tmp_called_name_2;
    PyObject *tmp_source_name_2;
    PyObject *tmp_name_name_1;
    PyObject *tmp_args_element_name_2;
    PyObject *tmp_mvar_value_1;
    PyObject *tmp_args_element_name_3;
    tmp_name_name_1 = const_str_plain_pkgutil;
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 20;
    tmp_source_name_2 = IMPORT_MODULE1( tmp_name_name_1 );
    if ( tmp_source_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 20;

        goto frame_exception_exit_1;
    }
    tmp_called_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_2, const_str_plain_extend_path );
    Py_DECREF( tmp_source_name_2 );
    if ( tmp_called_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 20;

        goto frame_exception_exit_1;
    }
    tmp_mvar_value_1 = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___path__ );

    if (unlikely( tmp_mvar_value_1 == NULL ))
    {
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain___path__ );
    }

    if ( tmp_mvar_value_1 == NULL )
    {
        Py_DECREF( tmp_called_name_2 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "__path__" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 20;

        goto frame_exception_exit_1;
    }

    tmp_args_element_name_2 = tmp_mvar_value_1;
    tmp_args_element_name_3 = const_str_plain_PyQt5;
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 20;
    {
        PyObject *call_args[] = { tmp_args_element_name_2, tmp_args_element_name_3 };
        tmp_assign_source_5 = CALL_FUNCTION_WITH_ARGS2( tmp_called_name_2, call_args );
    }

    Py_DECREF( tmp_called_name_2 );
    if ( tmp_assign_source_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 20;

        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain___path__, tmp_assign_source_5 );
    }
    {
    PyObject *tmp_assign_source_6;
    tmp_assign_source_6 = MAKE_FUNCTION_PyQt5$$$function_1_find_qt(  );



    UPDATE_STRING_DICT1( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain_find_qt, tmp_assign_source_6 );
    }
    {
    PyObject *tmp_called_name_3;
    PyObject *tmp_mvar_value_2;
    tmp_mvar_value_2 = GET_STRING_DICT_VALUE( moduledict_PyQt5, (Nuitka_StringObject *)const_str_plain_find_qt );

    if (unlikely( tmp_mvar_value_2 == NULL ))
    {
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_find_qt );
    }

    CHECK_OBJECT( tmp_mvar_value_2 );
    tmp_called_name_3 = tmp_mvar_value_2;
    frame_fd6748feb365784677e2abac97d6061d->m_frame.f_lineno = 49;
    tmp_unused = CALL_FUNCTION_NO_ARGS( tmp_called_name_3 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 49;

        goto frame_exception_exit_1;
    }
    Py_DECREF( tmp_unused );
    }
    {
    tmp_res = PyDict_DelItem( (PyObject *)moduledict_PyQt5, const_str_plain_find_qt );
    tmp_result = tmp_res != -1;
    if ( tmp_result == false ) CLEAR_ERROR_OCCURRED();

    if ( tmp_result == false )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyUnicode_FromFormat( "name '%s' is not defined", "find_qt" );
        exception_tb = NULL;
        NORMALIZE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
        CHAIN_EXCEPTION( exception_value );

        exception_lineno = 50;

        goto frame_exception_exit_1;
    }

    }

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION( frame_fd6748feb365784677e2abac97d6061d );
#endif
    popFrameStack();

    assertFrameObject( frame_fd6748feb365784677e2abac97d6061d );

    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_fd6748feb365784677e2abac97d6061d );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_fd6748feb365784677e2abac97d6061d, exception_lineno );
    }
    else if ( exception_tb->tb_frame != &frame_fd6748feb365784677e2abac97d6061d->m_frame )
    {
        exception_tb = ADD_TRACEBACK( exception_tb, frame_fd6748feb365784677e2abac97d6061d, exception_lineno );
    }

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;

    frame_no_exception_1:;

    return MOD_RETURN_VALUE( module_PyQt5 );
    module_exception_exit:
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );
    return MOD_RETURN_VALUE( NULL );
}
