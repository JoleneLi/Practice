#include <stdio.h>
#include <stdlib.h>

int push(char * a, int top, char elem) {
	a[++top] = elem;
	return top;
}



convert(char * a, int top, int d, int nd) {
	int numberd = 0;
	int i = 1;
	while (top != -1) {
		int coeff = 1;
		int numberd = a[top] * coeff;
		top--;
		while (top != -1) {
			coeff = coeff * d;
			numberd += a[top] * coeff
		}
	}



}

int ASCconvert(char a) {
	if (a > '0'&& a < '9') {
		return (a - '0');
	}
	if (a)
}

int main() {
	int d = 10, nd = 10;
	char a[100];
	int top = -1;
	char input[100] = { 0 };
	scanf("Input number, original decimal, new decimal:%s %d %d", input, &d, &nd);

	int i = 0;
	while (input[i] != NULL) {
		top = push(a, top, input[i]);
	}


}