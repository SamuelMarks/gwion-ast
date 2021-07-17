/* A Bison parser, made by GNU Bison 3.7.2.51-de63.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2.51-de63"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         gwion_parse
#define yylex           gwion_lex
#define yyerror         gwion_error
#define yydebug         gwion_debug
#define yynerrs         gwion_nerrs

/* First part of user prologue.  */
#line 8 "src/gwion.y"

#include <math.h>
#include "gwion_util.h"
#include "gwion_ast.h"
#include "bison_compat.h"
#include "parser.h"
#include "lexer.h"

#define YYERROR_VERBOSE
#define YYMALLOC xmalloc
#define gwion_error(a,b,c) parser_error(a,b,c, 0200)
#define scan arg->scanner
#define mpool(arg) arg->st->p
#define insert_symbol(a) insert_symbol(arg->st, (a))

#define LIST_FIRST(a)  map_set(&arg->map, (m_uint)a, (m_uint)a);

#define LIST_NEXT(a, b, t, c)                      \
  a = b;                                           \
  const t next = c;                                \
  const t list = (t)map_get(&arg->map, (m_uint)a); \
  list->next = next;                               \
  map_set(&arg->map, (m_uint) a, (m_uint)next);    \

#define LIST_REM(a) map_remove(&arg->map, (m_uint)a);

ANN static int parser_error(loc_t*, Scanner*const, const char *, const uint);
ANN Symbol lambda_name(const Scanner*);
ANN Symbol sig_name(const Scanner*, const pos_t);

