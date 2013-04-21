#include "filemanip.h"
#include "expression.h"
#include <conio.h>

int main() {
	char* expression = getEquationFromFile(NULL);
	puts(expression);
	
	char* converted = convertToReversedPolish(expression);
	puts(converted);

	delete[] converted;

	return 0;
}