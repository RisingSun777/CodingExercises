#include "expression.h"

bool checkForValidMultiCharOperator(char* const position) {
	if(getCodeName(position) == 4 && *(position + 1) != '>') {
		printf("Invalid operator: -> cannot be found.\n");
		return false;
	}
	if(getCodeName(position) == 5 && *(position + 1) != '-' && *(position + 1) != '>') {
		printf("Invalid operator: <-> cannot be found.\n");
		return false;
	}
	return true;
}

bool checkForValidBrackets(char* const expression) {
	int count = 0;

	for(char* i = expression; *i; i++) {
		if(getCodeName(i) == 6)
			count++;
		if(getCodeName(i) == 7)
			count--;
		if(count < 0) {
			printf("Invalid brackets: The brackets' orders are invalid.\n");
			return false;
		}
	}
	if(count != 0) {
		printf("Invalid brackets: The brackets' orders are invalid.\n");
		return false;
	}

	return true;
}

bool checkForOverlap(char* const position) {
	if(*(position + 1) == '\0')
		return true;

	switch(getCodeName(position)) {
	case 1:
		if(getCodeName(position + 1) <= 5 && getCodeName(position + 1) > 0) {
			printf("Invalid expression: Overlapped.\n");
			return false;
		}
		break;
	case 2:
		if(getCodeName(position + 1) <= 5 && getCodeName(position + 1) > 0) {
			printf("Invalid expression: Overlapped.\n");
			return false;
		}
		break;
	case 3:
		if(getCodeName(position + 1) <= 5 && getCodeName(position + 1) > 0) {
			printf("Invalid expression: Overlapped.\n");
			return false;
		}
		break;
	case 4:
		if(getCodeName(position + 2) <= 5 && getCodeName(position + 2) > 0) {
			printf("Invalid expression: The operator -> has been overlapped.\n");
			return false;
		}
		break;
	case 5:
		if(getCodeName(position + 3) <= 5 && getCodeName(position + 3) > 0) {
			printf("Invalid expression: The operator <-> has been overlapped.\n");
			return false;
		}
		break;
	case 6:
		return true;
		break;
	case 7:
		return true;
		break;
	default:
		if(getCodeName(position) == getCodeName(position + 1)) {
			printf("Invalid expression: The variables must be a single character.\n");
			return false;
		}
		break;
	}

	return true;
}

bool isValidExpression(char* expression) {
	if(!checkForValidBrackets(expression))
		return false;

	for(char* i = expression; *i; i++) {
		//ignore multi-chars operators' 2nd char onwards
		if(*i == '>' || (*i == '-' && *(i - 1) == '<'))
			continue;
		if(!checkForValidMultiCharOperator(i) || !checkForOverlap(i))
			return false;
	}

	return true;
}