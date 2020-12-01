/** @file: cpy_ast.h
@brief copy ast nodes
*/

#ifndef __CPY_AST
#define __CPY_AST
ANN Exp cpy_exp(MemPool, Exp);
ANN Array_Sub cpy_array_sub(MemPool, Array_Sub);
ANN Type_Decl* cpy_type_decl(MemPool, const Type_Decl*);
ANN Type_List cpy_type_list(MemPool, const Type_List);
ANN Func_Def cpy_func_def(MemPool, const Func_Def);
ANN Func_Def cpy_func_def(MemPool, Func_Def);
ANN struct Func_Base_* cpy_func_base(MemPool, const struct Func_Base_*);
ANN Class_Def cpy_class_def(MemPool, Class_Def);
ANN Union_Def cpy_union_def(MemPool, Union_Def);
ANN Type_List cpy_type_list(MemPool p, const Type_List src);
ANN Decl_List cpy_decl_list(MemPool p, const Decl_List src);
ANN ID_List cpy_id_list(MemPool p, const ID_List src);
ANN Tmpl* cpy_tmpl(MemPool p, const Tmpl *src);
ANN Ast   cpy_ast(MemPool p, const Ast ast);
#endif
