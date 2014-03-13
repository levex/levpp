#include <stdio.h>
#include <stdint.h>
#include <levpp/syntax.h>

void syntax_error(char *str)
{
	printf("Syntax error: %s", str);
	return;
}

int syntax_check(char *buf)
{
	int rc = check_braces(buf);
	if (rc)
		return rc;

	rc = check_markers(buf);

	return rc;

}
