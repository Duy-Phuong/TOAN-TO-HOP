#include<iostream>
using namespace std;

//cau a
void Tao(int a[], int &n){ // khoi tao cac gia tri cho n, a[i].
	cout << "\nNhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = i;
}

void hoanvi(int &x, int &y)
{
	int t = x; x = y; y = t;
}

void sinh(int a[], int n, int &kt){
	int i = n - 1; // xuat phat tu vi tri n-1
	while (i > 0 && a[i] > a[i + 1]) 
		i--; // tìm a[i] dau tien > a[i+1]
	if (i > 0)
	{
		int k = n; // xuat phat tu phan tu cuoi
		while (a[i] > a[k]) 
			k--; // tim a[k] dau tien thoa man a[k] > a[i]
		hoanvi(a[i], a[k]);
		int r = i + 1, s = n;
		while (r <= s)
		{ // dao vi tri cac phan tu a[i+1] toi a[n]
			hoanvi(a[r], a[s]);
			r++;
			s--;
		}
	}
	else kt = 0; // ok = 0 khi ch??ng trinh da sinh du n! hoan vi khac nhau
}

void xuat(int a[], int n)
{ // xuat tung hoan vi ra man hinh
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
}

void xuat1(int a[], int n, int k)
{ // xuat tung hoan vi ra man hinh
	cout << "ket qua thu " << k << " la: ";
	for (int i = 1; i <= n; i++)
		cout << "   " << a[i];
	cout << endl;
}

void HoanVi(int a[], int n, int kt)
{
	int k = 1;
	while (kt)
	{
		//xuat(a, n); // xuat du lieu
		xuat1(a, n, k);
		k++;
		sinh(a, n, kt); // sinh hoan vi ke tiep tu hoan vi hien tai
	}
}

//cau b

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
				cout << "ket qua thu " << z << " la: ";
				xuat(p, k);
				z++;
			}
			else
			{
				ChinhHop(n, k, b, p, i + 1, z);
			}
			b[j] = 1;
		}
	}
}

//cau c

void ToHop(int i, int a[], int n, int k, int &z){
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{ 
		a[i] = j;									
		if (i == k)
		{
			cout << "ket qua thu " << z << " la: ";
			z++;
			xuat(a, k); // kiem tra lieu co xuat to hop ra?
		}
		else ToHop(i + 1, a, n, k, z); // tim & sinh phan tu tiep theo cua to hop.
	}
}

//cau d

void ChinhHopLap(int k, int n, int a[], bool &check) // phai thay doi nen truyen tham chieu
{
	int i = k;
	while (a[i] == n && i > 0){  // nếu a[i] = n và i > 0 thì giảm i
		i--;
	}
	if (i == 0) check = true; // nếu i = 0 thì đã đến cấu hình cuối cùng 
	else
	{
		a[i]++;     // tăng a[i] lên 1 đơn vị
		for (int j = i + 1; j <= k; j++){
			a[j] = 1;   // đặt tất cả phần tử phía sau a[i] = 1
		}

	}
}

void taoChinhHopLap(int k, int n, int a[],int i, int &z)
{
	if (i == k + 1)
	{
		cout << "ket qua thu " << z << " la: ";
		z++;
		xuat(a, k);
		return;
	}

	for (int j = 1; j <= n; j++)
	{
		a[i] = j;
		taoChinhHopLap(k, n, a, i + 1, z);
	}
}

//cau e

void taoToHopLap(int k, int n, int a[], int i, int &z)
{
	for (int j = a[i - 1]; j <= n; j++)
	{
		a[i] = j;
		if (i == k)
		{
			cout << "ket qua thu " << z << " la: ";
			z++;
			xuat(a, k);
		}
		else
			taoToHopLap(k, n, a, i + 1, z);
	}
}

 //bai 1.3
int tongMang(int a[], int size)
{
	int tong = 0;

	for (int i = 1; i <= size; i++)
		tong += a[i];

	return tong;
}
void giaiPhuongTrinhNghiemNguyen(int k, int n, int a[], int i)
{
	if (i == n + 1)
	{
		if (tongMang(a, n) == k)
		{
			xuat(a, n);
		}
		return;
	}

	for (int j = 0; j <= k; j++)
	{
		a[i] = j;
		giaiPhuongTrinhNghiemNguyen(k, n, a, i + 1);
	}
}


int main()
{
	int a[100] , b[100], p[100], kt = 1;
	int n, k;
	Tao(a, n);
	//cau a
	HoanVi(a, n, kt);
	//cau b
	cout << "\n------chinh hop-----\n";
	cout << "\nnhap n va k: " << endl;
	cin >> n;
	cin >> k;
	int z = 1;
	for (int i = 1; i <= n; i++) 
		b[i] = 1;
	if (n < k)
	{
		cout << "khong co ket qua\n";
	}
	else
	ChinhHop(n, k, b, p, 1, z);

	int c[100] = {};
	z = 1;
	cout << "\n------to hop-----\n";
	cout << "\nnhap n va k(n > k): " << endl;
	cin >> n;
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
	cout << "\n------to hop lap-----\n";
	cout << "\nnhap n va k(n < k): " << endl;
	cin >> n;
	cin >> k;
	z = 1;
	c[100] = {};
	c[0] = 1;
	taoToHopLap(k, n, c, 1, z);
	

	cout << "\n------chinh hop lap-----\n";
	cout << "\nnhap n va k(n < k): " << endl;
	cin >> n;
	cin >> k;
	//for (int i = 1; i <= k; i++) 
	//	b[i] = 1;
	//bool check = false;
	//while (check == false)
	//{
	//	xuat(b, k);
	//	ChinhHopLap(k, n, b, check);
	//}
	z = 1;
	if (n > k)
	{
		cout << "khong co ket qua\n";
	}
	else
	taoChinhHopLap(k, n, a, 1, z);
	cout << "\n-----giai phuong trinh nghiem nguyen--------\n";
	cout << "\nnhap n va k: " << endl;
	cin >> n;
	cin >> k;
	giaiPhuongTrinhNghiemNguyen(k, n, a, 1);
	return 0;
}