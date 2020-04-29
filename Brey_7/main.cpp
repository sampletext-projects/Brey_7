#include <iostream>

using namespace std;

void read_mas(int* mas, int size)
{
	cout << "mas: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void write_mas(int* mas, int size)
{
	cout << "mas: ";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

int count_in_range(int* mas, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (abs(mas[i]) >= 2 && abs(mas[i]) <= 5)
		{
			count++;
		}
	}
	return count;
}

int sum_not_in_range(int* mas, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(abs(mas[i]) >= 2 && abs(mas[i]) <= 5))
		{
			sum += mas[i];
		}
	}
	return sum;
}

bool is_sorted_ascending(int* mas, int size)
{
	bool result = true;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] < mas[i - 1])
		{
			result = false;
			break;
		}
	}
	return result;
}

void insert(int** mas, int& size, int element)
{
	int index = 0;
	int* src = *mas; //исходный массив
	int* dest = new int[size + 1]; //новый массив
	while (src[index] <= element && index < size)
	{
		dest[index] = src[index];
		index++; //переписываем все элементы до нужного
	}
	dest[index] = element; //записываем новый элемент
	index++;
	for (; index <= size; index++)
	{
		dest[index] = src[index - 1]; //переписываем все элементы после нужного
	}
	*mas = dest;//перезаписываем массив
	size++;//увеличиваем размер
}

void print_menu()
{
	cout << "1. Ввод массива" << endl;
	cout << "2. Вывод массива" << endl;
	cout << "3. Найти количество элементов в интервале [-5; -2] и [2; 5]" << endl;
	cout << "4. Найти сумму элементов НЕ в интервале [-5; -2] и [2; 5]" << endl;
	cout << "5. Проверить, является ли упорядоченным по возрастанию" << endl;
	cout << "6. Вставить элемент" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Белевцева Дарья Юрьевна студент группы УМЛ-112" << endl;
	cout << "Программа по манипулированию массивом с помощью функций" << endl;
	int size = -1;
	int* mas = 0;


	int t;
	do
	{
		print_menu();
		cin >> t;
		switch (t)
		{
		case 1:
			{
				cout << "Введите размер массива: ";
				cin >> size;

				mas = new int[size];
				read_mas(mas, size);
				break;
			}
		case 2:
			{
				if (size == -1)
				{
					cout << "Перед выводом необходимо ввести массив!" << endl;
					break;
				}
				write_mas(mas, size);
				break;
			}
		case 3:
			{
				if (size == -1)
				{
					cout << "Перед подсчётом количества необходимо ввести массив!" << endl;
					break;
				}
				int count = count_in_range(mas, size);
				cout << "Количество элементов: " << count << endl;
				break;
			}
		case 4:
			{
				if (size == -1)
				{
					cout << "Перед поиском суммы необходимо ввести массив!" << endl;
					break;
				}
				int sum = sum_not_in_range(mas, size);
				cout << "Сумма элементов массива: " << sum << endl;
				break;
			}
		case 5:
			{
				if (size == -1)
				{
					cout << "Перед проверкой сортировки необходимо ввести массив!" << endl;
					break;
				}
				bool is_sorted = is_sorted_ascending(mas, size);
				cout << "Отсортирован ли массив по возрастанию: " << is_sorted << endl;
				break;
			}
		case 6:
			{
				if (size == -1)
				{
					cout << "Перед вставкой необходимо ввести массив!" << endl;
					break;
				}
				int element;
				cout << "Введите элемент для вставки: ";
				cin >> element;
				insert(&mas, size, element);
				cout << "Вставка выполнена." << endl;
				break;
			}
		}
	}
	while (t != 0);


	system("pause");

	return 0;
}
