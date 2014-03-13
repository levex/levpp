#include <stdio.h>

void print_help()
{
	printf("LevPP - A compiler for the Lev++ programming language\n");
	printf("Syntax: levpp [--help] file\n");
	return;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		print_help();
		return 0;
	}
	
	if (!strcmp(argv[1], "--help") ||
		!strcmp(argv[1], "-h") ||
		!strcmp(argv[1], "-?")) {
		print_help();
		return 0;
	}

	return 0;
}
