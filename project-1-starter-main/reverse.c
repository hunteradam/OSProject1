#include <stdio.h>
#include <string.h>
struct Reverse {
	char reverse;
};

int main(int argc, char *argv[])
{
  	// char *line = NULL;
  	// size_t len = 0;
  	// size_t lineSize = 0;
  	// lineSize = getline(&line, &len, stdin);
  	
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
		char ch;
		ch = fgetc(inputFile);
		int count = 0;
		for (char i = getc(inputFile); i != EOF; i = getc(inputFile)) {
			if (i == '\n'){
				count = count + 1;
			}
		}
		printf("%d", count);
		rewind(inputFile);
		char outputFile[count];
		int newCount = 0;
		ch = fgetc(inputFile);
		while (ch != EOF) {
			ch = fgetc(inputFile);
			outputFile[newCount] = ch;
			newCount = newCount + 1;
		} 
		printf("%d", newCount);
		for (int j = newCount - 1; j >= 0; j--) {
			printf("%c", outputFile[j]);
		}
		fclose(inputFile);
		struct name asdtg
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
		char ch;
		ch = fgetc(inputFile);
		printf("%c", ch);
		while (ch != EOF) {
			ch = fgetc(inputFile);
			printf("%c", ch);
		} 
		fclose(inputFile);
	}
	

	return 0;
}

