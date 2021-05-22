#include <iostream>
using namespace std;

struct List
{
	char info;
	List* next;
};

List* Vvod(int n)
{
	List* first, * a;
	first = NULL;
	cout << "Введите 1 элемент списка: ";
	a = new List;
	cin >> a->info;
	first = a;
	for (int i = 2; i <= n; i++)
	{
		List* b = new List;
		a->next = b;
		a = a->next;
		cout << "Введите " << i << " элемент: ";
		cin >> a->info;
		a->next = NULL;
	}
	return first;
}

void Print(List* first)
{
	if (first == NULL)
	{
		cout << "Список пустой.";
	}
	else
	{
		List* a = first;
		while (a != NULL)
		{
			cout << a->info << "\t";
			a = a->next;
		}
	}
	cout << endl;
}

void Adding(int n, char set_info, List* first)
{
	List* key = NULL;
	List* key_next = NULL;
	while (first != NULL)
	{
		if (first->info != NULL && first->info == set_info)
		{
			key = first;
			key_next = first->next;
		}
		first = first->next;
	}

	if (key != NULL)
	{
		List* b = new List;
		cout << "Введите элемент, который надо добавить в список: ";
		cin >> b->info;
		key->next = b;
		b->next = key_next;
	}
}

int main()
{
	system("color F0");
	setlocale(0, "");
	int n = 0;
	while (n <= 0)
	{
		cout << "Введите размер списка: ";
		cin >> n;
	}
	List* list = Vvod(n);
	cout << "Начальный список: ";
	Print(list);

	char set_info;
	cout << "Задайте информационное поле: ";
	cin >> set_info;

	Adding(n, set_info, list);

	cout << "Итоговый список: ";
	Print(list);
	return 0;
}

