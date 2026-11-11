#include <bits/stdc++.h>
using namespace std;
int s[10000000];
int a;
string c;
int main()
{
	int n;
	cin>>n;
	int d[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			c=s[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i+1]==s[i])
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=n;i>=n;i--)
	{
		s[i]=d[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=d[i])
		{
			break; 
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	cout<<2;
	return 0;
}