#line 107 "src/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* ";"  */
  YYSYMBOL_COMMA = 4,                      /* ","  */
  YYSYMBOL_LPAREN = 5,                     /* "("  */
  YYSYMBOL_RPAREN = 6,                     /* ")"  */
  YYSYMBOL_LBRACK = 7,                     /* "["  */
  YYSYMBOL_RBRACK = 8,                     /* "]"  */
  YYSYMBOL_LBRACE = 9,                     /* "{"  */
  YYSYMBOL_RBRACE = 10,                    /* "}"  */
  YYSYMBOL_FUNCTION = 11,                  /* "fun"  */
  YYSYMBOL_VAR = 12,                       /* "var"  */
  YYSYMBOL_IF = 13,                        /* "if"  */
  YYSYMBOL_ELSE = 14,                      /* "else"  */
  YYSYMBOL_WHILE = 15,                     /* "while"  */
  YYSYMBOL_DO = 16,                        /* "do"  */
  YYSYMBOL_UNTIL = 17,                     /* "until"  */
  YYSYMBOL_LOOP = 18,                      /* "repeat"  */
  YYSYMBOL_FOR = 19,                       /* "for"  */
  YYSYMBOL_FOREACH = 20,                   /* "foreach"  */
  YYSYMBOL_MATCH = 21,                     /* "match"  */
  YYSYMBOL_CASE = 22,                      /* "case"  */
  YYSYMBOL_WHEN = 23,                      /* "when"  */
  YYSYMBOL_WHERE = 24,                     /* "where"  */
  YYSYMBOL_ENUM = 25,                      /* "enum"  */
  YYSYMBOL_TRETURN = 26,                   /* "return"  */
  YYSYMBOL_BREAK = 27,                     /* "break"  */
  YYSYMBOL_CONTINUE = 28,                  /* "continue"  */
  YYSYMBOL_TRY = 29,                       /* "try"  */
  YYSYMBOL_PERFORM = 30,                   /* "perform"  */
  YYSYMBOL_HANDLET = 31,                   /* "handle"  */
  YYSYMBOL_RETRY = 32,                     /* "retry"  */
  YYSYMBOL_CLASS = 33,                     /* "class"  */
  YYSYMBOL_STRUCT = 34,                    /* "struct"  */
  YYSYMBOL_TRAIT = 35,                     /* "trait"  */
  YYSYMBOL_STATIC = 36,                    /* "static"  */
  YYSYMBOL_GLOBAL = 37,                    /* "global"  */
  YYSYMBOL_PRIVATE = 38,                   /* "private"  */
  YYSYMBOL_PROTECT = 39,                   /* "protect"  */
  YYSYMBOL_ABSTRACT = 40,                  /* "abstract"  */
  YYSYMBOL_FINAL = 41,                     /* "final"  */
  YYSYMBOL_EXTENDS = 42,                   /* "extends"  */
  YYSYMBOL_DOT = 43,                       /* "."  */
  YYSYMBOL_OPERATOR = 44,                  /* "operator"  */
  YYSYMBOL_TYPEDEF = 45,                   /* "typedef"  */
  YYSYMBOL_DISTINCT = 46,                  /* "distinct"  */
  YYSYMBOL_FUNPTR = 47,                    /* "funptr"  */
  YYSYMBOL_NOELSE = 48,                    /* NOELSE  */
  YYSYMBOL_UNION = 49,                     /* "union"  */
  YYSYMBOL_CONSTT = 50,                    /* "const"  */
  YYSYMBOL_ELLIPSE = 51,                   /* "..."  */
  YYSYMBOL_VARLOOP = 52,                   /* "varloop"  */
  YYSYMBOL_DEFER = 53,                     /* "defer"  */
  YYSYMBOL_BACKSLASH = 54,                 /* "\\"  */
  YYSYMBOL_OPID_A = 55,                    /* OPID_A  */
  YYSYMBOL_OPID_E = 56,                    /* OPID_E  */
  YYSYMBOL_LATE = 57,                      /* "late"  */
  YYSYMBOL_NUM = 58,                       /* "<integer>"  */
  YYSYMBOL_FLOATT = 59,                    /* FLOATT  */
  YYSYMBOL_STRING_LIT = 60,                /* "<litteral string>"  */
  YYSYMBOL_CHAR_LIT = 61,                  /* "<litteral char>"  */
  YYSYMBOL_INTERP_START = 62,              /* "`"  */
  YYSYMBOL_INTERP_LIT = 63,                /* "<interp string>"  */
  YYSYMBOL_INTERP_EXP = 64,                /* INTERP_EXP  */
  YYSYMBOL_INTERP_END = 65,                /* "<interp string>`"  */
  YYSYMBOL_PP_COMMENT = 66,                /* "<comment>"  */
  YYSYMBOL_PP_INCLUDE = 67,                /* "#include"  */
  YYSYMBOL_PP_DEFINE = 68,                 /* "#define"  */
  YYSYMBOL_PP_PRAGMA = 69,                 /* "#pragma"  */
  YYSYMBOL_PP_UNDEF = 70,                  /* "#undef"  */
  YYSYMBOL_PP_IFDEF = 71,                  /* "#ifdef"  */
  YYSYMBOL_PP_IFNDEF = 72,                 /* "#ifndef"  */
  YYSYMBOL_PP_ELSE = 73,                   /* "#else"  */
  YYSYMBOL_PP_ENDIF = 74,                  /* "#if"  */
  YYSYMBOL_PP_NL = 75,                     /* "\n"  */
  YYSYMBOL_PP_IMPORT = 76,                 /* "import"  */
  YYSYMBOL_77_operator_id_ = 77,           /* "@<operator id>"  */
  YYSYMBOL_78_operator_id_ = 78,           /* "&<operator id>"  */
  YYSYMBOL_ID = 79,                        /* "<identifier>"  */
  YYSYMBOL_PLUS = 80,                      /* "+"  */
  YYSYMBOL_PLUSPLUS = 81,                  /* "++"  */
  YYSYMBOL_MINUS = 82,                     /* "-"  */
  YYSYMBOL_MINUSMINUS = 83,                /* "--"  */
  YYSYMBOL_TIMES = 84,                     /* "*"  */
  YYSYMBOL_DIVIDE = 85,                    /* "/"  */
  YYSYMBOL_PERCENT = 86,                   /* "%"  */
  YYSYMBOL_DOLLAR = 87,                    /* "$"  */
  YYSYMBOL_QUESTION = 88,                  /* "?"  */
  YYSYMBOL_OPTIONS = 89,                   /* OPTIONS  */
  YYSYMBOL_COLON = 90,                     /* ":"  */
  YYSYMBOL_COLONCOLON = 91,                /* "::"  */
  YYSYMBOL_QUESTIONCOLON = 92,             /* "?:"  */
  YYSYMBOL_NEW = 93,                       /* "new"  */
  YYSYMBOL_SPORK = 94,                     /* "spork"  */
  YYSYMBOL_FORK = 95,                      /* "fork"  */
  YYSYMBOL_L_HACK = 96,                    /* "<<<"  */
  YYSYMBOL_R_HACK = 97,                    /* ">>>"  */
  YYSYMBOL_AND = 98,                       /* "&&"  */
  YYSYMBOL_EQ = 99,                        /* "=="  */
  YYSYMBOL_GE = 100,                       /* ">="  */
  YYSYMBOL_GT = 101,                       /* ">"  */
  YYSYMBOL_LE = 102,                       /* "<="  */
  YYSYMBOL_LT = 103,                       /* "<"  */
  YYSYMBOL_NEQ = 104,                      /* "!="  */
  YYSYMBOL_SHIFT_LEFT = 105,               /* "<<"  */
  YYSYMBOL_SHIFT_RIGHT = 106,              /* ">>"  */
  YYSYMBOL_S_AND = 107,                    /* "&"  */
  YYSYMBOL_S_OR = 108,                     /* "|"  */
  YYSYMBOL_S_XOR = 109,                    /* "^"  */
  YYSYMBOL_OR = 110,                       /* "||"  */
  YYSYMBOL_TMPL = 111,                     /* ":["  */
  YYSYMBOL_TILDA = 112,                    /* "~"  */
  YYSYMBOL_EXCLAMATION = 113,              /* "!"  */
  YYSYMBOL_DYNOP = 114,                    /* "<dynamic_operator>"  */
  YYSYMBOL_RANGE_EMPTY = 115,              /* RANGE_EMPTY  */
  YYSYMBOL_UMINUS = 116,                   /* UMINUS  */
  YYSYMBOL_UTIMES = 117,                   /* UTIMES  */
  YYSYMBOL_118_ = 118,                     /* "="  */
  YYSYMBOL_STMT_ASSOC = 119,               /* STMT_ASSOC  */
  YYSYMBOL_STMT_NOASSOC = 120,             /* STMT_NOASSOC  */
  YYSYMBOL_YYACCEPT = 121,                 /* $accept  */
  YYSYMBOL_prg = 122,                      /* prg  */
  YYSYMBOL_ast = 123,                      /* ast  */
  YYSYMBOL_section = 124,                  /* section  */
  YYSYMBOL_class_flag = 125,               /* class_flag  */
  YYSYMBOL_class_def = 126,                /* class_def  */
  YYSYMBOL_trait_stmt = 127,               /* trait_stmt  */
  YYSYMBOL_trait_stmt_list = 128,          /* trait_stmt_list  */
  YYSYMBOL_trait_section = 129,            /* trait_section  */
  YYSYMBOL_trait_ast = 130,                /* trait_ast  */
  YYSYMBOL_trait_body = 131,               /* trait_body  */
  YYSYMBOL_trait_def = 132,                /* trait_def  */
  YYSYMBOL_class_ext = 133,                /* class_ext  */
  YYSYMBOL_traits = 134,                   /* traits  */
  YYSYMBOL_extend_body = 135,              /* extend_body  */
  YYSYMBOL_extend_def = 136,               /* extend_def  */
  YYSYMBOL_class_body = 137,               /* class_body  */
  YYSYMBOL_id_list = 138,                  /* id_list  */
  YYSYMBOL_specialized_list = 139,         /* specialized_list  */
  YYSYMBOL_stmt_list = 140,                /* stmt_list  */
  YYSYMBOL_fptr_base = 141,                /* fptr_base  */
  YYSYMBOL__func_effects = 142,            /* _func_effects  */
  YYSYMBOL_func_effects = 143,             /* func_effects  */
  YYSYMBOL_func_base = 144,                /* func_base  */
  YYSYMBOL_fptr_def = 145,                 /* fptr_def  */
  YYSYMBOL_typedef_when = 146,             /* typedef_when  */
  YYSYMBOL_type_def_type = 147,            /* type_def_type  */
  YYSYMBOL_type_def = 148,                 /* type_def  */
  YYSYMBOL_type_decl_array = 149,          /* type_decl_array  */
  YYSYMBOL_type_decl_exp = 150,            /* type_decl_exp  */
  YYSYMBOL_type_decl_empty = 151,          /* type_decl_empty  */
  YYSYMBOL_arg = 152,                      /* arg  */
  YYSYMBOL_arg_list = 153,                 /* arg_list  */
  YYSYMBOL_fptr_arg = 154,                 /* fptr_arg  */
  YYSYMBOL_fptr_list = 155,                /* fptr_list  */
  YYSYMBOL_code_stmt = 156,                /* code_stmt  */
  YYSYMBOL_stmt_pp = 157,                  /* stmt_pp  */
  YYSYMBOL_stmt = 158,                     /* stmt  */
  YYSYMBOL_retry_stmt = 159,               /* retry_stmt  */
  YYSYMBOL_handler = 160,                  /* handler  */
  YYSYMBOL_161_1 = 161,                    /* $@1  */
  YYSYMBOL_handler_list = 162,             /* handler_list  */
  YYSYMBOL_try_stmt = 163,                 /* try_stmt  */
  YYSYMBOL_opt_id = 164,                   /* opt_id  */
  YYSYMBOL_enum_def = 165,                 /* enum_def  */
  YYSYMBOL_when_exp = 166,                 /* when_exp  */
  YYSYMBOL_match_case_stmt = 167,          /* match_case_stmt  */
  YYSYMBOL_match_list = 168,               /* match_list  */
  YYSYMBOL_where_stmt = 169,               /* where_stmt  */
  YYSYMBOL_match_stmt = 170,               /* match_stmt  */
  YYSYMBOL_flow = 171,                     /* flow  */
  YYSYMBOL_loop_stmt = 172,                /* loop_stmt  */
  YYSYMBOL_varloop_stmt = 173,             /* varloop_stmt  */
  YYSYMBOL_defer_stmt = 174,               /* defer_stmt  */
  YYSYMBOL_selection_stmt = 175,           /* selection_stmt  */
  YYSYMBOL_breaks = 176,                   /* breaks  */
  YYSYMBOL_jump_stmt = 177,                /* jump_stmt  */
  YYSYMBOL_exp_stmt = 178,                 /* exp_stmt  */
  YYSYMBOL_exp = 179,                      /* exp  */
  YYSYMBOL_binary_exp = 180,               /* binary_exp  */
  YYSYMBOL_call_template = 181,            /* call_template  */
  YYSYMBOL_op = 182,                       /* op  */
  YYSYMBOL_array_exp = 183,                /* array_exp  */
  YYSYMBOL_array_empty = 184,              /* array_empty  */
  YYSYMBOL_range = 185,                    /* range  */
  YYSYMBOL_array = 186,                    /* array  */
  YYSYMBOL_decl_exp = 187,                 /* decl_exp  */
  YYSYMBOL_func_args = 188,                /* func_args  */
  YYSYMBOL_fptr_args = 189,                /* fptr_args  */
  YYSYMBOL_arg_type = 190,                 /* arg_type  */
  YYSYMBOL_decl_template = 191,            /* decl_template  */
  YYSYMBOL_global = 192,                   /* global  */
  YYSYMBOL_storage_flag = 193,             /* storage_flag  */
  YYSYMBOL_access_flag = 194,              /* access_flag  */
  YYSYMBOL_flag = 195,                     /* flag  */
  YYSYMBOL_final = 196,                    /* final  */
  YYSYMBOL_modifier = 197,                 /* modifier  */
  YYSYMBOL_func_code = 198,                /* func_code  */
  YYSYMBOL_func_def_base = 199,            /* func_def_base  */
  YYSYMBOL_abstract_fdef = 200,            /* abstract_fdef  */
  YYSYMBOL_op_op = 201,                    /* op_op  */
  YYSYMBOL_op_base = 202,                  /* op_base  */
  YYSYMBOL_operator = 203,                 /* operator  */
  YYSYMBOL_op_def = 204,                   /* op_def  */
  YYSYMBOL_func_def = 205,                 /* func_def  */
  YYSYMBOL_type_decl_base = 206,           /* type_decl_base  */
  YYSYMBOL_type_decl_tmpl = 207,           /* type_decl_tmpl  */
  YYSYMBOL_type_decl_noflag = 208,         /* type_decl_noflag  */
  YYSYMBOL_option = 209,                   /* option  */
  YYSYMBOL_type_decl_opt = 210,            /* type_decl_opt  */
  YYSYMBOL_type_decl = 211,                /* type_decl  */
  YYSYMBOL_type_decl_flag = 212,           /* type_decl_flag  */
  YYSYMBOL_type_decl_flag2 = 213,          /* type_decl_flag2  */
  YYSYMBOL_union_decl = 214,               /* union_decl  */
  YYSYMBOL_union_list = 215,               /* union_list  */
  YYSYMBOL_union_def = 216,                /* union_def  */
  YYSYMBOL_var_decl_list = 217,            /* var_decl_list  */
  YYSYMBOL_var_decl = 218,                 /* var_decl  */
  YYSYMBOL_arg_decl = 219,                 /* arg_decl  */
  YYSYMBOL_fptr_arg_decl = 220,            /* fptr_arg_decl  */
  YYSYMBOL_eq_op = 221,                    /* eq_op  */
  YYSYMBOL_rel_op = 222,                   /* rel_op  */
  YYSYMBOL_shift_op = 223,                 /* shift_op  */
  YYSYMBOL_add_op = 224,                   /* add_op  */
  YYSYMBOL_mul_op = 225,                   /* mul_op  */
  YYSYMBOL_opt_exp = 226,                  /* opt_exp  */
  YYSYMBOL_con_exp = 227,                  /* con_exp  */
  YYSYMBOL_log_or_exp = 228,               /* log_or_exp  */
  YYSYMBOL_log_and_exp = 229,              /* log_and_exp  */
  YYSYMBOL_inc_or_exp = 230,               /* inc_or_exp  */
  YYSYMBOL_exc_or_exp = 231,               /* exc_or_exp  */
  YYSYMBOL_and_exp = 232,                  /* and_exp  */
  YYSYMBOL_eq_exp = 233,                   /* eq_exp  */
  YYSYMBOL_rel_exp = 234,                  /* rel_exp  */
  YYSYMBOL_shift_exp = 235,                /* shift_exp  */
  YYSYMBOL_add_exp = 236,                  /* add_exp  */
  YYSYMBOL_mul_exp = 237,                  /* mul_exp  */
  YYSYMBOL_dur_exp = 238,                  /* dur_exp  */
  YYSYMBOL_cast_exp = 239,                 /* cast_exp  */
  YYSYMBOL_unary_op = 240,                 /* unary_op  */
  YYSYMBOL_unary_exp = 241,                /* unary_exp  */
  YYSYMBOL_lambda_list = 242,              /* lambda_list  */
  YYSYMBOL_lambda_arg = 243,               /* lambda_arg  */
  YYSYMBOL_type_list = 244,                /* type_list  */
  YYSYMBOL_call_paren = 245,               /* call_paren  */
  YYSYMBOL_post_op = 246,                  /* post_op  */
  YYSYMBOL_dot_exp = 247,                  /* dot_exp  */
  YYSYMBOL_post_exp = 248,                 /* post_exp  */
  YYSYMBOL_interp_exp = 249,               /* interp_exp  */
  YYSYMBOL_interp = 250,                   /* interp  */
  YYSYMBOL_prim_exp = 251                  /* prim_exp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  209
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2039

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  319
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  554

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   375


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   171,   171,   172,   175,   176,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   191,   193,   200,   209,   213,
     214,   215,   218,   219,   223,   224,   227,   227,   229,   239,
     239,   240,   240,   242,   246,   252,   258,   258,   260,   261,
     263,   264,   266,   267,   269,   272,   272,   273,   273,   275,
     278,   285,   285,   286,   286,   287,   296,   296,   298,   302,
     307,   308,   310,   311,   317,   318,   318,   321,   322,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   353,   358,   358,   359,   360,   372,   374,   374,   377,
     383,   383,   386,   396,   397,   399,   399,   401,   411,   412,
     416,   418,   420,   422,   424,   426,   432,   434,   444,   446,
     449,   451,   455,   455,   457,   458,   459,   460,   464,   465,
     469,   470,   474,   475,   476,   477,   480,   480,   482,   482,
     482,   482,   485,   486,   490,   494,   495,   496,   500,   501,
     502,   505,   505,   506,   507,   509,   509,   510,   510,   511,
     511,   513,   513,   515,   517,   517,   519,   520,   523,   524,
     525,   526,   529,   529,   531,   531,   533,   533,   535,   546,
     555,   555,   555,   555,   555,   557,   561,   565,   571,   577,
     577,   579,   582,   582,   582,   583,   590,   591,   606,   607,
     611,   612,   615,   615,   615,   616,   617,   617,   620,   621,
     623,   623,   626,   630,   632,   633,   636,   646,   647,   650,
     651,   653,   654,   655,   656,   656,   658,   658,   659,   659,
     659,   659,   660,   660,   661,   661,   662,   662,   662,   664,
     664,   665,   666,   668,   671,   671,   672,   672,   673,   673,
     674,   674,   675,   675,   676,   676,   677,   677,   678,   678,
     679,   679,   680,   680,   681,   681,   683,   683,   686,   686,
     686,   687,   687,   687,   687,   690,   691,   692,   693,   696,
     697,   698,   699,   702,   703,   704,   704,   707,   708,   712,
     712,   714,   714,   716,   725,   726,   728,   730,   733,   735,
     737,   741,   742,   743,   745,   746,   758,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", ";", ",", "(", ")", "[", "]",
  "{", "}", "fun", "var", "if", "else", "while", "do", "until", "repeat",
  "for", "foreach", "match", "case", "when", "where", "enum", "return",
  "break", "continue", "try", "perform", "handle", "retry", "class",
  "struct", "trait", "static", "global", "private", "protect", "abstract",
  "final", "extends", ".", "operator", "typedef", "distinct", "funptr",
  "NOELSE", "union", "const", "...", "varloop", "defer", "\\", "OPID_A",
  "OPID_E", "late", "<integer>", "FLOATT", "<litteral string>",
  "<litteral char>", "`", "<interp string>", "INTERP_EXP",
  "<interp string>`", "<comment>", "#include", "#define", "#pragma",
  "#undef", "#ifdef", "#ifndef", "#else", "#if", "\n", "import",
  "@<operator id>", "&<operator id>", "<identifier>", "+", "++", "-", "--",
  "*", "/", "%", "$", "?", "OPTIONS", ":", "::", "?:", "new", "spork",
  "fork", "<<<", ">>>", "&&", "==", ">=", ">", "<=", "<", "!=", "<<", ">>",
  "&", "|", "^", "||", ":[", "~", "!", "<dynamic_operator>", "RANGE_EMPTY",
  "UMINUS", "UTIMES", "=", "STMT_ASSOC", "STMT_NOASSOC", "$accept", "prg",
  "ast", "section", "class_flag", "class_def", "trait_stmt",
  "trait_stmt_list", "trait_section", "trait_ast", "trait_body",
  "trait_def", "class_ext", "traits", "extend_body", "extend_def",
  "class_body", "id_list", "specialized_list", "stmt_list", "fptr_base",
  "_func_effects", "func_effects", "func_base", "fptr_def", "typedef_when",
  "type_def_type", "type_def", "type_decl_array", "type_decl_exp",
  "type_decl_empty", "arg", "arg_list", "fptr_arg", "fptr_list",
  "code_stmt", "stmt_pp", "stmt", "retry_stmt", "handler", "$@1",
  "handler_list", "try_stmt", "opt_id", "enum_def", "when_exp",
  "match_case_stmt", "match_list", "where_stmt", "match_stmt", "flow",
  "loop_stmt", "varloop_stmt", "defer_stmt", "selection_stmt", "breaks",
  "jump_stmt", "exp_stmt", "exp", "binary_exp", "call_template", "op",
  "array_exp", "array_empty", "range", "array", "decl_exp", "func_args",
  "fptr_args", "arg_type", "decl_template", "global", "storage_flag",
  "access_flag", "flag", "final", "modifier", "func_code", "func_def_base",
  "abstract_fdef", "op_op", "op_base", "operator", "op_def", "func_def",
  "type_decl_base", "type_decl_tmpl", "type_decl_noflag", "option",
  "type_decl_opt", "type_decl", "type_decl_flag", "type_decl_flag2",
  "union_decl", "union_list", "union_def", "var_decl_list", "var_decl",
  "arg_decl", "fptr_arg_decl", "eq_op", "rel_op", "shift_op", "add_op",
  "mul_op", "opt_exp", "con_exp", "log_or_exp", "log_and_exp",
  "inc_or_exp", "exc_or_exp", "and_exp", "eq_exp", "rel_exp", "shift_exp",
  "add_exp", "mul_exp", "dur_exp", "cast_exp", "unary_op", "unary_exp",
  "lambda_list", "lambda_arg", "type_list", "call_paren", "post_op",
  "dot_exp", "post_exp", "interp_exp", "interp", "prim_exp", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375
};
#endif

#define YYPACT_NINF (-390)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-237)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     510,  -390,  1218,  1279,   621,   218,  -390,    80,  -390,   834,
    -390,   109,   137,   180,  1822,   218,  1098,  -390,  -390,   834,
     131,    53,   218,   218,   218,   124,   176,  -390,  -390,   218,
     218,  -390,  1822,   834,   139,  1926,  -390,  -390,  -390,  -390,
    -390,  1340,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   124,   124,
     235,   235,  1822,  -390,  -390,   246,   510,  -390,  -390,  -390,
    -390,   834,  -390,   218,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,   244,  -390,  -390,  -390,  -390,    34,  -390,  -390,
     225,    14,  -390,   245,  -390,  -390,  -390,  -390,  -390,    27,
    -390,  -390,  -390,   218,  -390,  -390,   105,   164,   167,   157,
     171,    87,   158,   134,     6,   -21,   193,   205,  1926,  -390,
     235,  -390,  -390,   111,   231,  -390,  -390,  -390,   288,   289,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,    95,  -390,   290,  -390,  -390,  -390,  -390,  -390,
    1822,    70,  -390,   732,  -390,  -390,  -390,  -390,   292,  -390,
    -390,   228,   240,  1822,   151,  1882,  1158,   220,   108,   221,
    -390,   265,   270,  -390,  -390,   223,   242,   224,   226,   218,
    -390,    66,  -390,   208,   196,   261,   198,  -390,   299,    68,
    -390,   303,   124,   230,    43,  -390,   139,  -390,  -390,  1340,
    -390,    40,  -390,  -390,  -390,   305,  -390,  -390,    29,  -390,
    -390,  -390,   124,  1822,  -390,   310,  -390,  1822,  1822,  1822,
    1822,  1401,  -390,   292,  -390,  -390,   370,   235,   124,   124,
    1822,  1926,  1926,  1926,  1926,  1926,  1926,  -390,  -390,  1926,
    1926,  1926,  -390,  1926,  -390,  1926,  1926,   124,  -390,  -390,
    1461,   236,  -390,   124,   309,  -390,  -390,  -390,  1340,  -390,
    -390,   192,   311,  1522,  -390,   124,    44,  -390,   124,  -390,
     124,   178,  1822,   312,    35,  1158,    51,   295,  -390,   315,
    -390,  -390,  -390,   270,   209,  -390,  -390,  -390,   209,   208,
     124,   196,   247,   316,  -390,    68,  -390,  -390,  -390,  1582,
    -390,  -390,   124,    44,   248,   209,  -390,  -390,  -390,  1340,
    1822,  -390,   250,   195,  -390,    14,  -390,  -390,  -390,  -390,
     194,    44,   292,   209,   209,  -390,   209,   252,   328,   229,
    -390,   164,   167,   157,   171,    87,   158,   134,     6,   -21,
     193,   205,  -390,  -390,   329,   326,  1642,  -390,  -390,  -390,
    1702,  -390,  -390,   203,   257,  -390,   333,  -390,   332,   150,
     262,   263,   834,   285,  1822,   834,  1762,   264,  1822,  1822,
    -390,    83,   247,   221,  -390,   266,   298,   208,   335,   209,
    -390,  -390,   342,    50,  -390,   257,  -390,   344,   319,   209,
     341,  -390,   345,   209,   834,   235,   346,   349,   350,   352,
     299,  -390,   354,  1926,   124,  -390,  -390,   215,  -390,  -390,
     299,   272,   124,  -390,  -390,  -390,  -390,   209,   209,   351,
    -390,    36,  -390,   834,   219,   274,    41,    47,   336,  -390,
     173,   834,   208,   212,   124,   208,   357,   928,   303,   291,
     160,  -390,  -390,  -390,   124,   293,   294,   364,  -390,   130,
    -390,   348,  -390,  -390,  -390,   124,   124,   124,  -390,   252,
    -390,  -390,  -390,  -390,   245,  1822,  -390,   303,  -390,   834,
     834,  -390,   834,  1822,   834,  1822,   278,   834,  -390,  -390,
    -390,  -390,   297,  -390,  -390,   360,   510,  -390,  1013,  -390,
     928,   367,  -390,  -390,  -390,    44,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,   371,   301,   130,   368,  1822,   381,   382,
     384,   385,  -390,    14,    44,  -390,  -390,  -390,    42,  -390,
     328,   834,  -390,   208,   510,   510,   377,  -390,  -390,  -390,
     319,  -390,   389,  -390,  -390,    14,  -390,   124,  -390,  -390,
     391,   834,   834,  -390,   378,  -390,   390,  -390,   392,  -390,
    -390,  -390,  -390,  -390
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,   129,     0,     0,     0,   171,   210,     0,   108,     0,
     109,     0,     0,     0,     0,   171,     0,   122,   123,     0,
       0,     0,   171,   171,   171,     0,   189,    53,    54,   171,
     171,   209,     0,     0,   286,     0,   208,   307,   308,   310,
     311,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   306,   291,   268,   292,   269,     0,     0,
     272,   273,     0,   274,   271,     0,     2,     4,     8,     9,
      10,     6,    13,   171,    14,    83,    86,    42,    90,    89,
      11,    84,     0,    81,    87,    88,    82,     0,    85,    80,
       0,   130,   151,   152,   313,   312,   132,   192,   193,     0,
     194,     7,   211,   171,    12,   153,   241,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262,   264,     0,   266,
       0,   270,   300,   275,   309,   294,   319,   234,   268,   269,
     237,   238,   141,   138,   231,   229,   230,   228,   139,   232,
     233,   140,     0,   180,     0,   182,   181,   184,   183,   145,
       0,     0,    67,     0,   164,   163,   166,   167,     0,   165,
     169,   168,   173,     0,     0,     0,     0,     0,     0,    98,
     125,     0,     0,   318,    91,     0,   173,     0,     0,   171,
     196,     0,    59,    31,   137,   200,   204,   206,    57,     0,
     190,     0,     0,     0,     0,   119,   283,   285,   277,     0,
     301,     0,   304,   282,    58,   279,   280,   281,     0,     1,
       5,    43,     0,     0,   127,     0,   128,     0,     0,     0,
       0,     0,   147,     0,   272,   273,     0,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,   226,   227,     0,
       0,     0,   235,     0,   236,     0,     0,     0,   276,   316,
       0,     0,   299,     0,     0,   295,   296,   298,     0,   315,
     317,     0,   142,     0,    68,   156,     0,   170,     0,   172,
       0,     0,     0,   306,     0,     0,     0,     0,    97,     0,
     124,    92,    94,    96,   162,   174,   175,    15,   162,    31,
       0,   137,     0,     0,   198,     0,   202,   203,   205,     0,
      56,   207,   158,     0,     0,   162,   118,   284,   302,     0,
     240,   314,     0,     0,   126,   131,   133,   135,   134,   146,
       0,     0,     0,   162,   162,   191,   162,     0,   239,     0,
     243,   245,   247,   249,   251,   253,   255,   257,   259,   261,
     263,   265,   267,   293,   287,     0,     0,   297,   305,   150,
       0,   143,   149,     0,     0,    62,   155,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,    98,    95,     0,    30,    31,     0,   162,
     199,    38,    32,     0,   201,   225,    65,   157,    47,   162,
       0,   303,     0,   162,     0,     0,     0,     0,     0,     0,
     219,   154,   218,     0,     0,   136,   290,     0,   144,   148,
     221,    61,     0,   159,   177,   176,   178,   162,   162,   120,
     111,     0,   116,     0,     0,     0,     0,   101,   106,   104,
       0,     0,    31,     0,     0,    31,     0,    27,     0,     0,
       0,    33,   224,    64,     0,     0,    48,     0,    44,     0,
     278,    51,   110,   195,   188,     0,     0,     0,   220,     0,
     242,   288,   289,   223,   222,     0,    63,     0,    49,     0,
       0,   112,     0,     0,     0,     0,     0,     0,   107,    99,
      93,    40,     0,   161,    29,     0,    37,    20,    22,    24,
      26,     0,    19,    18,    23,     0,    39,    35,    34,    66,
      45,    46,    50,   196,     0,   214,     0,     0,     0,     0,
       0,     0,   217,    60,     0,   121,   117,   113,     0,   114,
     100,     0,   105,    31,    37,    36,     0,    21,    25,    28,
      47,   212,     0,   215,   216,    52,    55,     0,   186,   187,
       0,     0,   102,    41,     0,    17,     0,   213,     0,   179,
     115,    16,   197,   185
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -390,  -390,   395,   -59,   267,  -390,   -91,  -390,   -90,  -390,
    -390,  -390,  -390,  -270,  -390,  -390,  -125,    30,  -390,    -3,
    -390,  -390,  -129,  -390,  -390,  -390,  -390,  -390,   -51,   -31,
     -20,  -389,  -390,   -37,  -390,   -48,  -388,    -9,  -390,   125,
    -390,  -390,  -390,    37,  -390,  -390,    38,  -390,  -390,  -390,
     249,  -390,  -390,  -390,  -390,  -390,  -390,  -160,    13,   -29,
    -154,  -390,   -89,     2,   296,  -168,    54,  -164,  -385,  -278,
    -266,   394,   254,  -390,    16,   241,  -390,  -390,  -390,  -390,
     190,  -390,  -390,  -390,  -357,   237,  -390,   128,  -390,   238,
    -390,   -23,  -390,  -390,   -81,  -390,   -28,  -390,    45,  -390,
    -390,  -103,  -102,  -100,   -98,   118,  -213,  -390,   206,   202,
     207,   204,   201,   210,   200,   216,   199,   213,   197,   347,
      46,   251,  -390,    58,  -390,   -83,  -390,  -390,  -171,  -390,
    -390
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,   525,    67,   175,    68,   487,   488,   489,   490,
     491,    69,   435,   293,   440,    70,   526,   382,   433,    71,
     191,   446,   447,   158,    72,   508,    73,    74,   182,   205,
     344,   355,   356,   386,   387,    75,    76,    77,    78,   282,
     373,   283,    79,   279,    80,   476,   370,   371,   478,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     254,   143,    92,    93,    94,    95,    96,   266,   303,   359,
     376,   159,   160,   161,   176,   270,   287,   416,    97,    98,
     144,   227,    99,   100,   101,   184,   185,   186,   298,   187,
     188,   102,   103,   505,   506,   104,   401,   402,   411,   443,
     239,   145,   146,   147,   148,   329,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   197,   120,   345,   347,   121,   122,   123,   202,   124,
     125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     164,   153,   189,   194,   222,   183,   275,   210,   204,   240,
     172,   241,   206,   207,   243,   142,   151,   245,   330,   378,
     300,   162,   377,   466,   195,   388,   441,   168,   308,   171,
     294,   169,   179,   217,   255,   189,   189,   214,   203,   390,
     257,   365,   470,   395,   217,   192,   193,   474,   541,   492,
     357,   217,     4,   495,   201,   367,   174,   397,   398,   321,
     399,     5,   211,   244,   130,   131,   509,   510,   511,   218,
     475,   179,   249,   179,   217,   208,   189,    31,   262,   226,
     494,   198,   514,   498,    36,   163,   127,   348,   242,   212,
     218,   218,   215,   428,    26,   358,   218,   218,   218,   217,
     492,   259,   492,   219,   309,   369,   180,   436,    54,    55,
      56,    57,   217,   438,   165,   366,  -137,   277,   250,   229,
     223,   224,   225,   448,   219,   219,   311,   451,   220,   179,
     219,   219,   219,   494,   181,   179,   274,   380,   391,    63,
      64,   368,   166,   324,   211,   180,   306,   180,   548,   220,
     220,   467,   468,   414,   251,   220,   220,   220,   396,     4,
     263,   312,   481,   261,   248,   485,     8,   252,    10,   189,
     497,     5,   304,   351,    31,   181,   271,   439,   327,   325,
      31,    36,   217,   479,   362,   167,   237,    36,   315,   189,
     460,   238,    54,   230,    56,   290,   217,   231,   217,   217,
     349,   394,   262,   180,    26,   189,   189,   217,   326,   503,
     173,   409,   201,   155,   354,   232,   482,   530,   196,   217,
     483,   462,   253,   217,   189,   472,   313,   342,   216,   217,
     189,   181,   458,   240,   320,   241,   540,   181,   243,   139,
     140,   245,   189,   328,     4,   189,   209,   189,   360,   213,
     361,   385,   221,   543,   154,   155,   156,   157,   134,   135,
     136,   137,   233,   151,   154,   155,   235,   189,   280,   217,
     379,   201,   316,   317,   318,   234,   353,   493,   236,   189,
     268,   269,   285,   269,   246,   363,   296,   297,   420,   217,
     177,   178,   247,   258,  -235,  -236,   260,   265,   292,   276,
     278,   281,   284,   288,   295,   289,   299,   253,   302,   305,
     310,   415,   320,   314,   346,   343,   364,   369,   350,   403,
     375,   463,   201,   328,   372,   383,   381,   389,   493,   393,
     493,   400,   217,   404,   405,   421,   410,   412,   413,   426,
     434,   417,   418,   425,   437,   432,   439,   453,   444,   445,
     449,   450,   454,   419,   455,   456,   422,   457,   459,   407,
     477,   354,   465,   320,   473,   469,   486,   502,   521,   524,
     496,   507,   500,   501,   531,   222,   523,   529,   534,   424,
     532,   189,   427,   204,   536,   452,   537,   545,   551,   189,
     538,   539,   547,   385,   549,    66,   552,   527,   553,   544,
     528,   546,   430,   484,   354,   354,   354,   499,   374,   429,
     431,   189,   464,   272,   471,   267,   323,   286,   291,   256,
     190,   189,   480,   384,   533,   322,   189,   301,   392,   504,
     442,   512,   189,   189,   189,   332,   513,   335,   331,   334,
     337,   333,   339,   341,   518,     0,   228,   307,     0,   336,
     127,    54,   242,    56,   244,   130,   131,   338,   340,   132,
     515,   516,   461,   517,     0,   519,   210,     0,   522,   133,
     134,   135,   136,   137,   138,   139,   140,     0,   535,     0,
       0,     0,   189,     0,   141,   504,   354,     0,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   189,     2,     0,     3,   542,     4,
       0,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,   550,   211,     0,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,    25,     0,    26,    27,    28,    29,     0,    30,
      31,     0,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,    53,
       0,    54,    55,    56,    57,     0,     0,    58,     0,     0,
       0,     0,     0,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     1,     0,     2,     0,     3,     0,
       4,   152,     0,     6,     7,     0,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,     0,    16,    17,    18,
      19,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,     0,    54,    55,    56,    57,     0,     0,    58,     0,
       0,     0,     0,     0,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     1,     0,     2,     0,     3,
       0,     4,   264,     0,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,    16,    17,
      18,    19,    20,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,     0,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     3,     0,     4,    63,    64,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
      16,    17,    18,    19,    20,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,     0,    54,    55,    56,    57,     0,
       0,    58,     0,     0,     0,     0,     0,    59,    60,    61,
      62,     1,     0,     2,     0,     3,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,    31,     0,
       0,     0,    34,     0,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,     0,    54,
      55,    56,    57,     0,     0,    58,     1,     0,     2,     0,
       3,    59,    60,    61,    62,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,    34,     0,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,     0,    54,    55,    56,    57,     0,     0,
      58,   170,     0,     2,     0,     3,    59,    60,    61,    62,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,    34,     0,    35,    36,    37,    38,    39,    40,
      41,     1,     0,     2,     0,     3,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    53,     0,    54,
      55,    56,    57,     0,     0,    58,     0,     0,    20,     0,
       0,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      63,    64,    34,     0,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     2,   126,     3,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    53,     0,    54,
      55,    56,    57,     0,     0,    58,     0,     0,    20,     0,
       0,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      63,    64,    34,     0,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,     2,     0,     3,   149,     0,     0,
       0,     6,     0,     0,     0,     0,     0,    53,   127,    54,
     128,    56,   129,   130,   131,    58,     0,   132,     0,    20,
       0,    59,    60,    61,    62,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,    31,
      63,    64,   141,    34,     0,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,     2,     0,     3,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,    53,     0,
      54,    55,    56,    57,     0,     0,    58,     0,     0,   150,
      20,     0,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    63,    64,     0,    34,     0,    35,    36,    37,    38,
      39,    40,    41,   199,     0,   200,     2,     0,     3,   319,
       0,     0,     0,     6,     0,     0,     0,     0,     0,    53,
       0,    54,    55,    56,    57,     0,     0,    58,     0,     0,
       0,    20,     0,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    63,    64,     0,    34,     0,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     2,     0,     3,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
      53,     0,    54,    55,    56,    57,     0,     0,    58,     0,
       0,    20,     0,     0,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,    63,    64,    34,     0,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,     2,     0,     3,
     352,     0,     0,     0,     6,     0,     0,     0,     0,     0,
      53,     0,    54,    55,    56,    57,     0,     0,    58,     0,
       0,   150,    20,     0,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    63,    64,     0,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,     0,     3,
     149,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,   406,     3,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,     0,     3,
     408,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,   423,     3,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,     0,     3,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     2,     0,     3,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,    20,     0,     0,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    31,     3,    63,    64,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,   273,     0,    54,    55,    56,    57,     0,     0,    58,
       0,     0,     0,     0,     0,    59,    60,    61,    62,     0,
      34,     0,    35,     0,    37,    38,    39,    40,    41,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    54,    55,    56,
      57,     0,     0,    58,     0,     0,     0,     0,     0,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64
};

static const yytype_int16 yycheck[] =
{
       9,     4,    25,    32,    93,    25,   166,    66,    59,   112,
      19,   113,    60,    61,   114,     2,     3,   115,   231,   289,
     188,     5,   288,   412,    33,   303,   383,    14,   199,    16,
     184,    15,     5,     4,   123,    58,    59,     3,    58,   305,
     123,     6,     6,   321,     4,    29,    30,     6,     6,   437,
       6,     4,     9,   438,    41,     4,     3,   323,   324,   223,
     326,    11,    71,    84,    85,    86,   455,   456,   457,    55,
      23,     5,   120,     5,     4,    62,    99,    50,     8,    99,
     437,    35,   467,   440,    57,     5,    80,   258,    82,    73,
      55,    55,    58,    10,    44,    51,    55,    55,    55,     4,
     488,     6,   490,    89,    64,    22,    79,   377,    81,    82,
      83,    84,     4,   379,     5,   275,     5,     9,     7,   103,
      93,    94,    95,   389,    89,    89,    97,   393,   114,     5,
      89,    89,    89,   490,   107,     5,   165,   291,   309,   112,
     113,    90,     5,   226,   153,    79,   194,    79,   537,   114,
     114,   417,   418,     3,    43,   114,   114,   114,   322,     9,
      90,   212,   432,   150,   118,   435,    15,    56,    17,   192,
      10,    11,   192,   262,    50,   107,   163,     4,   229,   227,
      50,    57,     4,    10,     6,     5,    99,    57,   217,   212,
     403,   104,    81,    88,    83,   179,     4,    92,     4,     4,
       8,     6,     8,    79,    44,   228,   229,     4,   228,    79,
      79,     8,   199,    37,   265,   110,     4,   495,    79,     4,
       8,     6,   111,     4,   247,     6,   213,   247,     3,     4,
     253,   107,   400,   336,   221,   337,   514,   107,   338,   105,
     106,   339,   265,   230,     9,   268,     0,   270,   268,     5,
     270,   302,     7,   523,    36,    37,    38,    39,   100,   101,
     102,   103,    98,   250,    36,    37,   109,   290,     3,     4,
     290,   258,   218,   219,   220,   108,   263,   437,   107,   302,
      40,    41,    40,    41,    91,   272,    88,    89,     3,     4,
      23,    24,    87,    62,     6,     6,     6,     5,    90,    79,
      79,    31,    79,    79,    43,    79,     7,   111,     5,    79,
       5,   359,   299,     3,     5,    79,     4,    22,     7,    90,
     111,   410,   309,   310,     9,     9,    79,    79,   488,    79,
     490,    79,     4,     4,     8,   364,    79,     4,     6,   368,
      42,    79,    79,    79,     9,    79,     4,   395,     4,    30,
       9,     6,     6,   362,     5,     5,   365,     5,     4,   346,
      24,   412,    90,   350,    90,    14,     9,     3,    90,     9,
      79,    23,    79,    79,     3,   464,    79,    10,    10,   366,
      79,   404,   369,   434,     3,   394,     4,    10,    10,   412,
       6,     6,     3,   444,     3,     0,     6,   488,     6,   524,
     490,   530,   372,   434,   455,   456,   457,   444,   283,   371,
     373,   434,   410,   164,   423,   161,   226,   176,   181,   123,
      26,   444,   431,   295,   505,    55,   449,   189,   310,   449,
     385,   459,   455,   456,   457,   233,   465,   236,   232,   235,
     240,   234,   243,   246,   473,    -1,    99,   196,    -1,   239,
      80,    81,    82,    83,    84,    85,    86,   241,   245,    89,
     469,   470,   404,   472,    -1,   474,   525,    -1,   477,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,   507,    -1,
      -1,    -1,   505,    -1,   114,   505,   537,    -1,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   537,     5,    -1,     7,   521,     9,
      -1,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,   541,   542,    -1,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    -1,    49,
      50,    -1,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,     3,    -1,     5,    -1,     7,    -1,
       9,    10,    -1,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,     3,    -1,     5,    -1,     7,
      -1,     9,    10,    -1,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,     7,    -1,     9,   112,   113,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,     3,    -1,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    87,     3,    -1,     5,    -1,
       7,    93,    94,    95,    96,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      87,     3,    -1,     5,    -1,     7,    93,    94,    95,    96,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,     3,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    87,    -1,    -1,    30,    -1,
      -1,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
     112,   113,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    87,    -1,    -1,    30,    -1,
      -1,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
     112,   113,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,     5,    -1,     7,     8,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    30,
      -1,    93,    94,    95,    96,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    50,
     112,   113,   114,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,     5,    -1,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    87,    -1,    -1,    90,
      30,    -1,    93,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,   112,   113,    -1,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,     5,    -1,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    87,    -1,    -1,
      -1,    30,    -1,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,   112,   113,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,     5,    -1,     7,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    87,    -1,
      -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,   112,   113,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,     5,    -1,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    87,    -1,
      -1,    90,    30,    -1,    93,    94,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,   112,   113,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,    -1,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,    -1,     7,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,    -1,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,     5,    -1,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    30,    -1,    -1,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    50,     7,   112,   113,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,     9,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    21,    25,    26,    27,    28,    29,
      30,    32,    33,    34,    35,    42,    44,    45,    46,    47,
      49,    50,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    79,    81,    82,    83,    84,    87,    93,
      94,    95,    96,   112,   113,   122,   123,   124,   126,   132,
     136,   140,   145,   147,   148,   156,   157,   158,   159,   163,
     165,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   183,   184,   185,   186,   187,   199,   200,   203,
     204,   205,   212,   213,   216,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     243,   246,   247,   248,   250,   251,     6,    80,    82,    84,
      85,    86,    89,    99,   100,   101,   102,   103,   104,   105,
     106,   114,   179,   182,   201,   222,   223,   224,   225,     8,
      90,   179,    10,   140,    36,    37,    38,    39,   144,   192,
     193,   194,   195,     5,   158,     5,     5,     5,   179,   195,
       3,   179,   158,    79,     3,   125,   195,   125,   125,     5,
      79,   107,   149,   151,   206,   207,   208,   210,   211,   212,
     192,   141,   195,   195,   180,   158,    79,   242,   241,    63,
      65,   179,   249,   151,   149,   150,   156,   156,   179,     0,
     124,   158,   195,     5,     3,    58,     3,     4,    55,    89,
     114,     7,   183,    93,    94,    95,   151,   202,   240,   195,
      88,    92,   110,    98,   108,   109,   107,    99,   104,   221,
     222,   223,    82,   224,    84,   225,    91,    87,   241,   156,
       7,    43,    56,   111,   181,   183,   185,   246,    62,     6,
       6,   179,     8,    90,    10,     5,   188,   193,    40,    41,
     196,   179,   171,    79,   180,   178,    79,     9,    79,   164,
       3,    31,   160,   162,    79,    40,   196,   197,    79,    79,
     195,   206,    90,   134,   181,    43,    88,    89,   209,     7,
     186,   210,     5,   189,   151,    79,   156,   242,   249,    64,
       5,    97,   149,   179,     3,   180,   187,   187,   187,     8,
     179,   188,    55,   201,   246,   156,   151,   149,   179,   226,
     227,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   151,    79,   151,   244,     5,   245,   249,     8,
       7,   183,     8,   179,   149,   152,   153,     6,    51,   190,
     151,   151,     6,   179,     4,     6,   178,     4,    90,    22,
     167,   168,     9,   161,   160,   111,   191,   191,   134,   151,
     181,    79,   138,     9,   208,   149,   154,   155,   190,    79,
     191,   249,   226,    79,     6,   190,   188,   191,   191,   191,
      79,   217,   218,    90,     4,     8,     6,   179,     8,     8,
      79,   219,     4,     6,     3,   156,   198,    79,    79,   158,
       3,   180,   158,     6,   179,    79,   180,   179,    10,   167,
     138,   164,    79,   139,    42,   133,   134,     9,   191,     4,
     135,   205,   219,   220,     4,    30,   142,   143,   191,     9,
       6,   191,   158,   156,     6,     5,     5,     5,   186,     4,
     227,   244,     6,   183,   184,    90,   152,   191,   191,    14,
       6,   158,     6,    90,     6,    23,   166,    24,   169,    10,
     158,   134,     4,     8,   150,   134,     9,   127,   128,   129,
     130,   131,   157,   178,   205,   189,    79,    10,   205,   154,
      79,    79,     3,    79,   151,   214,   215,    23,   146,   152,
     152,   152,   217,   180,   189,   158,   158,   158,   180,   158,
     179,    90,   158,    79,     9,   123,   137,   127,   129,    10,
     190,     3,    79,   215,    10,   180,     3,     4,     6,     6,
     190,     6,   140,   134,   137,    10,   143,     3,   152,     3,
     158,    10,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   133,
     133,   134,   134,   135,   135,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   142,   142,   143,   143,   144,
     145,   146,   146,   147,   147,   148,   149,   149,   150,   151,
     152,   152,   153,   153,   154,   155,   155,   156,   156,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   161,   160,   162,   162,   163,   164,   164,   165,
     166,   166,   167,   168,   168,   169,   169,   170,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   172,   173,   174,
     175,   175,   176,   176,   177,   177,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   180,   181,   181,   182,   182,
     182,   182,   183,   183,   183,   184,   184,   184,   185,   185,
     185,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   193,   193,   194,   194,   195,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   199,   200,
     201,   201,   201,   201,   201,   202,   202,   202,   202,   203,
     203,   204,   205,   205,   205,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   209,   210,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   217,   217,   218,
     218,   219,   219,   219,   220,   220,   221,   221,   222,   222,
     222,   222,   223,   223,   224,   224,   225,   225,   225,   226,
     226,   227,   227,   227,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   232,   233,   233,   234,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   241,   241,   241,
     241,   241,   241,   242,   242,   243,   243,   244,   244,   245,
     245,   246,   246,   247,   248,   248,   248,   248,   248,   248,
     248,   249,   249,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     9,     8,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     0,     7,     2,
       0,     0,     2,     1,     2,     6,     1,     0,     1,     3,
       2,     4,     1,     2,     4,     2,     2,     0,     1,     5,
       6,     0,     2,     1,     1,     7,     2,     1,     1,     1,
       4,     2,     1,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     4,     1,     2,     3,     1,     0,     6,
       2,     0,     5,     1,     2,     2,     0,     6,     1,     1,
       5,     5,     6,     7,     7,     9,     5,     7,     3,     2,
       5,     7,     1,     1,     3,     2,     3,     2,     2,     1,
       1,     3,     1,     3,     3,     3,     3,     0,     1,     1,
       1,     1,     3,     4,     5,     2,     3,     2,     5,     4,
       4,     1,     1,     1,     4,     2,     1,     2,     1,     2,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     0,     1,     1,     1,     1,     5,     9,
       1,     1,     1,     1,     1,     8,     6,     6,     4,     1,
       2,     3,     1,     1,     1,     5,     1,     8,     2,     3,
       1,     3,     1,     1,     0,     2,     1,     2,     1,     1,
       1,     1,     2,     3,     1,     2,     7,     3,     1,     1,
       2,     1,     2,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     5,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     5,     2,
       2,     2,     2,     1,     2,     2,     1,     1,     3,     3,
       2,     1,     1,     3,     1,     2,     2,     3,     2,     2,
       1,     1,     2,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, arg, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, arg); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Scanner* arg)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (arg);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Scanner* arg)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, arg);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, Scanner* arg)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), arg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, arg); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Scanner* arg)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (arg);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (Scanner* arg)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scan);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prg: ast  */
