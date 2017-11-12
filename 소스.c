/*
먼저 메뉴를 표시하고 각 메뉴는 다음과 같이 동작한다.
“1. Random Square Matrix Generation” 선택 시, 정방행렬(Square matrix)의 행(또는 열)의 길이(2~5)를 입력 받아, 0~99 범위내에서 난수(Random number)를 생성하여 두 정방행렬 X, Y를 출력한다.
“2. Transpose” 선택 시, X, Y의 전치행렬(Transpose)를 출력한다.
“3. Rotation” 선택 시, (0, 90, 180, 270, 360) 중 원하는 각도를 입력 받아 X, Y를 오른쪽(시계방향)으로 입력 받은 각도만큼 회전한 행렬을 출력한다.
“4. Inverse” 선택 시, 각 행렬 X, Y의 역행렬(Inverse)를 출력한다. 이때, 행렬식(Determinant)을 구할 필요 있음. 역행렬이 존재하지 않을 때는 그 메시지를 출력한다. (예, “행렬 X is not invertible”)
“5. Calculation” 선택 시, (‘+’, ‘-’, ‘*’)중 원하는 연산을 입력 받아 그 결과를 출력한다.
“6. Exit” 선택 시, 프로그램을 종료한다.
각 메뉴는 반드시 함수 형태로 구현해야 한다. Call by reference 형태로 배열을 전달하고 접근한다. 1번 메뉴 선택 전에 다른 메뉴를 선택했을 시, 행렬이 존재하지 않는다는 error 메시지를 출력하게 한다. 함수의 연산은 정확한지 계산기로 확인한다.
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