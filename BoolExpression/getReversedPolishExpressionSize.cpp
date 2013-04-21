#include "expression.h"

int getReversedPolishExpressionSize(char* expression) {
	int count = 0;
	for(char* i = expression; *i != '\0'; i++)
		if(getCodeName(i) != 6 && getCodeName(i) != 7)
			count++;
	return count;
}