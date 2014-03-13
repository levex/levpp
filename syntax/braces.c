#include <stdio.h>
#include <stdint.h>
#include <levpp/syntax.h>

int check_braces(char *buf)
{
	int open_squared = 0;
	int open_circ = 0;
	int open_curl = 0;
	
	while(*buf++) {
		if (*buf == '[')
			open_squared ++;
		else if (*buf == '(')
			open_circ ++;
		else if (*buf == '{')
			open_curl ++;
		
		if (*buf == ']')
			open_squared --;
		else if (*buf == ')')
			open_circ --;
		else if (*buf == '}')
			open_curl --;
	}

	if (open_squared)
		syntax_error("Missing squared brackets!\n");
	if (open_circ)
		syntax_error("Missing parantheses!\n");
	if (open_curl)
		syntax_error("Missing curly brackets!\n");
	
	return open_squared + open_circ + open_curl;
}
