#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int DoUuTien(string s)
{
	if (s == "~") return 5;
	else if (s == "^") return 4;
	else if (s == "v") return 3;
	else if (s == "->") return 2;
	else if (s == "<->") return 1;
	else return -1;
}

bool isVar(char k)
{ 
	if (k >= 'A' && k <= 'Z')
		return true;
	else
		return false;
}
struct KQ
{
	char data;
	int x;
};
int search(KQ mang[], int n, char x)
{
	for (int i = 0; i < n; i++)
	{
		if (x == mang[i].data)
		{
			return i;
		}
	}
	return -1;
}
void tinh(vector<string> str, stack<int> s, KQ mang[], int kichthuoc, string in, int a[])
{
	for (int i = 0; i < kichthuoc; i++)
	{
		mang[i].x = a[i];
	}

	fstream f("bangchantri.out.txt", ios::out | ios::app);
	for (int i = 0; i< str.size(); i++)
	{
		if (str[i][0] >= 'A' && str[i][0] <= 'Z')
		{
			int p = search(mang, kichthuoc, str[i][0]);
			s.push(mang[p].x);
		}
			
		else if (!s.empty())
		{
			int a1, b;
			b = s.top(); s.pop();
			a1 = s.top(); s.pop();
			if (str[i] == "^")
			{
				int x = a1 & b;
				s.push(x);
			}
			if (str[i] == "v")
			{
				int y = a1 | b;
				s.push(y);
			}
			if (str[i] == "<->")
			{
				int x = 0;
				if (a1 == b)
				{
					x = 1;
				}
				s.push(x);
			}
			if (str[i] == "->") 
			{
				int x = 1;
				if (a1 == 1 && b == 0)
				{
					x = 0;
				}
				s.push(x);
			}
		}
	} 

	for (int i = 0; i < kichthuoc; i++)
	{
		f << a[i] << " ";
	}
	if (!s.empty())
		f << s.top();
	f << endl;
	f.close();
}

bool check(vector<char> variable, char x)
{
	for (int i = 0; i < variable.size(); i++)
	{
		if (x == variable[i])
			return false;
	}
	return true;
}
int main()
{
	string s;
	vector<string> tach;
	vector<char> variable;
	string u = "";
	fstream f1("bangchantri.in.txt", ios::in);
	fflush(stdin);
	getline(f1, s);
	f1.close();

	for (int i = 0; i < s.length(); i++)
	{ 
		if (s[i] == '~' || s[i] == '^' || s[i] == 'v' || s[i] == '(' || s[i] == ')' || s[i] == '~'|| isVar(s[i]))
		{
			u += s[i];
			tach.push_back(u);
		}
		if (s[i] == '-' && s[i-1] != '<')
		{
			u += "->";
			tach.push_back(u);
		}
		if (s[i] == '<')
		{
			u += "<->";
			tach.push_back(u);
		}
		u.clear();
	}
	//for (int i = 0; i < tach.size(); i++)
	//{ 
	//	cout << tach[i] << endl;
	//}
	vector<string> hauto;
	stack<string> h;
	for (int i = 0; i < tach.size(); i++)
	{ 
		if (tach[i][0] >= 'A' && tach[i][0] <= 'Z')
		{
			char a = tach[i][0];
			hauto.push_back(tach[i]);
			if (check(variable, tach[i][0]))
			{
				variable.push_back(tach[i][0]);// them vao mang ki tu

			}
		}
		else
		{
			string s2 = tach[i];
			if (tach[i] == "(")
			{
				h.push(tach[i]);
			}
			else
			{
				if (tach[i] == ")")
				{
					while (h.top() != "(")
					{
						string x = h.top();
						h.pop();
						hauto.push_back(x);
					}
					if (h.top() == "(")
					{
						h.pop();
					}
				}
				else
				{
					while (!h.empty() && DoUuTien(tach[i]) <= DoUuTien(h.top()))
					{
						string x1 = h.top();
						h.pop();
						hauto.push_back(x1);
						
					}
					h.push(tach[i]);
				}
			}
		}

	}
	while (!h.empty())
	{
		string x2 = h.top();
		h.pop();
		hauto.push_back(x2);
	}
	int n = h.size();

	for (int i = 0; i < hauto.size(); i++)
	{ 
		cout << hauto[i];
	}
	sort(variable.begin(), variable.end());// sap xep
	KQ mang[100];
	int kichthuoc = variable.size();
	for (int i = 0; i < variable.size(); i++)
	{
		//cout << variable[i];
		mang[i].data = variable[i];
	}
	//cout << endl;

	fstream f("bangchantri.out.txt", ios::out | ios::app);
	for (int i = 0; i < kichthuoc; i++)
	{
		f << variable[i];
		f << " ";
	}
	f << s;
	f << endl;
	f.close();
	stack<int> dapso;
	int a[] = { 0, 0, 0 };
	tinh(hauto, dapso, mang, kichthuoc, s, a);
	int a1[] = { 0, 0, 1 };
	tinh(hauto, dapso, mang, kichthuoc, s, a1);
	int a2[] = { 0, 1, 0 };
	tinh(hauto, dapso, mang, kichthuoc, s, a2);
	int a3[] = { 0, 1, 1 };
	tinh(hauto, dapso, mang, kichthuoc, s, a3);
	int a4[] = { 1, 0, 0 };
	tinh(hauto, dapso, mang, kichthuoc, s, a4);
	int a5[] = { 1, 0, 1 };
	tinh(hauto, dapso, mang, kichthuoc, s, a5);
	int a6[] = { 1, 1, 0 };
	tinh(hauto, dapso, mang, kichthuoc, s, a6);
	int a7[] = { 1, 1, 1 };
	tinh(hauto, dapso, mang, kichthuoc, s, a7);
	return 0;
}