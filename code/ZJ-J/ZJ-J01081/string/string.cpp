#include <bits/stdc++.h>
using namespace std;

bool f(string x)
{
	for(int i=0;i*2<x.size()-1;i++)
	{
		int a=abs(ceil(x.size()/2)-i);
		if(x[i]!=x[i+a])
			return false;
		else
			return true;
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a;
	char b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		while(a>0)
		{
			s+=b;
			a--;
		}
	}
	if(f(s))
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i*2<s.size()-1;i++)
	{
		int a=abs(ceil(s.size()/2)-i);
		if(s[i]!=s[i+a])
			s[i]=s[i+a];
			cnt++;
	}
	cout<<cnt;
	return 0;
}
