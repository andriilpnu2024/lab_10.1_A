#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Spec { RI, PZ, SA };
string specStr[] = { "РІ", "ПЗ", "СА" };
struct Studik
{
	string prizv;
	unsigned kurs;
	unsigned fiz;
	unsigned mat;
	unsigned prog;
	Spec spec;
};
void Create(Studik* p, const int N);
void Print(Studik* p, const int N);
double LineSearch(Studik* p, const int N, int& k);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	int k = 0;
	int N;
	cout << "Введіть N: "; cin >> N;

	Studik* p = new Studik[N];
	Create(p, N);
	Print(p, N);
	cout << LineSearch(p, N, k) << endl;
	cout << "Кількість кожної з оцінок з '3','4','5' фізики:"<< k << endl;

	return 0;
}
void Create(Studik * p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync(); 

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " Оцінка з фізики: "; cin >> p[i].fiz;
		cout << " Оцінка з математики: "; cin >> p[i].mat;
		cout << " Оцінка з програмування: "; cin >> p[i].prog;
		cout << " спеціальність: (0 - РІ, 1 - ПЗ, 2 - СА): ";
			cin >> spec;
			p[i].spec = (Spec)spec;
	}
}
void Print(Studik* p, const int N)
{
	cout << "=======================================================================================" << endl;
	cout << "| №   | Прізвище       | Курс | Спеціальність   | Фізика | Математика | Програмування |" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv // Прізвище 
			<< "| " << setw(4) << right << p[i].kurs << " "// Курс
			<< "| " << setw(16) << left << specStr[p[i].spec] // Спеціальність 
			<< "| " << setw(6) << right << p[i].fiz << " "    // Фізика 
			<< "| " << setw(10) << right << p[i].mat << " "   // Математика
			<< "| " << setw(13) << right << p[i].prog << " |" << endl; // Програмування 
	}
	cout << "======================================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Studik* p, const int N, int& k)
{
	cout << "Кількість студентів, які отримали і з фізики, і математики '4','5':";
    int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].fiz == 4 || p[i].fiz == 5 || p[i].fiz == 3)
		{
			k++;
		}
		if ((p[i].fiz == 4 || p[i].fiz == 5) && (p[i].mat == 4 || p[i].mat == 5))
		{
			n++;
		}
	}
	return n;
}
