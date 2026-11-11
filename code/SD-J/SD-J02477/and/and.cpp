#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string ttot(int n)
{
	string s;
	while(n > 0)
	{
		int a = n % 2;
		n /= 2;
		s = (char)(a + '0') + s;
	}
	return s;
}
int awy(string n,string m)
{
	string s;
	int sss;
	for(int i = 0;i < min(n.length(),m.length());i++)
	{
		if(m[i] = n[i])
		{
			s = '1' + s;
		}
		else
		{
			s = '0' + s;
		}
	}
	for(int i = 0;i < s.length();i++)
	{
		sss += pow((int)(s[i] - '0'),i);
	}
	return sss;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num = 0;
	cin >> n >> m;
	int a[n + 5];
	string b[n + 5];
	cin >> a[1];
	b[1] = ttot(a[1]);
	for(int i = 2;i <= n;i++)
	{
		cin >> a[i];
		b[i] = ttot(a[i]);
		if(awy(b[i],b[i - 1]) > num)
		{
			num = awy(b[i],b[i - 1]);
		}
	}
	cout << num;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
