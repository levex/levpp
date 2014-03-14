#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <levpp/ast.h>
#include <levpp/token.h>

ast_t *construct_variable_ast(char *type, char *name, char *value)
{
	ast_t *ret = malloc(sizeof(*ret));
	char *qualifier = strdup(type);
	strcat(qualifier, " ");
	strcat(qualifier, name);
	token_t *tok = new_token(qualifier, value, TOKEN_TYPE_VARIABLE);
	ret->token = tok;
	return ret;
}

/* 
 * Variable syntax:
 * <type> <name> = <value>;
 * Only one per line allowed!
 * 
 */

int try_parse_variable(char *line_nomod, ast_t *ast)
{
	char *line = strdup(line_nomod);
	char *var_type = 0;
	char *var_name = 0;
	char *var_value = 0;
	
	char *tok = strtok(line, " ");
	while (tok) {
		if (!var_type) {
			var_type = tok;
			goto cont;
		}
		if (!var_name) {
			var_name = tok;
			goto cont;
		}
		if (!var_value && strncmp(tok, "=", 1)) {
			var_value = tok;
			var_value[strlen(tok) - 2] = 0;
			goto cont;
		}
cont:
		tok = strtok(NULL, " ");
	}
	
	ast_t *variable = construct_variable_ast(var_type, var_name, var_value);
	add_to_ast(ast, variable);
}
