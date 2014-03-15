#include <stdio.h>
#include <stdlib.h>
#include <levpp/ast.h>

token_t *new_token(char *name, void *data, int type)
{
	token_t *ret = malloc(sizeof(*ret));
	ret->name = name;
	ret->data = data;
	ret->type = type;
	return ret;
}

char *token_stringize_type(int type)
{
	if (type == TOKEN_TYPE_VARIABLE)
		return "variable";
		
	if (type == TOKEN_TYPE_FUNCTION_CALL)
		return "function call";
		
	return "<null>";
}

void token_print(token_t *token)
{
	if (!token)
		return;
	printf("[%s (type: %s)]", token->name, token_stringize_type(token->type));
}