#line 171 "src/gwion.y"
         { arg->ppa->ast = (yyval.ast) = (yyvsp[0].ast); /* no need for LIST_REM here */}
#line 2412 "src/parser.c"
    break;

  case 3: /* prg: %empty  */
#line 172 "src/gwion.y"
                { loc_t loc = { {1, 1}, {1,1} }; parser_error(&loc, arg, "file is empty.", 0201); YYERROR; }
#line 2418 "src/parser.c"
    break;

  case 4: /* ast: section  */
#line 175 "src/gwion.y"
            { (yyval.ast) = new_ast(mpool(arg), (yyvsp[0].section), NULL); LIST_FIRST((yyval.ast)) }
#line 2424 "src/parser.c"
    break;

  case 5: /* ast: ast section  */
#line 176 "src/gwion.y"
                { LIST_NEXT((yyval.ast), (yyvsp[-1].ast), Ast, new_ast(mpool(arg), (yyvsp[0].section), NULL)) }
#line 2430 "src/parser.c"
    break;

  case 6: /* section: stmt_list  */
#line 180 "src/gwion.y"
                 { (yyval.section) = new_section_stmt_list(mpool(arg), (yyvsp[0].stmt_list)); LIST_REM((yyval.section)) }
#line 2436 "src/parser.c"
    break;

  case 7: /* section: func_def  */
