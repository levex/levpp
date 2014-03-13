#include <stdio.h>
#include <levpp/syntax.h>

int check_markers(char *buf)
{
	int doubles = 0;
	int singles = 0;

	while (*buf++)
		if (*buf == '\'')
			singles ++;
		else if (*buf == '\"')
			doubles ++;

	if (doubles % 2) {
		syntax_error("Unclosed double apostrophe!\n");
		return 1;
	}
	if (singles % 2) {
		syntax_error("Unclosed single apostrophe!\n");
		return 1;
	}
}
