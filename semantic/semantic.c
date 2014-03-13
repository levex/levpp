#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <levpp/ast.h>

char *__read_line(char *buf, char **b)
{
	int c = 0;
	char *ret = 0;
	while (*buf != '\n') {
		buf ++;
		c ++;
	}

	if (!c)
		return 0;

	ret = malloc(sizeof(char) * c);
	if (!ret)
		return 0;

	memcpy(ret, *b, c + 1);
	*b += c + 1;
	return ret;
}

void parse_line(char *line, ast_t *ast)
{
	printf("Parsing line: %s", line);
}

void semantic_analyze(char *__buf)
{
	char *line = 0;
	int len = strlen(__buf);
	char *__start = __buf;

	printf("Creating an AST for file\n");
	ast_t *ast = malloc(sizeof(ast_t));
	memset(ast, 0, sizeof(ast_t));

	do {
		line = __read_line(__buf, &__buf);
		if (!line)
			break;
		if (__buf > __start + len)
			break;
		parse_line(line, ast);
		free(line);
	} while (1);
}
