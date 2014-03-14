#include <stdio.h>
#include <stdlib.h>
#include <levpp/token.h>
#include <levpp/ast.h>

static ast_t *root = 0;

void set_root_ast(ast_t *ast)
{
	if (root)
		printf("WARNING: Overriding root AST!\n");

	ast->root = ast;
	ast->parent = 0;
	ast->token = new_token("ROOT", 0, TOKEN_TYPE_ROOT_ELEMENT);
	root = ast;
}

void add_to_ast(ast_t *parent, ast_t *child)
{
	/* if the parent has no child, we become their child */
	if (!parent->child) {
		//printf("AST: had no child, added directly\n");
		parent->child = child;
		return;
	}

	ast_t *looper = parent->child;
	while(looper->next)
		looper = looper->next;

	looper->next = child;
}

void __debug_dump_ast(ast_t *ast)
{
	if (!ast)
		return;
	token_print(ast->token);
	ast_t *sibling = ast->next;
	while(sibling) {
		printf(" ");
		token_print(sibling->token);
		sibling = sibling->next;
	}
	printf("\n");
	ast_t *child = ast->child;
	__debug_dump_ast(child);
	return;
}
