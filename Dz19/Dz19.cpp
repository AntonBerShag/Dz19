#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <typename T> void showArray(T arr[], int l);
int nod(int num1, int num2);
int resurveNumber(int num1);
template <typename T> T back(T arr[], int length, int N);
template <typename T> void full(T arr[], int length, int N, int M);


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	srand(time(NULL));

	//������ 1
	cout << "������ 1\n������� 2 �����: ";
	cin >> n >> m;
	cout << "��� = " << nod(n, m) << "\n\n";
	
	//������ 2
	cout << "������ 2\n������� �����: ";
	cin >> n;
	cout << "����� ��������: " << resurveNumber(n) << "\n\n";

	//������ 3
	/*cout << "������ 3\n";
	int arr1[10] = { 4, 0, -2, 10, -10, 20, 6, 56, -32, -34 };
	showArray(arr1, 10);
	cout << "������� �����: ";
	cin >> n;
	cout << back(arr1, 10, n) << "\n\n";*/

	//������ 4
	int arr2[50];
	cout << "������ 4\n������� ������ ���������(�� 0 �� 49): ";
	cin >> n;
	cout << "������� ����� ���������(�� 0 �� 49): ";
	cin >> m;
	full(arr2, 50, n, m);

	return 0;
}

//������ 4
template <typename T> void full(T arr[], int length, int N, int M) {
	cout << "�������� ������:\n[";
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
		for (int j = N; j < M; j++) {
			arr[j] = rand() % 50 + 1;
		}
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
}
//������ 3
template <typename T> T back(T arr[], int length, int N) {
	cout << "�������� ������:\n[";
	for (int i = 0; i < length; i++) {
		for (int j = N; j < length; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = arr[j];
			}
		}
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
	cout << "N = ";
	return N;
}
//������ 2
int resurveNumber(int num) {
	int reverse = 0, lastN;
	if (num / 10 == 0)
		return num;
	while (num > 0) {
		lastN = num % 10;
		reverse = reverse * 10 + lastN;
		num /= 10;
	}
	return reverse;
}
//������ 1
int nod(int num1, int num2) {
	if (num1 == num2) {
		return num1;
	}
	if (num1 > num2) {
		int a = num1;
		num1 = num2;
		num2 = a;
	}
	return nod(num1, num2 - num1);
}
//�������� ������
template <typename T> void showArray(T arr[], int l) {
	cout << "�������� ������:\n[";
	for (int i = 0; i < l; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}