#line 181 "src/gwion.y"
                 { (yyval.section) = new_section_func_def (mpool(arg), (yyvsp[0].func_def)); }
#line 2442 "src/parser.c"
    break;

  case 8: /* section: class_def  */
#line 182 "src/gwion.y"
                 { (yyval.section) = new_section_class_def(mpool(arg), (yyvsp[0].class_def)); }
#line 2448 "src/parser.c"
    break;

  case 9: /* section: trait_def  */
#line 183 "src/gwion.y"
                 { (yyval.section) = new_section_trait_def(mpool(arg), (yyvsp[0].trait_def)); }
#line 2454 "src/parser.c"
    break;

  case 10: /* section: extend_def  */
#line 184 "src/gwion.y"
                 { (yyval.section) = new_section_extend_def(mpool(arg), (yyvsp[0].extend_def)); }
#line 2460 "src/parser.c"
    break;

  case 11: /* section: enum_def  */
#line 185 "src/gwion.y"
                 { (yyval.section) = new_section_enum_def(mpool(arg), (yyvsp[0].enum_def)); }
#line 2466 "src/parser.c"
    break;

  case 12: /* section: union_def  */
#line 186 "src/gwion.y"
                 { (yyval.section) = new_section_union_def(mpool(arg), (yyvsp[0].union_def)); }
#line 2472 "src/parser.c"
    break;

  case 13: /* section: fptr_def  */
#line 187 "src/gwion.y"
                 { (yyval.section) = new_section_fptr_def(mpool(arg), (yyvsp[0].fptr_def)); }
#line 2478 "src/parser.c"
    break;

  case 14: /* section: type_def  */
#line 188 "src/gwion.y"
                 { (yyval.section) = new_section_type_def(mpool(arg), (yyvsp[0].type_def)); }
#line 2484 "src/parser.c"
    break;

  case 15: /* class_flag: flag modifier  */
#line 191 "src/gwion.y"
                          { (yyval.flag) = (yyvsp[-1].flag) | (yyvsp[0].flag); }
#line 2490 "src/parser.c"
    break;

  case 16: /* class_def: "class" class_flag "<identifier>" decl_template class_ext traits "{" class_body "}"  */
#line 194 "src/gwion.y"
    {
      (yyval.class_def) = new_class_def(mpool(arg), (yyvsp[-7].flag), (yyvsp[-6].sym), (yyvsp[-4].type_decl), (yyvsp[-1].ast), (yylsp[-6]));
      if((yyvsp[-5].specialized_list))
        (yyval.class_def)->base.tmpl = new_tmpl_base(mpool(arg), (yyvsp[-5].specialized_list));
      (yyval.class_def)->traits = (yyvsp[-3].id_list);
    }
#line 2501 "src/parser.c"
    break;

  case 17: /* class_def: "struct" class_flag "<identifier>" decl_template traits "{" class_body "}"  */
#line 201 "src/gwion.y"
    {
      (yyval.class_def) = new_class_def(mpool(arg), (yyvsp[-6].flag), (yyvsp[-5].sym), NULL, (yyvsp[-1].ast), (yylsp[-5]));
      if((yyvsp[-4].specialized_list))
        (yyval.class_def)->base.tmpl = new_tmpl_base(mpool(arg), (yyvsp[-4].specialized_list));
      (yyval.class_def)->cflag |= cflag_struct;
      (yyval.class_def)->traits = (yyvsp[-3].id_list);
    }
#line 2513 "src/parser.c"
    break;

  case 18: /* trait_stmt: exp_stmt  */
#line 209 "src/gwion.y"
                     {
    if((yyvsp[0].stmt)->d.stmt_exp.val->exp_type != ae_exp_decl)
    { parser_error(&(yyloc), arg, "trait can only contains variable requests and functions", 0211); YYERROR;}
    (yyval.stmt) = (yyvsp[0].stmt);
  }
#line 2523 "src/parser.c"
    break;

  case 20: /* trait_stmt_list: trait_stmt  */
#line 214 "src/gwion.y"
                             { (yyval.stmt_list) = new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL); LIST_FIRST((yyval.stmt_list)) }
#line 2529 "src/parser.c"
    break;

  case 21: /* trait_stmt_list: trait_stmt_list trait_stmt  */
#line 215 "src/gwion.y"
                             { LIST_NEXT((yyval.stmt_list), (yyvsp[-1].stmt_list), Stmt_List, new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL)) }
#line 2535 "src/parser.c"
    break;

  case 22: /* trait_section: trait_stmt_list  */
#line 218 "src/gwion.y"
                       { (yyval.section) = new_section_stmt_list(mpool(arg), (yyvsp[0].stmt_list)); LIST_REM((yyval.section)) }
#line 2541 "src/parser.c"
    break;

  case 23: /* trait_section: func_def  */
#line 219 "src/gwion.y"
                 { (yyval.section) = new_section_func_def (mpool(arg), (yyvsp[0].func_def)); }
#line 2547 "src/parser.c"
    break;

  case 24: /* trait_ast: trait_section  */
#line 223 "src/gwion.y"
                  { (yyval.ast) = new_ast(mpool(arg), (yyvsp[0].section), NULL); LIST_FIRST((yyval.ast)) }
#line 2553 "src/parser.c"
    break;

  case 25: /* trait_ast: trait_ast trait_section  */
#line 224 "src/gwion.y"
                            { LIST_NEXT((yyval.ast), (yyvsp[-1].ast), Ast, new_ast(mpool(arg), (yyvsp[0].section), NULL)) }
#line 2559 "src/parser.c"
    break;

  case 27: /* trait_body: %empty  */
#line 227 "src/gwion.y"
                         { (yyval.ast) = NULL; }
#line 2565 "src/parser.c"
    break;

  case 28: /* trait_def: "trait" class_flag "<identifier>" traits "{" trait_body "}"  */
#line 230 "src/gwion.y"
    {
      (yyval.trait_def) = new_trait_def(mpool(arg), (yyvsp[-5].flag), (yyvsp[-4].sym), (yyvsp[-1].ast), (yylsp[-4]));
      (yyval.trait_def)->traits = (yyvsp[-3].id_list);
      if(GET_FLAG((yyval.trait_def), abstract)) {
        { scanner_secondary(arg, "abstract should not be used on ${/+trait{0} declaration", (yylsp[-4])); }
        UNSET_FLAG((yyval.trait_def), abstract);
      }
    }
#line 2578 "src/parser.c"
    break;

  case 29: /* class_ext: "extends" type_decl_exp  */
#line 239 "src/gwion.y"
                                    { (yyval.type_decl) = (yyvsp[0].type_decl); }
#line 2584 "src/parser.c"
    break;

  case 30: /* class_ext: %empty  */
#line 239 "src/gwion.y"
                                                   { (yyval.type_decl) = NULL; }
