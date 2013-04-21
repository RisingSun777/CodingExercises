#include "expression.h"

//Return code name of a character, according to the priority.
int getCodeName(char* const character) {
	switch(*character) {
	case '~':
		return 1;
		break;
	case '^':
		return 2;
		break;
	case 'v':
		return 3;
		break;
	case '-':
		return 4;
		break;
	case '<':
		return 5;
		break;
	case '(':
		return 6;
		break;
	case ')':
		return 7;
		break;
	default:
		return 0;
		break;
	}
}