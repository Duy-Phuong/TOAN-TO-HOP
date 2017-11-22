#include <iostream>

using namespace std;

#define MAX 100


void xuat(int a[], int n)
{ // xuat tung hoan vi ra man hinh
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
}


// bt 3.2 it nhat 1 nam va 1 nu tuong tu áp dung cho bai...
bool check2(int a[], int n)
{
	int dem = 0;
	int dem2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= 50)
			dem++;
		if (a[i] >= 51)
			dem2++;
		if (dem == 1 && dem2 == 1)
			return true;
	}
	return false;
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
	int z = 1;

	//3.2
	int c[100] = {};
	cout << c[0] << c[1] << endl;
	cout << "bai 3.2: \n";
	cout << "Nhap n (n > k) = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	if (n < k || k == 0)
	{
		if (k == 0)
			cout << "tap rong\n";
		else
			cout << "khong co ket qua\n";
	}
	else
		ToHop(1, c, n, k, z);

}