#line 2590 "src/parser.c"
    break;

  case 31: /* traits: %empty  */
#line 240 "src/gwion.y"
        { (yyval.id_list) = NULL; }
#line 2596 "src/parser.c"
    break;

  case 32: /* traits: ":" id_list  */
#line 240 "src/gwion.y"
                                     { (yyval.id_list) = (yyvsp[0].id_list); }
#line 2602 "src/parser.c"
    break;

  case 33: /* extend_body: func_def  */
#line 242 "src/gwion.y"
             {
    Section * section= new_section_func_def (mpool(arg), (yyvsp[0].func_def));
    (yyval.ast) = new_ast(mpool(arg), section, NULL); LIST_FIRST((yyval.ast))
  }
#line 2611 "src/parser.c"
    break;

  case 34: /* extend_body: extend_body func_def  */
#line 246 "src/gwion.y"
                         {
    Section * section = new_section_func_def (mpool(arg), (yyvsp[0].func_def));
    LIST_NEXT((yyval.ast), (yyvsp[-1].ast), Ast, new_ast(mpool(arg), section, NULL))
  }
#line 2620 "src/parser.c"
    break;

  case 35: /* extend_def: "extends" type_decl_empty traits "{" extend_body "}"  */
#line 252 "src/gwion.y"
                                                                 {
  (yyval.extend_def) = new_extend_def(mpool(arg), (yyvsp[-4].type_decl), (yyvsp[-1].ast));
  (yyval.extend_def)->traits = (yyvsp[-3].id_list);
}
#line 2629 "src/parser.c"
    break;

  case 37: /* class_body: %empty  */
#line 258 "src/gwion.y"
                   { (yyval.ast) = NULL; }
#line 2635 "src/parser.c"
    break;

  case 38: /* id_list: "<identifier>"  */
#line 260 "src/gwion.y"
            { (yyval.id_list) = new_id_list(mpool(arg), (yyvsp[0].sym)); LIST_FIRST((yyval.id_list)) }
#line 2641 "src/parser.c"
    break;

  case 39: /* id_list: id_list "," "<identifier>"  */
#line 261 "src/gwion.y"
                         { LIST_NEXT((yyval.id_list), (yyvsp[-2].id_list), ID_List, new_id_list(mpool(arg), (yyvsp[0].sym))) }
#line 2647 "src/parser.c"
    break;

  case 40: /* specialized_list: "<identifier>" traits  */
#line 263 "src/gwion.y"
                            { (yyval.specialized_list) = new_specialized_list(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].id_list), (yylsp[-1])); LIST_FIRST((yyval.specialized_list)) }
#line 2653 "src/parser.c"
    break;

  case 41: /* specialized_list: specialized_list "," "<identifier>" traits  */
#line 264 "src/gwion.y"
                                         { LIST_NEXT((yyval.specialized_list), (yyvsp[-3].specialized_list), Specialized_List, new_specialized_list(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].id_list), (yylsp[-1]))) }
#line 2659 "src/parser.c"
    break;

  case 42: /* stmt_list: stmt  */
#line 266 "src/gwion.y"
                 { (yyval.stmt_list) = new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL); LIST_FIRST((yyval.stmt_list)) }
#line 2665 "src/parser.c"
    break;

  case 43: /* stmt_list: stmt_list stmt  */
#line 267 "src/gwion.y"
                 { LIST_NEXT((yyval.stmt_list), (yyvsp[-1].stmt_list), Stmt_List, new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL)) }
#line 2671 "src/parser.c"
    break;

  case 44: /* fptr_base: flag type_decl_empty "<identifier>" decl_template  */
#line 269 "src/gwion.y"
                                                 { (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-2].type_decl), (yyvsp[-1].sym), NULL, (yyvsp[-3].flag), (yylsp[-2]));
  if((yyvsp[0].specialized_list)) { (yyval.func_base)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[0].specialized_list)); } }
#line 2678 "src/parser.c"
    break;

  case 45: /* _func_effects: "perform" "<identifier>"  */
#line 272 "src/gwion.y"
                            { vector_init(&(yyval.vector)); vector_add(&(yyval.vector), (m_uint)(yyvsp[0].sym)); }
#line 2684 "src/parser.c"
    break;

  case 46: /* _func_effects: _func_effects "<identifier>"  */
#line 272 "src/gwion.y"
                                                                                                  { vector_add(&(yyval.vector), (m_uint)(yyvsp[0].sym)); }
#line 2690 "src/parser.c"
    break;

  case 47: /* func_effects: %empty  */
#line 273 "src/gwion.y"
              { (yyval.vector).ptr = NULL; }
#line 2696 "src/parser.c"
    break;

  case 48: /* func_effects: _func_effects  */
#line 273 "src/gwion.y"
                                                 { (yyval.vector).ptr = (yyvsp[0].vector).ptr; }
#line 2702 "src/parser.c"
    break;

  case 49: /* func_base: flag final type_decl_empty "<identifier>" decl_template  */
#line 275 "src/gwion.y"
                                                       { (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-2].type_decl), (yyvsp[-1].sym), NULL, (yyvsp[-4].flag) | (yyvsp[-3].flag), (yylsp[-1]));
  if((yyvsp[0].specialized_list)) { (yyval.func_base)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[0].specialized_list)); } }
#line 2709 "src/parser.c"
    break;

  case 50: /* fptr_def: "funptr" fptr_base fptr_args arg_type func_effects ";"  */
#line 278 "src/gwion.y"
                                                                 {
  (yyvsp[-4].func_base)->args = (yyvsp[-3].arg_list);
  (yyvsp[-4].func_base)->fbflag |= (yyvsp[-2].fbflag);
  (yyval.fptr_def) = new_fptr_def(mpool(arg), (yyvsp[-4].func_base));
  (yyval.fptr_def)->base->effects.ptr = (yyvsp[-1].vector).ptr;
}
#line 2720 "src/parser.c"
    break;

  case 51: /* typedef_when: %empty  */
#line 285 "src/gwion.y"
              { (yyval.exp) = NULL;}
#line 2726 "src/parser.c"
    break;

  case 52: /* typedef_when: "when" binary_exp  */
#line 285 "src/gwion.y"
                                                { (yyval.exp) = (yyvsp[0].exp); }
#line 2732 "src/parser.c"
    break;

  case 53: /* type_def_type: "typedef"  */
#line 286 "src/gwion.y"
                         { (yyval.ival) = 0; }
#line 2738 "src/parser.c"
    break;

  case 54: /* type_def_type: "distinct"  */
#line 286 "src/gwion.y"
                                                  { (yyval.ival) = 1; }
#line 2744 "src/parser.c"
    break;

  case 55: /* type_def: type_def_type flag type_decl_array "<identifier>" decl_template typedef_when ";"  */
#line 287 "src/gwion.y"
                                                                               {
  (yyval.type_def) = new_type_def(mpool(arg), (yyvsp[-4].type_decl), (yyvsp[-3].sym), (yylsp[-3]));
  (yyvsp[-4].type_decl)->flag |= (yyvsp[-5].flag);
  (yyval.type_def)->when = (yyvsp[-1].exp);
  if((yyvsp[-2].specialized_list))
    (yyval.type_def)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-2].specialized_list));
  (yyval.type_def)->distinct = (yyvsp[-6].ival);
}
#line 2757 "src/parser.c"
    break;

  case 56: /* type_decl_array: type_decl array  */
#line 296 "src/gwion.y"
                                 { (yyvsp[-1].type_decl)->array = (yyvsp[0].array_sub); }
#line 2763 "src/parser.c"
    break;

  case 58: /* type_decl_exp: type_decl_array  */
#line 298 "src/gwion.y"
                               { if((yyvsp[0].type_decl)->array && !(yyvsp[0].type_decl)->array->exp)
    { parser_error(&(yyloc), arg, "can't instantiate with empty `[]`", 0203); YYERROR;}
  (yyval.type_decl) = (yyvsp[0].type_decl); }
#line 2771 "src/parser.c"
    break;

  case 59: /* type_decl_empty: type_decl_array  */
#line 302 "src/gwion.y"
                                 { if((yyvsp[0].type_decl)->array && (yyvsp[0].type_decl)->array->exp)
    { parser_error(&(yyloc), arg, "type must be defined with empty []'s", 0204); YYERROR;}
  (yyval.type_decl) = (yyvsp[0].type_decl); }
#line 2779 "src/parser.c"
    break;

  case 60: /* arg: type_decl_array arg_decl ":" binary_exp  */
#line 307 "src/gwion.y"
                                            { (yyval.arg_list) = new_arg_list(mpool(arg), (yyvsp[-3].type_decl), (yyvsp[-2].var_decl), NULL); (yyval.arg_list)->exp = (yyvsp[0].exp); }
#line 2785 "src/parser.c"
    break;

  case 61: /* arg: type_decl_array arg_decl  */
#line 308 "src/gwion.y"
                             { (yyval.arg_list) = new_arg_list(mpool(arg), (yyvsp[-1].type_decl), (yyvsp[0].var_decl), NULL); }
#line 2791 "src/parser.c"
    break;

  case 62: /* arg_list: arg  */
#line 310 "src/gwion.y"
         { (yyval.arg_list) = (yyvsp[0].arg_list); LIST_FIRST((yyvsp[0].arg_list)) }
#line 2797 "src/parser.c"
    break;

  case 63: /* arg_list: arg_list "," arg  */
#line 311 "src/gwion.y"
                      {
     LIST_NEXT((yyval.arg_list), (yyvsp[-2].arg_list), Arg_List, (yyvsp[0].arg_list))
     if(next->exp && !(yyvsp[0].arg_list)->exp)
        { parser_error(&(yylsp[0]), arg, "missing default argument", 0205); YYERROR;}
   }
#line 2807 "src/parser.c"
    break;

  case 64: /* fptr_arg: type_decl_array fptr_arg_decl  */
#line 317 "src/gwion.y"
                                        { (yyval.arg_list) = new_arg_list(mpool(arg), (yyvsp[-1].type_decl), (yyvsp[0].var_decl), NULL); }
#line 2813 "src/parser.c"
    break;

  case 65: /* fptr_list: fptr_arg  */
#line 318 "src/gwion.y"
                    { (yyval.arg_list) = (yyvsp[0].arg_list); LIST_FIRST((yyval.arg_list)) }
#line 2819 "src/parser.c"
    break;

  case 66: /* fptr_list: fptr_list "," fptr_arg  */
#line 318 "src/gwion.y"
                                                                         { LIST_NEXT((yyval.arg_list), (yyvsp[-2].arg_list), Arg_List, (yyvsp[0].arg_list)) }
#line 2825 "src/parser.c"
    break;

  case 67: /* code_stmt: "{" "}"  */
#line 321 "src/gwion.y"
            { (yyval.stmt) = new_stmt(mpool(arg), ae_stmt_code, (yyloc)); }
#line 2831 "src/parser.c"
    break;

  case 68: /* code_stmt: "{" stmt_list "}"  */
#line 322 "src/gwion.y"
                      { (yyval.stmt) = new_stmt_code(mpool(arg), (yyvsp[-1].stmt_list), (yyloc)); LIST_REM((yyvsp[-1].stmt_list)) }
#line 2837 "src/parser.c"
    break;

  case 69: /* stmt_pp: "<comment>"  */
#line 326 "src/gwion.y"
               { if(!arg->ppa->lint)return 0; (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_comment, (yyvsp[0].sval), (yyloc)); }
#line 2843 "src/parser.c"
    break;

  case 70: /* stmt_pp: "#include"  */
#line 327 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_include, (yyvsp[0].sval), (yyloc)); }
#line 2849 "src/parser.c"
    break;

  case 71: /* stmt_pp: "#define"  */
#line 328 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_define,  (yyvsp[0].sval), (yyloc)); }
#line 2855 "src/parser.c"
    break;

  case 72: /* stmt_pp: "#pragma"  */
#line 329 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_pragma,  (yyvsp[0].sval), (yyloc)); }
#line 2861 "src/parser.c"
    break;

  case 73: /* stmt_pp: "#undef"  */
#line 330 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_undef,   (yyvsp[0].sval), (yyloc)); }
#line 2867 "src/parser.c"
    break;

  case 74: /* stmt_pp: "#ifdef"  */
#line 331 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_ifdef,   (yyvsp[0].sval), (yyloc)); }
#line 2873 "src/parser.c"
    break;

  case 75: /* stmt_pp: "#ifndef"  */
#line 332 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_ifndef,  (yyvsp[0].sval), (yyloc)); }
#line 2879 "src/parser.c"
    break;

  case 76: /* stmt_pp: "#else"  */
#line 333 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_else,    (yyvsp[0].sval), (yyloc)); }
#line 2885 "src/parser.c"
    break;

  case 77: /* stmt_pp: "#if"  */
#line 334 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_endif,   (yyvsp[0].sval), (yyloc)); }
#line 2891 "src/parser.c"
    break;

  case 78: /* stmt_pp: "\n"  */
#line 335 "src/gwion.y"
               { if(!arg->ppa->lint)return 0; (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_nl,      (yyvsp[0].sval), (yyloc)); }
#line 2897 "src/parser.c"
    break;

  case 79: /* stmt_pp: "import"  */
#line 336 "src/gwion.y"
               { (yyval.stmt) = new_stmt_pp(mpool(arg), ae_pp_import, (yyvsp[0].sval), (yyloc)); }
#line 2903 "src/parser.c"
    break;

  case 91: /* retry_stmt: "retry" ";"  */
#line 353 "src/gwion.y"
                        {
  if(!arg->handling)
    { parser_error(&(yylsp[-1]), arg, "`retry` outside of `handle` block", 0); YYERROR; }
  (yyval.stmt) = new_stmt(mpool(arg), ae_stmt_retry, (yylsp[-1]));
}
#line 2913 "src/parser.c"
    break;

  case 92: /* $@1: %empty  */
#line 358 "src/gwion.y"
                  { arg->handling = true; }
#line 2919 "src/parser.c"
    break;

  case 93: /* handler: "handle" $@1 opt_id stmt  */
#line 358 "src/gwion.y"
                                                        { (yyval.handler_list) = new_handler_list(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].stmt), (yyvsp[-1].sym) ? (yylsp[-1]) :(yylsp[-3])); arg->handling = false; }
#line 2925 "src/parser.c"
    break;

  case 95: /* handler_list: handler_list handler  */
#line 360 "src/gwion.y"
                          {
        if(!(yyvsp[-1].handler_list)->xid)
        { parser_error(&(yylsp[0]), arg, "specific `handle` after a catch-all block", 0); YYERROR; }
        Handler_List list = (yyvsp[0].handler_list);
        while(list) {
          if(list->xid == (yyvsp[-1].handler_list)->xid)
          { parser_error(&(yylsp[0]), arg, "duplicated `handle`", 0); YYERROR; }
          list = list->next;
        }
        (yyval.handler_list) = (yyvsp[-1].handler_list);
        (yyvsp[-1].handler_list)->next = (yyvsp[0].handler_list);
  }
#line 2942 "src/parser.c"
    break;

  case 96: /* try_stmt: "try" stmt handler_list  */
#line 372 "src/gwion.y"
                                  { (yyval.stmt) = new_stmt_try(mpool(arg), (yyvsp[-1].stmt), (yyvsp[0].handler_list)); }
#line 2948 "src/parser.c"
    break;

  case 98: /* opt_id: %empty  */
#line 374 "src/gwion.y"
             { (yyval.sym) = NULL; }
#line 2954 "src/parser.c"
    break;

  case 99: /* enum_def: "enum" flag opt_id "{" id_list "}"  */
