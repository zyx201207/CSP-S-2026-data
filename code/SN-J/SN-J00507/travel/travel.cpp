#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
string s;
bool f1=0, f2=0, f3=0;
signed main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin, s);
	/*
	02 01C 02 01D
	0123456789012
	*/
//	for (int i=0;i<=12;i++)
//	{
//		cout << s[i];
//	}
	if (s[0]==s[7]&&s[1]==s[8])
	{
		cout << 1;
		f1=1;
	}
	else
	{
		cout << 0;
	}
	if (s[3]==s[10]&&s[4]==s[11]&&f1)
	{
		cout << 1;
		f2=1;
	}
	else 
	{
		cout << 0;
	}
	if (s[5]=='A'||s[5]=='B'||s[5]=='C')
	{
		if ((s[12]=='A'||s[12]=='B'||s[12]=='C')&&f2)
		{
			cout << 1;
			f3=1;
		}
		else
		{
			cout << 0;
		}
	}
	if (s[5]=='D'||s[5]=='F')
	{
		if ((s[12]=='D'||s[12]=='F')&&f2)
		{
			cout << 1;
			f3=1;
		}
		else
		{
			cout << 0;
		}
	}
	if (abs(s[12]-s[5])==1&&f3==1)
	{
		if (s[5]=='C'&&s[12]=='D')
		{
			cout << 0;
		}
		else 
		{
			cout << 1;
		}
	}
	else 
	{
		cout << 0;
	}
}	
