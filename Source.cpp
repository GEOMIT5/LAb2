#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class Matrix {
	int** mas;
	int a, b;
	
public:
	void fillMatrix();
	void MaxAndMinElements();
	void StrOfMatrix();
	void printMatrix() const;
	
	Matrix(int A, int B);
	~Matrix();
};
Matrix::Matrix(int A, int B) {
	a = A; b = B;
	mas = new int* [a];
	for (int i = 0; i < a; i++)
		mas[i] = new int[b];
	
}
Matrix::~Matrix() {
	for (int i = 0; i < a; i++)
		delete[]mas[i];
	delete[]mas;
}
void Matrix::printMatrix() const {
	system("cls");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	system("pause");
	system("cls");
}
void Matrix::fillMatrix() {
	int l = 0, r = 0;
	int key1;
	cout << "�������� �������:" << endl;
	cout << "1.��������� ����� \n 2.����� � ����������" << endl;
	cin >> key1;
	switch (key1)
	{
	case 1:
		system("cls");
		cout << "������� ����� ������� ���������: ";
		
		cin >> l;
		cout << "������� ������ ������� ���������: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				mas[i][j] = rand() % (r - l + 1) + l;
		break;
	case 2:
		cout << "������� �����: " << endl;
		for (int i = 0; i < a; i++) {
			cout << i + 1 << " - ������ �� " << b << " ��������: ";
			for (int j = 0; j < b; j++)
				cin >> mas[i][j];
			
		}
		break;
	default:
		break;
	}
	
	
}
void Matrix::MaxAndMinElements() {
	int min = mas[0][0], max = mas[0][0];
	int mini = 0, minj = 0, maxi = 0, maxj = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
				maxi = i;
				maxj = j;
			}
			if (mas[i][j] < min) {
				min = mas[i][j];
				mini = i;
				minj = j;
			}
		}
	int swap = 0;
	swap = mas[maxi][maxj];
	mas[maxi][maxj] = mas[mini][minj];
	mas[mini][minj] = swap;
}
void Matrix::StrOfMatrix() {
	int change = 0;
	for (int i = 0; i < a - 1; i = i + 2)
		for (int j = 0; j < b; j++) {
			change = mas[i][j];
			mas[i][j] = mas[i + 1][j];
			mas[i + 1][j] = change;
		}
}
int main()
{
	setlocale(0, "rus");
	int a = 0, b = 0;
	int key;
	cout << "������� ������� �������: " << endl;
	cout << "������ ������ ";
	cin >> a;
	cout << "������ ������ ";
	cin >> b;
	system("cls");
	Matrix Array(a, b);
	
	
	while (true) {
		cout << "�������� �������:" << endl;
		cout << "1.��������� ������� \n 2.�������� ������� \n 3.�������� ������� ������������ � ����������� �������� ������� \n 4.�������� ������� ������ ������� \n 5.��������� ������  " << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			Array.fillMatrix();
			system("cls");
			break;
		case 2:
			
			Array.printMatrix();
			system("cls");
			break;

		
		case 3:
			Array.MaxAndMinElements();
			cout << "��������� ��������� ���� ������������� � ������������ ��������� " << endl;
			
			
			break;
		case 4:
			Array.StrOfMatrix();
			cout << "��������� ��������� ���� ����� �������" << endl;
			
			
			break;
		case 5:
			
			return 0;
		default:
			return 0;
			
		}
		
		
	}
	return 0;
}


