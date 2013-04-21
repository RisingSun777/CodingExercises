#include "expression.h"

void popStackToResult(char* result, stack<char*> &stack) {
	if(stack.empty())
		return;

	switch(*stack.top()) {
	case '-':
		strcat(result, "->");
		break;
	case '<':
		strcat(result, "<->");
		break;
	default:
		strncat(result, stack.top(), 1);
		break;
	}
	stack.pop();
}

void pushCharToStack(char* const position, stack<char*> &stack) {
	char* a = new char[5];
	strcpy(a, "");

	strncat(a, position, 1);
	stack.push(a);
}

char* convertToReversedPolish(char* expression) {
	if(!isValidExpression(expression))
		return NULL;

	stack<char*> operators_stack;
	char* converted = new char[getReversedPolishExpressionSize(expression)];
	strcpy(converted, "");

	for(char* i = expression; *i; i++) {
		//ignore multi-chars operators' 2nd char onwards
		if(*i == '>' || (*i == '-' && *(i - 1) == '<'))
			continue;

		int code = getCodeName(i);

		if(code == 0) {
			strncat(converted, i, 1);
			continue;
		}
		if(code == 6) {
			pushCharToStack(i, operators_stack);
			continue;
		}
		if(code == 7) {
			while(*operators_stack.top() != '(') {
				popStackToResult(converted, operators_stack);
			}
			//pop the '(' char
			operators_stack.pop();
			continue;
		}
		if(operators_stack.empty()) {
			pushCharToStack(i, operators_stack);
			continue;
		}
		else if(*operators_stack.top() != '(')
			popStackToResult(converted, operators_stack);

		pushCharToStack(i, operators_stack);
	}

	while(!operators_stack.empty())
		popStackToResult(converted, operators_stack);
	
	return converted;
}