#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Spec { RI, PZ, SA };
string specStr[] = { "в", "��", "��" };
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
	cout << "������ N: "; cin >> N;

	Studik* p = new Studik[N];
	Create(p, N);
	Print(p, N);
	cout << LineSearch(p, N, k) << endl;
	cout << "ʳ������ ����� � ������ � '3','4','5' ������:"<< k << endl;

	return 0;
}
void Create(Studik * p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync(); 

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������ � ������: "; cin >> p[i].fiz;
		cout << " ������ � ����������: "; cin >> p[i].mat;
		cout << " ������ � �������������: "; cin >> p[i].prog;
		cout << " ������������: (0 - в, 1 - ��, 2 - ��): ";
			cin >> spec;
			p[i].spec = (Spec)spec;
	}
}
void Print(Studik* p, const int N)
{
	cout << "=======================================================================================" << endl;
	cout << "| �   | �������       | ���� | ������������   | Գ���� | ���������� | ������������� |" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv // ������� 
			<< "| " << setw(4) << right << p[i].kurs << " "// ����
			<< "| " << setw(16) << left << specStr[p[i].spec] // ������������ 
			<< "| " << setw(6) << right << p[i].fiz << " "    // Գ���� 
			<< "| " << setw(10) << right << p[i].mat << " "   // ����������
			<< "| " << setw(13) << right << p[i].prog << " |" << endl; // ������������� 
	}
	cout << "======================================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Studik* p, const int N, int& k)
{
	cout << "ʳ������ ��������, �� �������� � � ������, � ���������� '4','5':";
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
