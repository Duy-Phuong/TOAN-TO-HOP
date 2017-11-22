#include <iostream>

using namespace std;

#define MAX 100


void xuat(int a[], int n)
{ // xuat tung hoan vi ra man hinh
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
}

//bai 3.4
int Demsolanxh(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == x)
			dem++;
	}
	return dem;
}

bool check3(int a[], int n)
{
	if (Demsolanxh(a, n, 1) != 1)//so 1 xh 1 lan
	{
		return 0;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (Demsolanxh(a, n, i) == 3)// so 3 xh khac 3 lan
			return 0;
	}
	return 1;
}

void taoChinhHopLap(int k, int n, int a[], int i, int &z)
{
	if (i == k + 1)
	{
		if (check3(a, k))
		{
			cout << "ket qua thu " << z << " la: ";
			z++;
			xuat(a, k);
		}
		return;

	}

	for (int j = 0; j < n; j++)
	{
		a[i] = j;
		taoChinhHopLap(k, n, a, i + 1, z);
	}
}


int main()
{
	int a[MAX];
	int n = 0;
	int k = 0;
	cout << "bai 3.4 : \n";
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	int z;

	z = 1;
	//if (n > k)
	//{
	//	cout << "khong co ket qua\n";
	//}
	//else
		taoChinhHopLap(k, n, a, 1, z);

}