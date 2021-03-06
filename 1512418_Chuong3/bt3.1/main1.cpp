#include <iostream>

using namespace std;

#define MAX 100


void xuat(int a[], int n)
{ // xuat tung hoan vi ra man hinh
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
}

bool check(int a[], int n)// kiem tra
{
	for (int i = 1; i <= n - 2; i++)
	{
		if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 1)
			return true;
	}
	return false;
}


// bt 3.1 it nhat 2 mat ngua
bool check1(int a[], int n)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
			dem++;
		if (dem >= 2)
			return true;
	}
	return false;
}
// bt 3.2 it nhat 1 nam va 1 nu tuong tu �p dung cho bai...
bool check2(int a[], int n)
{
	int dem = 0;
	int dem2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= 5)
			dem++;
		if (a[i] >= 6)
			dem2++;
		if (dem == 1 && dem2 == 1)
			return true;
	}
	return false;
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
		if (check1(a, k))
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

//3.2
void ToHop(int i, int a[], int n, int k, int &z){
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{
		a[i] = j;
		if (i == k)
		{
			if (check2(a, k))
			{
				cout << "ket qua thu " << z << " la: ";
				z++;
				xuat(a, k); // kiem tra lieu co xuat to hop ra
			}
		}
		else ToHop(i + 1, a, n, k, z); // tim & sinh phan tu tiep theo cua to hop.
	}
}


int main()
{
	int a[MAX];
	bool b[MAX];
	int n = 0;
	int k = 0;
	cout << "bai 3.1 (ngua la 0, xap la 1): \n";
	//n = 2, k = 8
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	int z;

	z = 1;
	if (n > k)
	{
		cout << "khong co ket qua\n";
	}
	else
		taoChinhHopLap(k, n, a, 1, z);


}