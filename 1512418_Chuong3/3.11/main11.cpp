#include <iostream>
using namespace std;

#define MAX 100


void xuat(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
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

void taoChinhHopLap1(int k, int n, int a[], int i, int &z)
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
		taoChinhHopLap1(k, n, a, i + 1, z);
	}

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
		if (dem >= 1 && dem2 >= 1)
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
				xuat(a, k); 
			}
		}
		else ToHop(i + 1, a, n, k, z); 
	}
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

void taoChinhHopLap4(int k, int n, int a[], int i, int &z)
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
		taoChinhHopLap4(k, n, a, i + 1, z);
	}
}

int TongChuSo(int x)
{
	int s = 0;
	int dv;
	while (x > 0)
	{
		dv = x % 10;
		s += dv;
		x /= 10;
	}
	return s;
}

//bai 3.6
bool check6(int a[], int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		if ((a[i] == 1 && a[i + 1] == 2) || (a[i] == 3 && a[i + 1] == 4) || (a[i] == 5 && a[i + 1] == 6))
			return true;
	}
	return false;
}


void ChinhHop(int n, int k, int b[], int p[], int i, int &z)
{
	for (int j = 1; j <= n; j++)
	{
		if (b[j] == 1)
		{
			p[i] = j;
			b[j] = 0;
			if (i == k)
			{
				if (check6(p, k))
				{
					cout << "ket qua thu " << z << " la: ";
					xuat(p, k);
					z++;
				}
			}
			else
			{
				ChinhHop(n, k, b, p, i + 1, z);
			}
			b[j] = 1;
		}
	}
}

int UCLN(int a, int b)
{
	if (a == b)
	{
		return a;
	}

	if (a > b)
	{
		return UCLN(a - b, b);
	}
	else
	{
		return UCLN(b - a, a);
	}
}

//3.8
void xuat8(int a[], int n, char c[])
{
	for (int i = 1; i <= n; i++)
		cout << "   " << c[a[i] - 1];
	cout << endl;
}



void ChinhHop(int n, int k, int b[], int p[], int i, int &z, char c[])
{
	for (int j = 1; j <= n; j++)
	{
		if (b[j] == 1)
		{
			p[i] = j;
			b[j] = 0;
			if (i == k)
			{
				cout << "ket qua thu " << z << " la: ";
				xuat8(p, k, c);
				z++;
			}
			else
			{
				ChinhHop(n, k, b, p, i + 1, z, c);
			}
			b[j] = 1;
		}
	}
}

//bai 3.9

bool tong9(int a[], int n)// kiem tra
{
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += a[i];
	}
	if (s == 31)
		return true;
	else
		return false;
}

void TimNghiem(int a[], int n, int i, int& d)
{
	for (int j = 0; j <= 9; j++)
	{
		a[i] = j;
		if (i == n - 1)
		{
			if (tong9(a, n))
			{
				cout << "So nguyen thu " << d << " : ";
				xuat(a, n);
				d++;
			}
		}
		else
			TimNghiem(a, n, i + 1, d);
	}
}
//bai 3.10

bool tong10(int a[], int n)// kiem tra
{
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += a[i];
	}
	if (s == 20)
		return true;
	else
		return false;
}



void taoChinhHopLap10(int k, int n, int a[], int i, int &z)
{
	if (i == k + 1)
	{
		if (tong10(a, k))
		{
			cout << "ket qua thu " << z << " la: ";
			z++;
			xuat(a, k);
		}
		return;

	}

	for (int j = 1; j <= n; j++)
	{
		a[i] = j;
		taoChinhHopLap10(k, n, a, i + 1, z);
	}
}

	



