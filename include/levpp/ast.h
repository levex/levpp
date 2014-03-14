#ifndef __LEVPP_AST_H_
#define __LEVPP_AST_H_


#define TOKEN_TYPE_VARIABLE 1
#define TOKEN_TYPE_ROOT_ELEMENT 2

typedef struct ___token_t {
	char *name;
	void *data;
	int type;
} token_t;

struct ___ast_t;

typedef struct ___ast_t {
	/* the token that makes up this element */
	token_t *token;
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
