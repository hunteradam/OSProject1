#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

struct Line {
   char  *line;
   struct Line* back;
};

int main(int argc, char *argv[])
{

	if (argc == 3) {
		
		if (!strcmp(argv[1], argv[2])) {
			fprintf(stderr, "error: input and output file must differ\n");
			return 1;
		}
		FILE* inputFile;
		inputFile = fopen(argv[1], "r");
		if (inputFile == NULL) {
			fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
			return 1;
		}
		struct Line *current = NULL;
		char *line = (char*) malloc(12*sizeof(char));
		int newCount = 0;
		while (fgets(line, sizeof(line), inputFile)) {
			
			struct Line* lineS = (struct Line*) malloc(sizeof(struct Line));
			lineS->line = line;
			lineS->back = current;
			current = lineS;
			newCount = newCount + 1;
			line = (char*) malloc(12*sizeof(char));
		} 
		fclose(inputFile);
		FILE* outputFile;
		outputFile = fopen(argv[2], "w");
		if (outputFile == NULL) {
			fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
			return 1;
		}

		while (current != NULL){
			struct Line* back = current->back;
			fprintf(outputFile, "%s", current->line);
			free(current->line);
			free(current);
			current = back;
			
		}
		free(line);
		fclose(outputFile);
		
	}
	else if (argc > 3) {
		fprintf(stderr, "usage: reverse <input> <output>\n");
		return 1;
	}
	else if (argc == 2) {
		FILE* inputFile;
		inputFile = fopen(argv[1], "r");
		if (inputFile == NULL) {
			fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
			return 1;
		}
		struct Line *current = NULL;
		char *line = (char*) malloc(12*sizeof(char));
		int newCount = 0;
		while (fgets(line, sizeof(line), inputFile)) {
			
			struct Line* lineS = (struct Line*) malloc(sizeof(struct Line));
			lineS->line = line;
			lineS->back = current;
			current = lineS;
			newCount = newCount + 1;
			line = (char*) malloc(12*sizeof(char));
		} 
		
		
		while (current != NULL){
			struct Line* back = current->back;
			printf(" %s", current->line);
			free(current->line);
			free(current);
			current = back;
			
		}
		free(line);
		fclose(inputFile);
	}
	

	return 0;
}