#line 377 "src/gwion.y"
                                       {
    (yyval.enum_def) = new_enum_def(mpool(arg), (yyvsp[-1].id_list), (yyvsp[-3].sym), (yyloc));
    (yyval.enum_def)->flag = (yyvsp[-4].flag);
    LIST_REM((yyvsp[-1].id_list))
  }
#line 2964 "src/parser.c"
    break;

  case 100: /* when_exp: "when" exp  */
#line 383 "src/gwion.y"
                     { (yyval.exp) = (yyvsp[0].exp); LIST_REM((yyvsp[0].exp)) }
#line 2970 "src/parser.c"
    break;

  case 101: /* when_exp: %empty  */
#line 383 "src/gwion.y"
                                                 { (yyval.exp) = NULL; }
#line 2976 "src/parser.c"
    break;

  case 102: /* match_case_stmt: "case" exp when_exp ":" stmt_list  */
#line 386 "src/gwion.y"
                                      {
    (yyval.stmt) = new_stmt(mpool(arg), 0, (yyloc));
    (yyval.stmt)->d.stmt_match.cond = (yyvsp[-3].exp);
    (yyval.stmt)->d.stmt_match.list = (yyvsp[0].stmt_list);
    (yyval.stmt)->d.stmt_match.when = (yyvsp[-2].exp);
    LIST_REM((yyvsp[-3].exp))
    LIST_REM((yyvsp[0].stmt_list))
}
#line 2989 "src/parser.c"
    break;

  case 103: /* match_list: match_case_stmt  */
#line 396 "src/gwion.y"
                    { (yyval.stmt_list) = new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL); LIST_FIRST((yyval.stmt_list)) }
#line 2995 "src/parser.c"
    break;

  case 104: /* match_list: match_list match_case_stmt  */
#line 397 "src/gwion.y"
                               { LIST_NEXT((yyval.stmt_list), (yyvsp[-1].stmt_list), Stmt_List, new_stmt_list(mpool(arg), (yyvsp[0].stmt), NULL)) }
#line 3001 "src/parser.c"
    break;

  case 105: /* where_stmt: "where" stmt  */
#line 399 "src/gwion.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3007 "src/parser.c"
    break;

  case 106: /* where_stmt: %empty  */
#line 399 "src/gwion.y"
                                        { (yyval.stmt) = NULL; }
#line 3013 "src/parser.c"
    break;

  case 107: /* match_stmt: "match" exp "{" match_list "}" where_stmt  */
#line 401 "src/gwion.y"
                                                      {
  (yyval.stmt) = new_stmt(mpool(arg), ae_stmt_match, (yyloc));
  (yyval.stmt)->d.stmt_match.cond  = (yyvsp[-4].exp);
  (yyval.stmt)->d.stmt_match.list  = (yyvsp[-2].stmt_list);
  (yyval.stmt)->d.stmt_match.where = (yyvsp[0].stmt);
  LIST_REM((yyvsp[-4].exp))
  LIST_REM((yyvsp[-2].stmt_list))
}
#line 3026 "src/parser.c"
    break;

  case 108: /* flow: "while"  */
#line 411 "src/gwion.y"
            { (yyval.ival) = ae_stmt_while; }
#line 3032 "src/parser.c"
    break;

  case 109: /* flow: "until"  */
#line 412 "src/gwion.y"
            { (yyval.ival) = ae_stmt_until; }
#line 3038 "src/parser.c"
    break;

  case 110: /* loop_stmt: flow "(" exp ")" stmt  */
#line 417 "src/gwion.y"
    { (yyval.stmt) = new_stmt_flow(mpool(arg), (yyvsp[-4].ival), (yyvsp[-2].exp), (yyvsp[0].stmt), false, (yyloc)); LIST_REM((yyvsp[-2].exp)) }
#line 3044 "src/parser.c"
    break;

  case 111: /* loop_stmt: "do" stmt flow exp ";"  */
#line 419 "src/gwion.y"
    { (yyval.stmt) = new_stmt_flow(mpool(arg), (yyvsp[-2].ival), (yyvsp[-1].exp), (yyvsp[-3].stmt), true, (yyloc)); LIST_REM((yyvsp[-2].ival)) }
#line 3050 "src/parser.c"
    break;

  case 112: /* loop_stmt: "for" "(" exp_stmt exp_stmt ")" stmt  */
#line 421 "src/gwion.y"
      { (yyval.stmt) = new_stmt_for(mpool(arg), (yyvsp[-3].stmt), (yyvsp[-2].stmt), NULL, (yyvsp[0].stmt), (yyloc)); }
#line 3056 "src/parser.c"
    break;

  case 113: /* loop_stmt: "for" "(" exp_stmt exp_stmt exp ")" stmt  */
#line 423 "src/gwion.y"
      { (yyval.stmt) = new_stmt_for(mpool(arg), (yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc)); LIST_REM((yyvsp[-2].exp)) }
#line 3062 "src/parser.c"
    break;

  case 114: /* loop_stmt: "foreach" "(" "<identifier>" ":" binary_exp ")" stmt  */
#line 425 "src/gwion.y"
      { (yyval.stmt) = new_stmt_each(mpool(arg), (yyvsp[-4].sym), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc)); }
#line 3068 "src/parser.c"
    break;

  case 115: /* loop_stmt: "foreach" "(" "<identifier>" "," "<identifier>" ":" binary_exp ")" stmt  */
#line 427 "src/gwion.y"
      { (yyval.stmt) = new_stmt_each(mpool(arg), (yyvsp[-4].sym), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc));
        (yyval.stmt)->d.stmt_each.idx = mp_malloc(mpool(arg), EachIdx);
        (yyval.stmt)->d.stmt_each.idx->sym = (yyvsp[-6].sym);
        (yyval.stmt)->d.stmt_each.idx->pos = (yylsp[-6]);
    }
#line 3078 "src/parser.c"
    break;

  case 116: /* loop_stmt: "repeat" "(" binary_exp ")" stmt  */
#line 433 "src/gwion.y"
      { (yyval.stmt) = new_stmt_loop(mpool(arg), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc)); LIST_REM((yyvsp[-2].exp)) }
#line 3084 "src/parser.c"
    break;

  case 117: /* loop_stmt: "repeat" "(" "<identifier>" "," binary_exp ")" stmt  */
#line 435 "src/gwion.y"
      { 
        (yyval.stmt) = new_stmt_loop(mpool(arg), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc));
        (yyval.stmt)->d.stmt_loop.idx = mp_malloc(mpool(arg), EachIdx);
        (yyval.stmt)->d.stmt_loop.idx->sym = (yyvsp[-4].sym);
        (yyval.stmt)->d.stmt_loop.idx->pos = (yylsp[-4]);        
        LIST_REM((yyvsp[-2].exp))
      }
#line 3096 "src/parser.c"
    break;

  case 118: /* varloop_stmt: "varloop" binary_exp code_stmt  */
#line 444 "src/gwion.y"
                                             { (yyval.stmt) = new_stmt_varloop(mpool(arg), (yyvsp[-1].exp), (yyvsp[0].stmt), (yyloc)); }
#line 3102 "src/parser.c"
    break;

  case 119: /* defer_stmt: "defer" stmt  */
#line 446 "src/gwion.y"
                         { (yyval.stmt) = new_stmt_defer(mpool(arg), (yyvsp[0].stmt), (yyloc)); }
#line 3108 "src/parser.c"
    break;

  case 120: /* selection_stmt: "if" "(" exp ")" stmt  */
#line 450 "src/gwion.y"
      { (yyval.stmt) = new_stmt_if(mpool(arg), (yyvsp[-2].exp), (yyvsp[0].stmt), (yyloc)); LIST_REM((yyvsp[-2].exp)) }
#line 3114 "src/parser.c"
    break;

  case 121: /* selection_stmt: "if" "(" exp ")" stmt "else" stmt  */
#line 452 "src/gwion.y"
      { (yyval.stmt) = new_stmt_if(mpool(arg), (yyvsp[-4].exp), (yyvsp[-2].stmt), (yyloc)); (yyval.stmt)->d.stmt_if.else_body = (yyvsp[0].stmt); LIST_REM((yyvsp[-4].exp)) }
#line 3120 "src/parser.c"
    break;

  case 122: /* breaks: "break"  */
#line 455 "src/gwion.y"
                    { (yyval.ival) = ae_stmt_break; }
#line 3126 "src/parser.c"
    break;

  case 123: /* breaks: "continue"  */
#line 455 "src/gwion.y"
                                                        { (yyval.ival) = ae_stmt_continue; }
#line 3132 "src/parser.c"
    break;

  case 124: /* jump_stmt: "return" exp ";"  */
#line 457 "src/gwion.y"
                     { (yyval.stmt) = new_stmt_exp(mpool(arg), ae_stmt_return, (yyvsp[-1].exp), (yyloc)); LIST_REM((yyvsp[-1].exp)) }
#line 3138 "src/parser.c"
    break;

  case 125: /* jump_stmt: "return" ";"  */
#line 458 "src/gwion.y"
                     { (yyval.stmt) = new_stmt(mpool(arg), ae_stmt_return, (yyloc)); }
#line 3144 "src/parser.c"
    break;

  case 126: /* jump_stmt: breaks "<integer>" ";"  */
#line 459 "src/gwion.y"
                     { (yyval.stmt) = new_stmt(mpool(arg), (yyvsp[-2].ival), (yyloc)); (yyval.stmt)->d.stmt_index.idx = (yyvsp[-1].lval); }
#line 3150 "src/parser.c"
    break;

  case 127: /* jump_stmt: breaks ";"  */
#line 460 "src/gwion.y"
                     { (yyval.stmt) = new_stmt(mpool(arg), (yyvsp[-1].ival), (yyloc)); (yyval.stmt)->d.stmt_index.idx = -1; }
#line 3156 "src/parser.c"
    break;

  case 128: /* exp_stmt: exp ";"  */
#line 464 "src/gwion.y"
            { (yyval.stmt) = new_stmt_exp(mpool(arg), ae_stmt_exp, (yyvsp[-1].exp), (yyloc)); LIST_REM((yyvsp[-1].exp)) }
#line 3162 "src/parser.c"
    break;

  case 129: /* exp_stmt: ";"  */
#line 465 "src/gwion.y"
            { (yyval.stmt) = new_stmt(mpool(arg), ae_stmt_exp, (yyloc)); }
#line 3168 "src/parser.c"
    break;

  case 130: /* exp: binary_exp  */
#line 469 "src/gwion.y"
                         { (yyval.exp) = (yyvsp[0].exp); LIST_FIRST((yyval.exp)) }
#line 3174 "src/parser.c"
    break;

  case 131: /* exp: exp "," binary_exp  */
#line 470 "src/gwion.y"
                       { LIST_NEXT((yyval.exp), (yyvsp[-2].exp), Exp, (yyvsp[0].exp)) }
#line 3180 "src/parser.c"
    break;

  case 133: /* binary_exp: binary_exp OPID_A decl_exp  */
#line 475 "src/gwion.y"
                                { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3186 "src/parser.c"
    break;

  case 134: /* binary_exp: binary_exp "<dynamic_operator>" decl_exp  */
#line 476 "src/gwion.y"
                                { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3192 "src/parser.c"
    break;

  case 135: /* binary_exp: binary_exp OPTIONS decl_exp  */
#line 477 "src/gwion.y"
                                { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3198 "src/parser.c"
    break;

  case 136: /* call_template: ":[" type_list "]"  */
#line 480 "src/gwion.y"
                                  { (yyval.type_list) = (yyvsp[-1].type_list); }
#line 3204 "src/parser.c"
    break;

  case 137: /* call_template: %empty  */
#line 480 "src/gwion.y"
                                                 { (yyval.type_list) = NULL; }
#line 3210 "src/parser.c"
    break;

  case 142: /* array_exp: "[" exp "]"  */
#line 485 "src/gwion.y"
                          { (yyval.array_sub) = new_array_sub(mpool(arg), (yyvsp[-1].exp));  LIST_REM((yyvsp[-1].exp)) }
#line 3216 "src/parser.c"
    break;

  case 143: /* array_exp: "[" exp "]" array_exp  */
#line 486 "src/gwion.y"
                          {
    LIST_REM((yyvsp[-2].exp))
    if((yyvsp[-2].exp)->next){ parser_error(&(yylsp[-2]), arg, "invalid format for array init [...][...]...", 0207); YYERROR; } (yyval.array_sub) = prepend_array_sub((yyvsp[0].array_sub), (yyvsp[-2].exp));
  }
#line 3225 "src/parser.c"
    break;

  case 144: /* array_exp: "[" exp "]" "[" "]"  */
#line 490 "src/gwion.y"
                         { LIST_REM(2) parser_error(&(yylsp[-2]), arg, "partially empty array init [...][]...", 0x0208); YYERROR; }
#line 3231 "src/parser.c"
    break;

  case 145: /* array_empty: "[" "]"  */
#line 494 "src/gwion.y"
                          { (yyval.array_sub) = new_array_sub(mpool(arg), NULL); }
#line 3237 "src/parser.c"
    break;

  case 146: /* array_empty: array_empty "[" "]"  */
#line 495 "src/gwion.y"
                          { (yyval.array_sub) = prepend_array_sub((yyvsp[-2].array_sub), NULL); }
#line 3243 "src/parser.c"
    break;

  case 147: /* array_empty: array_empty array_exp  */
#line 496 "src/gwion.y"
                          { parser_error(&(yylsp[-1]), arg, "partially empty array init [][...]", 0x0209); YYERROR; }
#line 3249 "src/parser.c"
    break;

  case 148: /* range: "[" exp ":" exp "]"  */
#line 500 "src/gwion.y"
                        { (yyval.range) = new_range(mpool(arg), (yyvsp[-3].exp), (yyvsp[-1].exp)); LIST_REM(2) LIST_REM((yyvsp[-1].exp)) }
#line 3255 "src/parser.c"
    break;

  case 149: /* range: "[" exp ":" "]"  */
#line 501 "src/gwion.y"
                        { (yyval.range) = new_range(mpool(arg), (yyvsp[-2].exp), NULL);  LIST_REM((yyvsp[-2].exp)) }
#line 3261 "src/parser.c"
    break;

  case 150: /* range: "[" ":" exp "]"  */
#line 502 "src/gwion.y"
                                          { (yyval.range) = new_range(mpool(arg), NULL, (yyvsp[-1].exp)); LIST_REM((yyvsp[-1].exp)) }
#line 3267 "src/parser.c"
    break;

  case 154: /* decl_exp: type_decl_flag2 flag type_decl_array var_decl_list  */
#line 507 "src/gwion.y"
                                                       { (yyval.exp)= new_exp_decl(mpool(arg), (yyvsp[-1].type_decl), (yyvsp[0].var_decl_list), (yyloc)); (yyval.exp)->d.exp_decl.td->flag |= (yyvsp[-3].flag) | (yyvsp[-2].flag); }
#line 3273 "src/parser.c"
    break;

  case 155: /* func_args: "(" arg_list  */
#line 509 "src/gwion.y"
                          { (yyval.arg_list) = (yyvsp[0].arg_list); LIST_REM((yyvsp[0].arg_list)) }
#line 3279 "src/parser.c"
    break;

  case 156: /* func_args: "("  */
#line 509 "src/gwion.y"
                                                          { (yyval.arg_list) = NULL; }
#line 3285 "src/parser.c"
    break;

  case 157: /* fptr_args: "(" fptr_list  */
#line 510 "src/gwion.y"
                         { (yyval.arg_list) = (yyvsp[0].arg_list); LIST_REM((yyvsp[0].arg_list)) }
#line 3291 "src/parser.c"
    break;

  case 158: /* fptr_args: "("  */
#line 510 "src/gwion.y"
                                                         { (yyval.arg_list) = NULL; }
#line 3297 "src/parser.c"
    break;

  case 159: /* arg_type: "..." ")"  */
#line 511 "src/gwion.y"
                    { (yyval.fbflag) = fbflag_variadic; }
#line 3303 "src/parser.c"
    break;

  case 160: /* arg_type: ")"  */
#line 511 "src/gwion.y"
                                                   { (yyval.fbflag) = 0; }
#line 3309 "src/parser.c"
    break;

  case 161: /* decl_template: ":[" specialized_list "]"  */
#line 513 "src/gwion.y"
                                         { (yyval.specialized_list) = (yyvsp[-1].specialized_list); LIST_REM(2) }
#line 3315 "src/parser.c"
    break;

  case 162: /* decl_template: %empty  */
#line 513 "src/gwion.y"
                                                                    { (yyval.specialized_list) = NULL; }
#line 3321 "src/parser.c"
    break;

  case 163: /* global: "global"  */
#line 515 "src/gwion.y"
               { (yyval.flag) = ae_flag_global; arg->global = true; }
#line 3327 "src/parser.c"
    break;

  case 164: /* storage_flag: "static"  */
#line 517 "src/gwion.y"
                     { (yyval.flag) = ae_flag_static; }
#line 3333 "src/parser.c"
    break;

  case 166: /* access_flag: "private"  */
#line 519 "src/gwion.y"
                     { (yyval.flag) = ae_flag_private; }
#line 3339 "src/parser.c"
    break;

  case 167: /* access_flag: "protect"  */
#line 520 "src/gwion.y"
            { (yyval.flag) = ae_flag_protect; }
#line 3345 "src/parser.c"
    break;

  case 168: /* flag: access_flag  */
#line 523 "src/gwion.y"
                  { (yyval.flag) = (yyvsp[0].flag); }
#line 3351 "src/parser.c"
    break;

  case 169: /* flag: storage_flag  */
#line 524 "src/gwion.y"
                  { (yyval.flag) = (yyvsp[0].flag); }
#line 3357 "src/parser.c"
    break;

  case 170: /* flag: access_flag storage_flag  */
#line 525 "src/gwion.y"
                              { (yyval.flag) = (yyvsp[-1].flag) | (yyvsp[0].flag); }
#line 3363 "src/parser.c"
    break;

  case 171: /* flag: %empty  */
#line 526 "src/gwion.y"
    { (yyval.flag) = ae_flag_none; }
#line 3369 "src/parser.c"
    break;

  case 172: /* final: "final"  */
#line 529 "src/gwion.y"
               { (yyval.flag) = ae_flag_final; }
#line 3375 "src/parser.c"
    break;

  case 173: /* final: %empty  */
#line 529 "src/gwion.y"
                                         { (yyval.flag) = ae_flag_none; }
#line 3381 "src/parser.c"
    break;

  case 174: /* modifier: "abstract"  */
#line 531 "src/gwion.y"
                     { (yyval.flag) = ae_flag_abstract; }
#line 3387 "src/parser.c"
    break;

  case 177: /* func_code: ";"  */
#line 533 "src/gwion.y"
                           { (yyval.stmt) = NULL; }
#line 3393 "src/parser.c"
    break;

  case 178: /* func_def_base: "fun" func_base func_args arg_type func_code  */
#line 535 "src/gwion.y"
                                                 {
    (yyvsp[-3].func_base)->args = (yyvsp[-2].arg_list);
    (yyvsp[-3].func_base)->fbflag |= (yyvsp[-1].fbflag);
    (yyval.func_def) = new_func_def(mpool(arg), (yyvsp[-3].func_base), (yyvsp[0].stmt));
//    $$->trait = $5;
    if(!(yyvsp[0].stmt)) {
      SET_FLAG((yyvsp[-3].func_base), abstract);
    }
  }
#line 3407 "src/parser.c"
    break;

  case 179: /* abstract_fdef: "fun" flag "abstract" type_decl_empty "<identifier>" decl_template fptr_args arg_type ";"  */
#line 547 "src/gwion.y"
    { Func_Base *base = new_func_base(mpool(arg), (yyvsp[-5].type_decl), (yyvsp[-4].sym), NULL, (yyvsp[-7].flag) | ae_flag_abstract, (yylsp[-4]));
      if((yyvsp[-3].specialized_list))
        base->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-3].specialized_list));
      base->args = (yyvsp[-2].arg_list);
      base->fbflag |= (yyvsp[-1].fbflag);
      (yyval.func_def) = new_func_def(mpool(arg), base, NULL);
    }
