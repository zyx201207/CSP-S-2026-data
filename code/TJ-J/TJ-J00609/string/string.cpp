#include<iostream>
#include<cstdio>
using namespace std;
long long n;
string s,s1;
string fan(string a)
{
	string b;
	for(int i=a.size()-1;i>=0;i--)
	{
		b+=a[i];
	}
	return b;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			s+=a;
		}
	}
	s1=fan(s);
	if(s1==s)
	{
		cout<<0;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
