#include <stdio.h>
char input[5];

int sum_all()
{
	int sum = 0, i = 0;
	for (i = 0; input[i] != '\0'; i++) {
		if (input[i] < '0' || input[i] > '9') {
			printf("Invalid input!\n");
			sum = -1;
			break;
		}
		sum = sum*10 + input[i] - '0';
	}
	return sum;
}

int main()
{
	scanf("%s", input);
	int sum = sum_all();
	printf("input=%d\n", sum);
	return 0;
}