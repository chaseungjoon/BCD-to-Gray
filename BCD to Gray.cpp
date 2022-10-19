#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bcd_gray(int a, int b, int c, int d);
int main() {
	int b3, b2, b1, b0, b;
	while (true) {
		printf("Type BCD number : ");
		scanf("%d", &b);
		b3 = b / 1000;
		b2 = (b % 1000) / 100;
		b1 = (b % 100) / 10;
		b0 = b % 10;
		if ((b3 != 0 && b3 != 1) || (b2 != 0 && b2 != 1) || (b1 != 0 && b1 != 1) || (b0 != 0 && b0 != 1)) {
			printf("Wrong input, Type again.\n");
			continue;
		}
		else if (b > 1001) {
			printf("The corresponding Gray code does not exist. Type again.\n");
			continue;
		}
		else break;
	}
	printf("%04d\n", bcd_gray(b3, b2, b1, b0));
}

int bcd_gray(int a, int b, int c, int d) {
	int g = a * 1000 + (a | b) * 100 + ((a & b) | (b ^ c)) * 10 + (a & (b | c)) | (c ^ d);
	return g;
}