#include <bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s,d;
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin >>n;
	for (int i=1; i<=n; i++)
	{
		cin >>a>>c;
		for (int j=1; j<=a; j++)
		{
			s+=c;
		}
	}
	for (int i=s.size()-1; i>=0; i--)
	{
		d+=s[i];
	}
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]!=d[i])
		{
			ans++;
		}
	}
	cout <<ans/2; 
	return 0;
} 
