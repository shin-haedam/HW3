/*
���� �޴��� ǥ���ϰ� �� �޴��� ������ ���� �����Ѵ�.
��1. Random Square Matrix Generation�� ���� ��, �������(Square matrix)�� ��(�Ǵ� ��)�� ����(2~5)�� �Է� �޾�, 0~99 ���������� ����(Random number)�� �����Ͽ� �� ������� X, Y�� ����Ѵ�.
��2. Transpose�� ���� ��, X, Y�� ��ġ���(Transpose)�� ����Ѵ�.
��3. Rotation�� ���� ��, (0, 90, 180, 270, 360) �� ���ϴ� ������ �Է� �޾� X, Y�� ������(�ð����)���� �Է� ���� ������ŭ ȸ���� ����� ����Ѵ�.
��4. Inverse�� ���� ��, �� ��� X, Y�� �����(Inverse)�� ����Ѵ�. �̶�, ��Ľ�(Determinant)�� ���� �ʿ� ����. ������� �������� ���� ���� �� �޽����� ����Ѵ�. (��, ����� X is not invertible��)
��5. Calculation�� ���� ��, (��+��, ��-��, ��*��)�� ���ϴ� ������ �Է� �޾� �� ����� ����Ѵ�.
��6. Exit�� ���� ��, ���α׷��� �����Ѵ�.
�� �޴��� �ݵ�� �Լ� ���·� �����ؾ� �Ѵ�. Call by reference ���·� �迭�� �����ϰ� �����Ѵ�. 1�� �޴� ���� ���� �ٸ� �޴��� �������� ��, ����� �������� �ʴ´ٴ� error �޽����� ����ϰ� �Ѵ�. �Լ��� ������ ��Ȯ���� ����� Ȯ���Ѵ�.
*/
#include<stdio.h>
#include<stdlib.h>

void show_arr(int arr[][5], int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void RSM_gen(int X[][5], int Y[][5], int *n) {
	int i, j;
	void(*show_arr)(int, int) = show_arr;

	printf("Input the number of rows (2~5): ");
	scanf("%d", n);
	

	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			X[i][j] = rand() % 100;
		}
	}
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			Y[i][j] = rand() % 100;
		}
	}
	printf("X = \n");
	show_arr(X, *n);
	printf("Y = \n");
	show_arr(Y, *n);
	printf("\n");
}

void Transpose(int X[][5], int Y[][5], int *n) {
	int temp, i, j;
	void(*show_arr)(int**, int) = show_arr;

	if (X[0][0] < 0) {
		puts("Error: Random square matrix not ready\n");
		return;
	}

	for (i = 0; i < *n - 1; i++) {
		for (j = *n - 1; j > i; j--) {
			temp = X[i][j];
			X[i][j] = X[j][i];
			X[j][i] = temp;
		}
	}
	for (i = 0; i < *n - 1; i++) {
		for (j = *n - 1; j > i; j--) {
			temp = Y[i][j];
			Y[i][j] = Y[j][i];
			Y[j][i] = temp;
		}
	}

	printf("X = \n");
	show_arr(X, *n);
	printf("Y = \n");
	show_arr(Y, *n);
	printf("\n");
}

int main() {
	int c, n;
	int X[5][5] = { -1 } , Y[5][5] = { 0 };
	
	while (1) {
		printf("--Menu--\n");
		printf("1. Random Square Matrix Generation\n");
		printf("2. Transpose\n");
		printf("4. Inverse\n");
		printf("5. Calculation\n");
		printf("6. Exit\n");
		printf("Choose the item you want: ");
		scanf("%d", &c);

		if (c == 1) {
			RSM_gen(X, Y, &n);
		}
		else if (c == 2) {
			Transpose(X, Y, &n);
		}
		else if (c == 3) {

		}
		else if (c == 4) {

		}
		else if (c == 5) {

		}
		else if (c == 6) {
			printf("Exit\n");
			break;
		}
		else;
	}
}