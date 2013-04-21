#include "filemanip.h"

char* getEquationFromFile(char* location) {
	if(location == NULL)
		location = "./input.txt";
	FILE* file = fopen(location, "rt"); //read-text mode, distinguish from read-binary mode

	char* expression = new char;
	strcpy(expression, "");
	char* test_char = new char;
	while(!feof(file)) {
		fscanf(file, "%s", test_char);
		strcat(expression, test_char);
	}

	fclose(file);
	return expression;
}