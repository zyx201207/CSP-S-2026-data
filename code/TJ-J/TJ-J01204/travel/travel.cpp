#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	int c,d;
	cin >> c >> a >> d >> b;
	if(d==c)
	{
		cout << 1;
	}
	else
	{
		cout << 0000;
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout << 1;
	}
	else
	{
		cout << 000;
		return 0;
	}
	if(b[2]<='C'&&a[2]<='C')
	{
		cout << 1;
	}
	else
	{
		cout << 00;
		return 0;
	}
	if(b[2]>'C'&&a[2]>'C')
	{
		cout << 11;
		return 0;
	}
	if(abs(a[2]-b[2])==1)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	return 0;
}
