#include <iostream>

using namespace std;

struct book {
	char title[10];
};

void task1() {
	int i, n;
	char **arr;

	cout << "size: ";
	cin >> n;

	arr = (char**)malloc(n * sizeof(char*));
	if (!arr) {
		cout << "Error" << endl;
	}

	cout << "Enter array: " << endl;

	for (i = 0; i < n; i++){
		*(arr + i) = (char*)malloc(n * sizeof(char));
		cin >> arr[i];
	}
	cout << endl << "array: " << endl;
	for (i = 0; i < n; i++)
		cout << ' ' << arr[i];
	cout << endl;
	free(arr);
	system("pause");
}

void task2() {
	system("cls");
	int i, n;
	
	book *arr;

	cout << "size: ";
	cin >> n;
	
	arr = (book*)malloc(n * sizeof(book)); 
	
	if (!arr) {
		cout << "Error" << endl;
	}
	
	cout << "Enter struct:" << endl;
	
	for (i = 0; i < n; i++) {
		cin >> arr[i].title;
	}
	
	cout << endl << "array: " << endl;
	
	for (i = 0; i < n; i++)
		cout << ' ' << arr[i].title<<endl;      
	
	cout << endl;
	free(arr);
	system("pause");
}

void task3() {
	int i, n;
	book** arr;
	
	system("cls");

	cout << "size: ";
	cin >> n;
	
	arr = (book**)malloc(n * sizeof(book*));
	
	if (!arr) {
		cout << "Error" << endl;
	}
	
	cout << "Enter struct: " << endl;

	for (int j = 0; j < n; j++) {
		*(arr + j) = (book*)malloc(n * sizeof(book));
		for (i = 0; i < n; i++) {
			cin >> arr[j][i].title;
		}
	}
	
	cout << endl << "array: " << endl;

	for (int j = 0; j < n; j++)
		for (i = 0; i < n; i++)
			cout << ' ' << arr[j][i].title << endl;
	
	free(arr);
}

int main() {
	int k = 0;
	while (k != 4)
	{
		setlocale(LC_ALL, "ru");
		cout << "1 задание" << endl;
		cout << "2 задание" << endl;
		cout << "3 задание" << endl;
		cout << "4 выход" << endl;
		cin >> k;
		switch (k)
		{
		case 1:task1(); break;
		case 2:task2(); break;
		case 3:task3(); break;
		case 4:break;
		}
	}
	return 0;
}

