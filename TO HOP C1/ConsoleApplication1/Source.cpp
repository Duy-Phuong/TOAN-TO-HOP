#include <iostream>

using namespace std;

#define MAX 100
int a[MAX];
bool b[MAX];
int n = 0;
int k = 0;

void inKq(int size)
{
	for (int i = 1; i <= size; i++)
		cout << a[i] << "  ";
	cout << endl;
}

void khoiTao()
{
	for (int i = 0; i <= n; i++)
		b[i] = true;
}

void taoHoanVi(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (b[j])
		{
			a[i] = j;
			if (i == n)
			{
				inKq(n);
			}
			else
			{
				b[j] = false;
				taoHoanVi(i + 1);
				b[j] = true;
			}
		}
	}
}

void taoChinhHop(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (b[j])
		{
			a[i] = j;
			if (i == k + 1) inKq(k);
			else
			{
				b[j] = false;
				taoChinhHop(i + 1);
				b[j] = true;
			}
		}
	}
}


void taoChinhHopLap(int i)
{
	if (i == k + 1)
	{
		inKq(k);
		return;
	}

	for (int j = 1; j <= n; j++)
	{
		a[i] = j;
		taoChinhHopLap(i + 1);
	}
}

void taoToHop(int i)
{
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{
		a[i] = j;
		if (i == k)
		{
			inKq(k);
		}
		else
			taoToHop(i + 1);
	}
}

void taoToHopLap(int i)
{
	for (int j = a[i - 1]; j <= n; j++)
	{
		a[i] = j;
		if (i == k)
		{
			inKq(k);
		}
		else
			taoToHopLap(i + 1);
	}
}

int tongMang(int size)
{
	int tong = 0;

	for (int i = 1; i <= size; i++)
		tong += a[i];

	return tong;
}

void InKq(int size)
{
	cout << a[1];
	for (int i = 2; i <= size; i++)
		cout << " + " << a[i];
	cout << " = " << k << endl;
}

void InKQ(int size)
{
	cout << a[1];
	for (int i = 2; i <= size; i++)
		cout << " + " << a[i];
	cout << " <= " << k << endl;
}

void giaiPhuongTrinhNghiemNguyen(int i)
{
	if (i == n + 1)
	{
		if (tongMang(n) == k)
		{
			InKq(n);
		}
		return;
	}

	for (int j = 0; j <= k; j++)
	{
		a[i] = j;
		giaiPhuongTrinhNghiemNguyen(i + 1);
	}
}

void giaiBatPhuongTrinhNghiemNguyen(int i)
{
	if (i == n + 2)
	{
		if (tongMang(n + 1) == k)
		{
			InKQ(n);
		}
		return;
	}

	for (int j = 0; j <= k; j++)
	{
		a[i] = j;
		giaiBatPhuongTrinhNghiemNguyen(i + 1);
	}
}

bool cauA()
{
	for (int i = 1; i <= n - 2; i++)
	if (a[i] == 0 && a[i + 1] == 0)
		return false;
	return true;
}

bool cauB()
{
	for (int i = 1; i <= n - 1; i++)
	if (a[i] == 1 && a[i + 1] == 1)
		return true;
	return false;
}

void sinhNhiPhan(int i, bool(*dieuKien)())
{
	if (i == n + 1)
	{
		if (dieuKien() == true)
			inKq(n);
		return;
	}

	a[i] = 0;
	sinhNhiPhan(i + 1, dieuKien);

	a[i] = 1;
	sinhNhiPhan(i + 1, dieuKien);
}

int main()
{
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;

	cout << "Tat cua hoan vi cua " << n << " phan tu:" << endl;
	khoiTao();
	taoHoanVi(1);
	cout << endl << endl;

	cout << "Liet ke tat ca chinh hop chap " << k << " cua " << n << endl;
	khoiTao();
	taoChinhHop(1);
	cout << endl << endl;

	cout << "Liet ke tat ca chinh hop lap chap " << k << " cua " << n << endl;
	taoChinhHopLap(1);
	cout << endl << endl;

	cout << "Liet ke tat ca to hop chap " << k << " cua " << n << endl;
	a[0] = 0;
	taoToHop(1);
	cout << endl << endl;

	cout << "Liet ke tat ca to hop lap chap " << k << " cua " << n << endl;
	a[0] = 1;
	taoToHopLap(1);
	cout << endl;

	cout << "Liet ke tat ca bo so x1, x2,..., xn thoa x1 + x2 + ... + xn = k" << endl;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	giaiPhuongTrinhNghiemNguyen(1);
	cout << endl << endl;

	cout << "Liet ke tat ca bo so x1, x2,..., xn thoa x1 + x2 + ... + xn <= k" << endl;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap k = ";
	cin >> k;
	giaiBatPhuongTrinhNghiemNguyen(1);
	cout << endl << endl;

	cout << "Nhap do dai cua day nhi phan n = ";
	cin >> n;
	cout << "Chuoi nhi phan co do dai " << n << " khong chua 2 bit 0 lien tiep:" << endl;
	sinhNhiPhan(1, cauA);
	cout << endl << endl;

	cout << "Nhap do dai cua day nhi phan n = ";
	cin >> n;
	cout << "Chuoi nhi phan co do dai " << n << " chua 2 bit 1 lien tiep:" << endl;
	sinhNhiPhan(1, cauB);

	return 0;
}