#line 3419 "src/parser.c"
    break;

  case 185: /* op_base: type_decl_empty op_op decl_template "(" arg "," arg ")"  */
#line 558 "src/gwion.y"
    { (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-7].type_decl), (yyvsp[-6].sym), (yyvsp[-3].arg_list), ae_flag_none, (yylsp[-6])); (yyvsp[-3].arg_list)->next = (yyvsp[-1].arg_list);
      if((yyvsp[-5].specialized_list))(yyval.func_base)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-5].specialized_list));
    }
#line 3427 "src/parser.c"
    break;

  case 186: /* op_base: type_decl_empty post_op decl_template "(" arg ")"  */
#line 562 "src/gwion.y"
    { (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-5].type_decl), (yyvsp[-4].sym), (yyvsp[-1].arg_list), ae_flag_none, (yylsp[-4]));
      if((yyvsp[-3].specialized_list))(yyval.func_base)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-3].specialized_list));
    }
#line 3435 "src/parser.c"
    break;

  case 187: /* op_base: unary_op type_decl_empty decl_template "(" arg ")"  */
#line 566 "src/gwion.y"
    {
      (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-4].type_decl), (yyvsp[-5].sym), (yyvsp[-1].arg_list), ae_flag_none, (yylsp[-5]));
      (yyval.func_base)->fbflag |= fbflag_unary;
      if((yyvsp[-3].specialized_list))(yyval.func_base)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-3].specialized_list));
    }
#line 3445 "src/parser.c"
    break;

  case 188: /* op_base: type_decl_empty OPID_A func_args ")"  */
#line 572 "src/gwion.y"
    {
      (yyval.func_base) = new_func_base(mpool(arg), (yyvsp[-3].type_decl), (yyvsp[-2].sym), (yyvsp[-1].arg_list), ae_flag_none, (yylsp[-2]));
      (yyval.func_base)->fbflag |= fbflag_internal;
    }
#line 3454 "src/parser.c"
    break;

  case 189: /* operator: "operator"  */
#line 577 "src/gwion.y"
                     { (yyval.flag) = ae_flag_none; }
#line 3460 "src/parser.c"
    break;

  case 190: /* operator: "operator" global  */
#line 577 "src/gwion.y"
                                                                { (yyval.flag) = ae_flag_global; }
#line 3466 "src/parser.c"
    break;

  case 191: /* op_def: operator op_base code_stmt  */
#line 580 "src/gwion.y"
  { (yyval.func_def) = new_func_def(mpool(arg), (yyvsp[-1].func_base), (yyvsp[0].stmt)); (yyvsp[-1].func_base)->fbflag |= fbflag_op; (yyvsp[-1].func_base)->flag |= (yyvsp[-2].flag); }
#line 3472 "src/parser.c"
    break;

  case 194: /* func_def: op_def  */
#line 582 "src/gwion.y"
                                                 { (yyval.func_def) = (yyvsp[0].func_def); (yyval.func_def)->base->fbflag |= fbflag_op; }
#line 3478 "src/parser.c"
    break;

  case 195: /* func_def: operator "new" func_args arg_type code_stmt  */
#line 584 "src/gwion.y"
    { Func_Base *const base = new_func_base(mpool(arg), NULL, (yyvsp[-3].sym), (yyvsp[-2].arg_list), (yyvsp[-4].flag), (yylsp[-3]));
      base->fbflag = (yyvsp[-1].fbflag);
      (yyval.func_def) = new_func_def(mpool(arg), base, (yyvsp[0].stmt));
    }
#line 3487 "src/parser.c"
    break;

  case 196: /* type_decl_base: "<identifier>"  */
#line 590 "src/gwion.y"
       { (yyval.type_decl) = new_type_decl(mpool(arg), (yyvsp[0].sym), (yyloc)); }
#line 3493 "src/parser.c"
    break;

  case 197: /* type_decl_base: "(" flag type_decl_empty decl_template fptr_args arg_type func_effects ")"  */
#line 591 "src/gwion.y"
                                                                               {
      const Symbol name = sig_name(arg, (yylsp[-5]).first);
      (yyval.type_decl) = new_type_decl(mpool(arg), name, (yylsp[-7]));
      Func_Base *fb = new_func_base(mpool(arg), (yyvsp[-5].type_decl), name, NULL, (yyvsp[-6].flag), (yylsp[-7]));
      if((yyvsp[-4].specialized_list))
        fb->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-4].specialized_list));
      fb->args = (yyvsp[-3].arg_list);
      fb->fbflag |= (yyvsp[-2].fbflag);
      const Fptr_Def fptr = new_fptr_def(mpool(arg), fb);
      fptr->base->effects.ptr = (yyvsp[-1].vector).ptr;
      (yyval.type_decl)->fptr = fptr;
  }
#line 3510 "src/parser.c"
    break;

  case 198: /* type_decl_tmpl: type_decl_base call_template  */
#line 606 "src/gwion.y"
                                 { (yyval.type_decl) = (yyvsp[-1].type_decl); (yyval.type_decl)->types = (yyvsp[0].type_list); }
#line 3516 "src/parser.c"
    break;

  case 199: /* type_decl_tmpl: "&" type_decl_base call_template  */
#line 607 "src/gwion.y"
                                     { (yyval.type_decl) = (yyvsp[-1].type_decl); (yyval.type_decl)->ref = true; (yyval.type_decl)->types = (yyvsp[0].type_list); }
#line 3522 "src/parser.c"
    break;

  case 201: /* type_decl_noflag: type_decl_tmpl "." type_decl_noflag  */
#line 612 "src/gwion.y"
                                        { (yyvsp[-2].type_decl)->next = (yyvsp[0].type_decl); }
#line 3528 "src/parser.c"
    break;

  case 202: /* option: "?"  */
#line 615 "src/gwion.y"
            { (yyval.uval) = 1; }
#line 3534 "src/parser.c"
    break;

  case 203: /* option: OPTIONS  */
#line 615 "src/gwion.y"
                                  { (yyval.uval) = strlen(s_name((yyvsp[0].sym))); }
#line 3540 "src/parser.c"
    break;

  case 204: /* option: %empty  */
#line 615 "src/gwion.y"
                                                                 { (yyval.uval) = 0; }
#line 3546 "src/parser.c"
    break;

  case 205: /* type_decl_opt: type_decl_noflag option  */
#line 616 "src/gwion.y"
                                       { (yyval.type_decl) = (yyvsp[-1].type_decl); (yyval.type_decl)->option = (yyvsp[0].uval); }
#line 3552 "src/parser.c"
    break;

  case 207: /* type_decl: type_decl_flag type_decl_opt  */
#line 617 "src/gwion.y"
                                                        { (yyval.type_decl) = (yyvsp[0].type_decl); (yyval.type_decl)->flag |= (yyvsp[-1].flag); }
#line 3558 "src/parser.c"
    break;

  case 208: /* type_decl_flag: "late"  */
#line 620 "src/gwion.y"
            { (yyval.flag) = ae_flag_late; }
#line 3564 "src/parser.c"
    break;

  case 209: /* type_decl_flag: "const"  */
#line 621 "src/gwion.y"
            { (yyval.flag) = ae_flag_const; }
#line 3570 "src/parser.c"
    break;

  case 210: /* type_decl_flag2: "var"  */
#line 623 "src/gwion.y"
                        { (yyval.flag) = ae_flag_none; }
#line 3576 "src/parser.c"
    break;

  case 212: /* union_decl: "<identifier>" ";"  */
#line 626 "src/gwion.y"
                   {
  Type_Decl *td = new_type_decl(mpool(arg), insert_symbol("None"), (yylsp[-1]));
  (yyval.union_list) = new_union_list(mpool(arg), td, (yyvsp[-1].sym), (yylsp[-1]));
}
#line 3585 "src/parser.c"
    break;

  case 213: /* union_decl: type_decl_empty "<identifier>" ";"  */
#line 630 "src/gwion.y"
                         { (yyval.union_list) = new_union_list(mpool(arg), (yyvsp[-2].type_decl), (yyvsp[-1].sym), (yyloc)); }
#line 3591 "src/parser.c"
    break;

  case 215: /* union_list: union_decl union_list  */
#line 633 "src/gwion.y"
                          { (yyval.union_list) = (yyvsp[-1].union_list); (yyval.union_list)->next = (yyvsp[0].union_list); }
#line 3597 "src/parser.c"
    break;

  case 216: /* union_def: "union" flag "<identifier>" decl_template "{" union_list "}"  */
#line 636 "src/gwion.y"
                                                     {
      (yyval.union_def) = new_union_def(mpool(arg), (yyvsp[-1].union_list), (yylsp[-4]));
      (yyval.union_def)->xid = (yyvsp[-4].sym);
      (yyval.union_def)->flag = (yyvsp[-5].flag);
      if((yyvsp[-3].specialized_list))
        (yyval.union_def)->tmpl = new_tmpl_base(mpool(arg), (yyvsp[-3].specialized_list));
    }
#line 3609 "src/parser.c"
    break;

  case 217: /* var_decl_list: var_decl "," var_decl_list  */
#line 646 "src/gwion.y"
                               { (yyval.var_decl_list) = new_var_decl_list(mpool(arg), (yyvsp[-2].var_decl), (yyvsp[0].var_decl_list)); }
#line 3615 "src/parser.c"
    break;

  case 218: /* var_decl_list: var_decl  */
#line 647 "src/gwion.y"
             { (yyval.var_decl_list) = new_var_decl_list(mpool(arg), (yyvsp[0].var_decl), NULL); }
#line 3621 "src/parser.c"
    break;

  case 219: /* var_decl: "<identifier>"  */
#line 650 "src/gwion.y"
             { (yyval.var_decl) = new_var_decl(mpool(arg), (yyvsp[0].sym), NULL, (yylsp[0])); }
#line 3627 "src/parser.c"
    break;

  case 220: /* var_decl: "<identifier>" array  */
#line 651 "src/gwion.y"
               { (yyval.var_decl) = new_var_decl(mpool(arg), (yyvsp[-1].sym),   (yyvsp[0].array_sub), (yyloc)); }
#line 3633 "src/parser.c"
    break;

  case 221: /* arg_decl: "<identifier>"  */
#line 653 "src/gwion.y"
             { (yyval.var_decl) = new_var_decl(mpool(arg), (yyvsp[0].sym), NULL, (yyloc)); }
#line 3639 "src/parser.c"
    break;

  case 222: /* arg_decl: "<identifier>" array_empty  */
#line 654 "src/gwion.y"
                   { (yyval.var_decl) = new_var_decl(mpool(arg), (yyvsp[-1].sym),   (yyvsp[0].array_sub), (yyloc)); }
#line 3645 "src/parser.c"
    break;

  case 223: /* arg_decl: "<identifier>" array_exp  */
#line 655 "src/gwion.y"
                 { parser_error(&(yylsp[0]), arg, "argument/union must be defined with empty []'s", 0210); YYERROR; }
#line 3651 "src/parser.c"
    break;

  case 225: /* fptr_arg_decl: %empty  */
#line 656 "src/gwion.y"
                          { (yyval.var_decl) = new_var_decl(mpool(arg), NULL, NULL, (yyloc)); }
