#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


void print_help()
{
	printf("LevPP - A compiler for the Lev++ programming language\n");
	printf("Syntax: levpp [--help] file\n");
	return;
}

int process_file(char *filename)
{
	struct stat st;
	stat(filename, &st);
	if (!st.st_size)
		return 1;
	
	uint8_t *file_buf = (uint8_t *)malloc(st.st_size);
	if (!file_buf)
		return 1;

	FILE *fp = fopen(filename, "r");
	if (!fp) {
		free(file_buf);
		return 1;
	}

	size_t len = fread(file_buf, sizeof(char), st.st_size, fp);
	if (!len) {
		printf("%s couldn't be read.\n", filename);
		free(file_buf);
		return 1;
	}

	syntax_check(file_buf);
	semantic_analyze(file_buf);
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
	
	return process_file(argv[1]);
}
