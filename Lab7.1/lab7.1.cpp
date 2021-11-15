#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** T, const int r, const int c) {
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			T[i][j] = -42 + rand() * 94 / RAND_MAX;
}

void Print(int** T, const int r, const int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			cout << setw(4) << T[i][j];
		}
		cout << endl;
	}
	cout << endl;
}



void Sort1(int** T, const int r, const int c) {

	//–озташуванн€ елемент≥в першого стовпчика за зростанн€м
	for (int i = 0; i < r - 1; i++) {
		int min = T[i][c];
		int imin = i;
		for (int j = i + 1; j < r; j++)
			if (min > T[j][c]) {
				min = T[j][c];
				imin = j;
			}
		swap(T[imin], T[i]);
	}
}

void Sort2(int** T, const int r, const int c) {
	/*якщо у першому стовпчику на€вн≥ однаков≥ елементи,
	 переставл€ютьс€ р€дки, щоб елементи другого стовпчика спадали*/
	for (int i = 0; i < r - 1; i++)
		for (int j = i + 1; j < r; j++)
			if (T[i][0] == T[j][0]) {
				for (int i = 0; i < r - 1; i++) {
					int max = T[i][c];
					int imax = i;
					for (int j = i + 1; j < r; j++)
						if (max < T[j][c]) {
							max = T[j][c];
							imax = j;
						}
					swap(T[imax], T[i]);

				}
			}
}

void Sort3(int** T, const int r, const int c) {
	/*якщо у першому ≥ другому стовпчику на€вн≥ однаков≥ елементи,
	 переставл€ютьс€ р€дки, щоб елементи третього стовпчика зростали*/
	for (int i = 0; i < r - 1; i++)
		for (int j = i + 1; j < r; j++)
			if (T[i][0] == T[j][0] || T[i][1] == T[j][1] || T[i][0] == T[j][1] || T[i][1] == T[j][0]) {
				for (int i = 0; i < r - 1; i++) {
					int min = T[i][c];
					int imin = i;
					for (int j = i + 1; j < r; j++)
						if (min > T[j][c]) {
							min = T[j][c];
							imin = j;
						}
					swap(T[imin], T[i]);
				}
			}
}

int Amount(int** T, const int r, const int c) {
	int am = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			if (T[i][j] < 0 || (T[i][j] % 5 != 0 && T[i][j] >= 0))
				am++;
		}
	}
	return am;
}

int Sum(int** T, const int r, const int c) {
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			if (T[i][j] < 0 || (T[i][j] % 5 != 0 && T[i][j] >= 0))
				s += T[i][j];
		}
	}
	return s;
}

void Zero(int** T, const int r, const int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			if (T[i][j] < 0 || (T[i][j] % 5 != 0 && T[i][j] >= 0))
				 T[i][j] = 0;
		}
	}
}


int main() {
	srand((unsigned)time(NULL));

	const int r = 7, c = 6;
	int** T = new int* [r];
	for (int i = 0; i < r; i++)
		T[i] = new int[c];

	cout << "Start array: " << endl;
	Create(T, r, c);
	Print(T, r, c);
	cout << "Array after Sort1: " << endl;
	Sort1(T, r, 0);
	Print(T, r, c);
	cout << "Array after Sort2: " << endl;
	Sort2(T, r, 1);
	Print(T, r, c);
	cout << "Array after Sort3: " << endl;
	Sort3(T, r, 2);
	Print(T, r, c);
	cout << endl;
	cout << "Amount = " << Amount(T, r, c) << endl;
	cout << "Sum = " << Sum(T, r, c) << endl;
	cout << endl;
	cout << "Replacing relevant elements with 0: " << endl;
	Zero(T, r, c);
	Print(T, r, c);

	for (int i = 0; i < r; i++)
		delete[] T[i];
	delete[] T;

	return 0;
}