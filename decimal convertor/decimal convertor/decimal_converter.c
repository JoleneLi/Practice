#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int push(char * a, int top, char elem) {
	a[++top] = elem;
	return top;
}

int convertASCtoNum(char a) {
	if (a >= '0'&& a <= '9') {
		return (a - '0');
	}
	else if (a >= 65 && a <= 90) {
		return(a - 55);
	}
	else {
		return -1;
	}
}

char convertNumToAcs(int n) {
	if (n < 10) {
		char symbol = n + 48;
		return symbol;
	}
	if (n >= 10) {
		char symbol = n + 55;
		return symbol;
	}
}


int convertToDecimal(char * a, int top, int old) {
	int symbol = 0;
	int i = 0;
	int sum = 0;
	while(top != -1){
		symbol = convertASCtoNum(a[top]);
		sum += symbol * pow(old, i);
		i++;
		top--;
	}
	return sum;
}

int convertToNew(int sum, char * b, int new) {
	int top = -1;
	int n;
	char temp;
	int quotient = sum;
	while((quotient / new) != 0) {
		n = quotient % new;
		quotient = quotient / new;
		temp = convertNumToAcs(n);
		top = push(b, top, temp);
	}
	n = quotient % new;
	temp = convertNumToAcs(n);
	top = push(b, top, temp);
	return top;
}


int main() {
	char a[100];
	char b[100];
	int top1 = -1, top2 = -1;
	char input[100] = { 0 };
	int sum = 0;
	int old;
	int new;
	printf("Input number, original decimal, new decimal:");
	scanf("%s %d %d", input, &old, &new);

	int i = 0;
	while (input[i] != NULL) {
		top1 = push(a, top1, input[i]);
		i++;
	}
	sum = convertToDecimal(a, top1, old);
	printf("The decimal version of the number is: %d\n", sum);

	top2 = convertToNew(sum, b, new);
	printf("The new decimal version of the number is:\n");
	while (top2 != -1) {
		printf("%c", b[top2]);
		top2--;
	}
	return 0;
}