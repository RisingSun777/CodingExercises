#include "filemanip.h"
#include "expression.h"

int main() {
	char* expression = getEquationFromFile(NULL);
	puts(expression);
	
	char* converted = convertToReversedPolish(expression);
	puts(converted);
	
	return 0;
}