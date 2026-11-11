#include <bits/stdc++.h>
using namespace std;
bool p[5] , l;
int c1 , c2 , t[3] , a[3];
string s1 , s2;
bool check1(int a , int b)
{
	return a == b;
}
bool check2(string a , string b)
{
	return a[0] == b[0] && a[1] == b[1];
}
bool check3()
{
	return t[1] == t[2];
}
bool check4()
{
	if (t[1] == 2)
	{
		return true;
	}
	if (a[1] - a[2] >= -1 && a[1] - a[2] <= 1)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a[1] = s1[2] - 'A';
	a[2] = s2[2] - 'A';
	for (int i = 1;i <= 2;i++)
	{
		if (a[i] >= 0 && a[i] <= 2)
		{
			t[i] = 1;
		}
		else
		{
			t[i] = 2;
		}
	}
	if (check1(c1, c2) && !l)
	{
		p[1] = 1;
	}
	else
	{
		l = 1;
	}
	if (check2(s1, s2) && !l)
	{
		p[2] = 1;
	}
	else
	{
		l = 1;
	}
	if (check3() && !l)
	{
		p[3] = 1;
	}
	else
	{
		l = 1;
	}
	if (check4() && !l)
	{
		p[4] = 1;
	}
	else
	{
		l = 1;
	}
	for (int i = 1;i <= 4;i++)
	{
		cout << p[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