#line 3657 "src/parser.c"
    break;

  case 239: /* opt_exp: exp  */
#line 664 "src/gwion.y"
             { (yyval.exp) = (yyvsp[0].exp); LIST_REM((yyvsp[0].exp)) }
#line 3663 "src/parser.c"
    break;

  case 240: /* opt_exp: %empty  */
#line 664 "src/gwion.y"
                                         { (yyval.exp) = NULL; }
#line 3669 "src/parser.c"
    break;

  case 242: /* con_exp: log_or_exp "?" opt_exp ":" con_exp  */
#line 667 "src/gwion.y"
      { (yyval.exp) = new_exp_if(mpool(arg), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp), (yyloc)); }
#line 3675 "src/parser.c"
    break;

  case 243: /* con_exp: log_or_exp "?:" con_exp  */
#line 669 "src/gwion.y"
      { (yyval.exp) = new_exp_if(mpool(arg), (yyvsp[-2].exp), NULL, (yyvsp[0].exp), (yyloc)); }
#line 3681 "src/parser.c"
    break;

  case 245: /* log_or_exp: log_or_exp "||" log_and_exp  */
#line 671 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3687 "src/parser.c"
    break;

  case 247: /* log_and_exp: log_and_exp "&&" inc_or_exp  */
#line 672 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3693 "src/parser.c"
    break;

  case 249: /* inc_or_exp: inc_or_exp "|" exc_or_exp  */
#line 673 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3699 "src/parser.c"
    break;

  case 251: /* exc_or_exp: exc_or_exp "^" and_exp  */
#line 674 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3705 "src/parser.c"
    break;

  case 253: /* and_exp: and_exp "&" eq_exp  */
#line 675 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3711 "src/parser.c"
    break;

  case 255: /* eq_exp: eq_exp eq_op rel_exp  */
#line 676 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3717 "src/parser.c"
    break;

  case 257: /* rel_exp: rel_exp rel_op shift_exp  */
#line 677 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3723 "src/parser.c"
    break;

  case 259: /* shift_exp: shift_exp shift_op add_exp  */
#line 678 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3729 "src/parser.c"
    break;

  case 261: /* add_exp: add_exp add_op mul_exp  */
#line 679 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3735 "src/parser.c"
    break;

  case 263: /* mul_exp: mul_exp mul_op dur_exp  */
#line 680 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3741 "src/parser.c"
    break;

  case 265: /* dur_exp: dur_exp "::" cast_exp  */
#line 681 "src/gwion.y"
                                                       { (yyval.exp) = new_exp_binary(mpool(arg), (yyvsp[-2].exp), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3747 "src/parser.c"
    break;

  case 267: /* cast_exp: cast_exp "$" type_decl_empty  */
#line 684 "src/gwion.y"
    { (yyval.exp) = new_exp_cast(mpool(arg), (yyvsp[0].type_decl), (yyvsp[-2].exp), (yyloc)); }
#line 3753 "src/parser.c"
    break;

  case 276: /* unary_exp: unary_op unary_exp  */
#line 691 "src/gwion.y"
                       { (yyval.exp) = new_exp_unary(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3759 "src/parser.c"
    break;

  case 277: /* unary_exp: OPID_E unary_exp  */
#line 692 "src/gwion.y"
                     { (yyval.exp) = new_exp_unary(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].exp), (yyloc)); }
#line 3765 "src/parser.c"
    break;

  case 278: /* unary_exp: "new" type_decl_exp "(" opt_exp ")"  */
#line 693 "src/gwion.y"
                                        {
       (yyval.exp) = new_exp_unary2(mpool(arg), (yyvsp[-4].sym), (yyvsp[-3].type_decl), (yyvsp[-1].exp) ?: new_prim_nil(mpool(arg), (yylsp[-1])), (yyloc));
  }
#line 3773 "src/parser.c"
    break;

  case 279: /* unary_exp: "new" type_decl_exp  */
#line 696 "src/gwion.y"
                        {(yyval.exp) = new_exp_unary2(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].type_decl), NULL, (yyloc)); }
#line 3779 "src/parser.c"
    break;

  case 280: /* unary_exp: "spork" code_stmt  */
#line 697 "src/gwion.y"
                        { (yyval.exp) = new_exp_unary3(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].stmt), (yyloc)); }
#line 3785 "src/parser.c"
    break;

  case 281: /* unary_exp: "fork" code_stmt  */
#line 698 "src/gwion.y"
                        { (yyval.exp) = new_exp_unary3(mpool(arg), (yyvsp[-1].sym), (yyvsp[0].stmt), (yyloc)); }
#line 3791 "src/parser.c"
    break;

  case 282: /* unary_exp: "$" type_decl_empty  */
#line 699 "src/gwion.y"
                        { (yyval.exp) = new_exp_td(mpool(arg), (yyvsp[0].type_decl), (yylsp[0])); }
#line 3797 "src/parser.c"
    break;

  case 283: /* lambda_list: "<identifier>"  */
#line 702 "src/gwion.y"
    { (yyval.arg_list) = new_arg_list(mpool(arg), NULL, new_var_decl(mpool(arg), (yyvsp[0].sym), NULL, (yyloc)), NULL); }
#line 3803 "src/parser.c"
    break;

  case 284: /* lambda_list: "<identifier>" lambda_list  */
#line 703 "src/gwion.y"
                    { (yyval.arg_list) = new_arg_list(mpool(arg), NULL, new_var_decl(mpool(arg), (yyvsp[-1].sym), NULL, (yyloc)), (yyvsp[0].arg_list)); }
#line 3809 "src/parser.c"
    break;

  case 285: /* lambda_arg: "\\" lambda_list  */
#line 704 "src/gwion.y"
                             { (yyval.arg_list) = (yyvsp[0].arg_list); }
#line 3815 "src/parser.c"
    break;

  case 286: /* lambda_arg: "\\"  */
#line 704 "src/gwion.y"
                                                      { (yyval.arg_list) = NULL; }
#line 3821 "src/parser.c"
    break;

  case 287: /* type_list: type_decl_empty  */
#line 707 "src/gwion.y"
                    { (yyval.type_list) = new_type_list(mpool(arg), (yyvsp[0].type_decl), NULL); }
#line 3827 "src/parser.c"
    break;

  case 288: /* type_list: type_decl_empty "," type_list  */
#line 708 "src/gwion.y"
                                  { (yyval.type_list) = new_type_list(mpool(arg), (yyvsp[-2].type_decl), (yyvsp[0].type_list)); }
#line 3833 "src/parser.c"
    break;

  case 289: /* call_paren: "(" exp ")"  */
#line 712 "src/gwion.y"
                         { (yyval.exp) = (yyvsp[-1].exp); LIST_REM((yyvsp[-1].exp)) }
#line 3839 "src/parser.c"
    break;

  case 290: /* call_paren: "(" ")"  */
#line 712 "src/gwion.y"
                                                             { (yyval.exp) = NULL; }
#line 3845 "src/parser.c"
    break;

  case 293: /* dot_exp: post_exp "." "<identifier>"  */
#line 716 "src/gwion.y"
                         {
  if((yyvsp[-2].exp)->next) {
    parser_error(&(yylsp[-2]), arg, "can't use multiple expression"
      " in dot member base expression", 0211);
    YYERROR;
  };
  (yyval.exp) = new_exp_dot(mpool(arg), (yyvsp[-2].exp), (yyvsp[0].sym), (yyloc));
}
#line 3858 "src/parser.c"
    break;

  case 295: /* post_exp: post_exp array_exp  */
#line 727 "src/gwion.y"
    { (yyval.exp) = new_exp_array(mpool(arg), (yyvsp[-1].exp), (yyvsp[0].array_sub), (yyloc)); }
#line 3864 "src/parser.c"
    break;

  case 296: /* post_exp: post_exp range  */
#line 729 "src/gwion.y"
    { (yyval.exp) = new_exp_slice(mpool(arg), (yyvsp[-1].exp), (yyvsp[0].range), (yyloc)); }
#line 3870 "src/parser.c"
    break;

  case 297: /* post_exp: post_exp call_template call_paren  */
#line 731 "src/gwion.y"
    { (yyval.exp) = new_exp_call(mpool(arg), (yyvsp[-2].exp), (yyvsp[0].exp), (yyloc));
      if((yyvsp[-1].type_list))(yyval.exp)->d.exp_call.tmpl = new_tmpl_call(mpool(arg), (yyvsp[-1].type_list)); }
#line 3877 "src/parser.c"
    break;

  case 298: /* post_exp: post_exp post_op  */
#line 734 "src/gwion.y"
    { (yyval.exp) = new_exp_post(mpool(arg), (yyvsp[-1].exp), (yyvsp[0].sym), (yyloc)); }
#line 3883 "src/parser.c"
    break;

  case 299: /* post_exp: post_exp OPID_E  */
#line 736 "src/gwion.y"
    { (yyval.exp) = new_exp_post(mpool(arg), (yyvsp[-1].exp), (yyvsp[0].sym), (yyloc)); }
#line 3889 "src/parser.c"
    break;

  case 300: /* post_exp: dot_exp  */
#line 737 "src/gwion.y"
            { (yyval.exp) = (yyvsp[0].exp); }
#line 3895 "src/parser.c"
    break;

  case 301: /* interp_exp: "<interp string>`"  */
#line 741 "src/gwion.y"
               { (yyval.exp) = new_prim_string(mpool(arg), (yyvsp[0].sval), (yyloc)); }
#line 3901 "src/parser.c"
    break;

  case 302: /* interp_exp: "<interp string>" interp_exp  */
#line 742 "src/gwion.y"
                          { (yyval.exp) = new_prim_string(mpool(arg), (yyvsp[-1].sval), (yyloc)); (yyval.exp)->next = (yyvsp[0].exp); }
#line 3907 "src/parser.c"
    break;

  case 303: /* interp_exp: exp INTERP_EXP interp_exp  */
#line 743 "src/gwion.y"
                              { (yyval.exp) = (yyvsp[-2].exp); (yyval.exp)->next = (yyvsp[0].exp); LIST_REM((yyvsp[-2].exp)) }
#line 3913 "src/parser.c"
    break;

  case 304: /* interp: "`" interp_exp  */
#line 745 "src/gwion.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 3919 "src/parser.c"
    break;

  case 305: /* interp: interp "`" interp_exp  */
#line 746 "src/gwion.y"
                                 {
  if(!(yyvsp[0].exp)->next) {
    char c[strlen((yyvsp[-2].exp)->d.prim.d.str) + strlen((yyvsp[0].exp)->d.prim.d.str) + 1];
    sprintf(c, "%s%s\n", (yyvsp[-2].exp)->d.prim.d.str, (yyvsp[0].exp)->d.prim.d.str);
    (yyvsp[-2].exp)->d.prim.d.str = s_name(insert_symbol(c));
    (yyvsp[-2].exp)->pos.last = (yyvsp[0].exp)->pos.last;
    free_exp(mpool(arg), (yyvsp[0].exp));
  } else
  (yyvsp[-2].exp)->next = (yyvsp[0].exp);
}
#line 3934 "src/parser.c"
    break;

  case 306: /* prim_exp: "<identifier>"  */
#line 758 "src/gwion.y"
                         { (yyval.exp) = new_prim_id(     mpool(arg), (yyvsp[0].sym), (yyloc)); }
#line 3940 "src/parser.c"
    break;

  case 307: /* prim_exp: "<integer>"  */
#line 759 "src/gwion.y"
                         { (yyval.exp) = new_prim_int(    mpool(arg), (yyvsp[0].lval), (yyloc)); }
#line 3946 "src/parser.c"
    break;

  case 308: /* prim_exp: FLOATT  */
#line 760 "src/gwion.y"
                         { (yyval.exp) = new_prim_float(  mpool(arg), (yyvsp[0].fval), (yyloc)); }
#line 3952 "src/parser.c"
    break;

  case 309: /* prim_exp: interp  */
#line 761 "src/gwion.y"
                         { (yyval.exp) = !(yyvsp[0].exp)->next ? (yyvsp[0].exp) : new_prim_interp(mpool(arg), (yyvsp[0].exp), (yyloc)); }
#line 3958 "src/parser.c"
    break;

  case 310: /* prim_exp: "<litteral string>"  */
#line 762 "src/gwion.y"
                         { (yyval.exp) = new_prim_string( mpool(arg), (yyvsp[0].sval), (yyloc)); }
#line 3964 "src/parser.c"
    break;

  case 311: /* prim_exp: "<litteral char>"  */
#line 763 "src/gwion.y"
                         { (yyval.exp) = new_prim_char(   mpool(arg), (yyvsp[0].sval), (yyloc)); }
#line 3970 "src/parser.c"
    break;

  case 312: /* prim_exp: array  */
#line 764 "src/gwion.y"
                         { (yyval.exp) = new_prim_array(  mpool(arg), (yyvsp[0].array_sub), (yyloc)); }
#line 3976 "src/parser.c"
    break;

  case 313: /* prim_exp: range  */
#line 765 "src/gwion.y"
                         { (yyval.exp) = new_prim_range(  mpool(arg), (yyvsp[0].range), (yyloc)); }
#line 3982 "src/parser.c"
    break;

  case 314: /* prim_exp: "<<<" exp ">>>"  */
#line 766 "src/gwion.y"
                         { (yyval.exp) = new_prim_hack(   mpool(arg), (yyvsp[-1].exp), (yyloc)); LIST_REM(2) }
#line 3988 "src/parser.c"
    break;

  case 315: /* prim_exp: "(" exp ")"  */
#line 767 "src/gwion.y"
                         { (yyval.exp) = (yyvsp[-1].exp); LIST_REM((yyvsp[-1].exp)) }
#line 3994 "src/parser.c"
    break;

  case 316: /* prim_exp: lambda_arg code_stmt  */
#line 768 "src/gwion.y"
                         { (yyval.exp) = new_exp_lambda( mpool(arg), lambda_name(arg), (yyvsp[-1].arg_list), (yyvsp[0].stmt), (yyloc)); }
#line 4000 "src/parser.c"
    break;

  case 317: /* prim_exp: "(" op_op ")"  */
#line 769 "src/gwion.y"
                         { (yyval.exp) = new_prim_id(     mpool(arg), (yyvsp[-1].sym), (yyloc)); }
#line 4006 "src/parser.c"
    break;

  case 318: /* prim_exp: "perform" "<identifier>"  */
#line 770 "src/gwion.y"
                         { (yyval.exp) = new_prim_perform(mpool(arg), (yyvsp[0].sym), (yylsp[0])); }
#line 4012 "src/parser.c"
    break;

  case 319: /* prim_exp: "(" ")"  */
#line 771 "src/gwion.y"
                         { (yyval.exp) = new_prim_nil(    mpool(arg),     (yyloc)); }
#line 4018 "src/parser.c"
    break;


#line 4022 "src/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, arg, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, arg);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, arg);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, arg, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, arg);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, arg);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 773 "src/gwion.y"

#undef scan
ANN static int parser_error(loc_t *loc, Scanner *const scan, const char* diagnostic, const uint error_code) {
  char _main[strlen(diagnostic) + 1];
  strcpy(_main, diagnostic);
  char *_explain = strchr(_main, ','),
       *_fix = NULL;
  if(_explain) {
    _main[_explain - _main] = '\0';
    _explain += 2;
    _fix = strchr(_explain, ',');
    if(_fix) {
      _explain[_fix - _explain] = '\0';
      _fix += 2;
    }
  }
  scanner_error(scan, _main, _explain, _fix, *loc, error_code);
  return 0;
}