int main()
{
	//bai 3.1
	int a[MAX];
	int n = 0;
	int k = 0;
	int z;
	cout << "bai 3.1 (ngua la 0, xap la 1): \n";
	//n = 2, k = 8
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	
	z = 1;
	if (n >= k)
	{
		cout << "khong co ket qua\n";
	}
	else
	{
		taoChinhHopLap1(k, n, a, 1, z);
	}
		
	//bai 3.2
	z = 1;

	int c[100] = {};//
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
	{
		ToHop(1, c, n, k, z);
	}

	//bai 3.3
	cout << "bai 3.3: \n";
	cout << "\nnhap n: " << endl;
	cin >> n;
	int dem = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0 || i % 7 == 0)
		{
			cout << "ket qua thu " << dem << " la: " << i << endl;
			dem++;
		}
	}

	//int z = 1;
	//for (int i = 1; i <= n; i++)
	//{
	//	b[i] = 1;
	//}

	//bai 3.4
	//int a[MAX];
	////int n = 0;
	//int k = 0;
	//n=10, k=5
	cout << "bai 3.4 : \n";
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
//	int z;

	z = 1;
	taoChinhHopLap4(k, n, a, 1, z);



	////bai 3.6
	//int p[100];
	//int b[100];
	//cout << "bai 3.6: \n";
	//cout << "\nnhap n: " << endl;
	//cin >> n;
	//z = 1;
	//for (int i = 1; i <= n; i++)
	//{
	//	b[i] = 1;
	//}
	//ChinhHop(n, n, b, p, 1, z);

	////bai3.7
	//cout << "bai 3.7: \n";
	//cout << "\nnhap n: " << endl;
	//cin >> n;
	//dem = 1;
	//cout << "\ncau a:\n";
	//for (int i = 1; i <= n; i++)
	//{
	//	if (i % 2 != 0 || i % 3 != 0 || i % 5 != 0)
	//	{
	//		cout << "ket qua thu " << dem << " la: " << i << endl;
	//		dem++;
	//	}
	//}
	//dem = 1;
	//cout << "\ncau b:\n";
	//for (int i = 1; i <= n; i++)
	//{
	//	if (UCLN(i, 210) == 1)
	//	{
	//		cout << "ket qua thu " << dem << " la: " << i << endl;
	//		dem++;
	//	}
	//}

	//dem = 1;
	//cout << "\ncau c:\n";
	//for (int i = 1; i <= n; i++)
	//{
	//	if (UCLN(i, 30) == 1 && i % 7 == 0)
	//	{
	//		cout << "ket qua thu " << dem << " la: " << i << endl;
	//		dem++;
	//	}
	//}

	//bai 3.8
	//char c[] = { 'I', 'N', 'F', 'O', 'R', 'M', 'A', 'T', 'I', '0', 'N' };
	//char d[] = { 'I', 'O', 'N' };
	//int p[100];
	//int b[100];
	////cau b
	//cout << "bai 3.8: \n";
	//cout << "\nnhap n: " << endl;
	//cin >> n;
	//int z = 1;
	//for (int i = 1; i <= n; i++)
	//{
	//	b[i] = 1;
	//}
	//	
	//ChinhHop(n, n, b, p, 1, z, c);


	//bai 3.9
	//int dem9 = 1;
	//int x1, x2, x3, x4;
	//cout << "cau a: \n";
	//for (int x1 = 0; x1 < 8; x1++)
	//{
	//	for (int x2 = 0; x2 < 8; x2++)
	//	{
	//		for (int x3 = 0; x3 < 8; x3++)
	//		{
	//			for (int x4 = 0; x4 < 8; x4++)
	//			{
	//				if (x1 + x2 + x3 + x4 == 19)
	//				{
	//					cout << "ket qua thu " << dem9 << " thoa YCBT la: " << x1 << "  " << x2 << "  "<< x3 << "  " << x4 << endl;
	//					dem9++;
	//				}
	//			}
	//		}
	//	}
	//}
	//dem9 = 1;
	//cout << "\ncau b: \n";
	//for (int x1 = 0; x1 <= 5; x1++)
	//{
	//	for (int x2 = 0; x2 <= 6; x2++)
	//	{
	//		for (int x3 = 3; x3 <= 7; x3++)
	//		{
	//			for (int x4 = 3; x4 <= 8; x4++)
	//			{
	//				if (x1 + x2 + x3 + x4 == 19)
	//				{
	//					cout << "ket qua thu " << dem9 << " thoa YCBT la: " << x1 << "  " << x2 << "  " << x3 << "  " << x4 << endl;
	//					dem9++;
	//				}
	//			}
	//		}
	//	}
	//}
	//dem9 = 1;
	//cout << "cau c: \n";
	//for (int x1 = -5; x1 <= 10; x1++)
	//{
	//	for (int x2 = -5; x2 <= 10; x2++)
	//	{
	//		for (int x3 = -5; x3 <= 10; x3++)
	//		{
	//			for (int x4 = -5; x4 <= 10; x4++)
	//			{
	//				if (x1 + x2 + x3 + x4 == 19)
	//				{
	//					cout << "ket qua thu " << dem9 << " thoa YCBT la: " << x1 << "  " << x2 << "  " << x3 << "  " << x4 << endl;
	//					dem9++;
	//				}
	//			}
	//		}
	//	}
	//}

	//bai 3.10
	//int a[MAX];
	//n = 0;
	//int k = 0;
	//cout << "bai 3.10: \n";
	//cout << "Nhap n = ";
	//cin >> n;
	//cout << "Nhap k = ";
	//cin >> k;
	//int z;
	//// n= 6; k=5
	//z = 1;
	//taoChinhHopLap10(k, n, a, 1, z);

	//bai 3.11
	//dem = 1;
	//for (int i = 1; i <= 9999999; i++)
	//{
	//	if (TongChuSo(i) == 31)
	//	{
	//		cout << "chu so thu " << dem << " la: " << i << endl;
	//		dem++;
	//	}
	//}

	//int a[MAX];
	//n = 0;
	//TimNghiem(a, n, 1, dem);

	return 0;
}