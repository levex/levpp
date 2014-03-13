#ifndef __LEVPP_AST_H_
#define __LEVPP_AST_H_


#define TOKEN_TYPE_VARIABLE_SPEC 1
#define TOKEN_TYPE_VARIABLE_NAME 2
#define TOKEN_TYPE_LITERAL 3

typedef struct ___token_t {
	char *data;
	int type;
} token_t;

struct ___ast_t;

typedef struct ___ast_t {
	/* list of tokens that make up this element */
	token_t *token_list;
	/* the document (or the root AST) */
	struct ___ast_t *root;
	/* the parent of this AST */
	struct ___ast_t *parent;
	/* the child of this AST (if any) */
	struct ___ast_t *child;
	/* an AST in the same level, with the same parent */
	struct ___ast_t *next;
} ast_t;

#endif
