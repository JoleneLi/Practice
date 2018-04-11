#include <stdio.h>
#include <string.h>

int push(char * b, int top, char elem) {
	b[++top] = elem;
	return top;
}


int main() {
	char a[100];
	char b[60];
	int top = -1;
	
	printf("Input the parentheses:");
	scanf("%s", a);
	int k = (int)strlen(a);
	
	for (int i = 0; i < k; i++) {
		if (a[i] == '{') {
			top = push(b, top, '}');
		}
		else if (a[i] == '(') {
			top = push(b, top, ')');
		}
		else if (a[i] == '}' || a[i] == ')') {
			if (b[top] == a[i]) {
				top--;
			}
			else {
				printf("the parentheses do not match.");
				return 0;
			}
		}
	}
	if (top != -1) {
		printf("the parentheses do not match.");
	}
	else {
		printf("The parentheses match.");
	}

	return 0;

}