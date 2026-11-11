#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,a[N];
char c[N];
string s;
ll hu(string x)
{
	if(x.size()==3) return (x[0]==x[2])?1:0;
	for(int i=0;i<x.size()/2;i++)
	{
		if(x[i]!=x[x.size()-i-1]) return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(c[1]==c[2]) 
		{
			cout<<0;
			return 0;
		}
		else if(a[1]<=a[2]) 
		{
			cout<<a[1];
			return 0;
		}
		else
		{
			cout<<a[2];
			return 0;
		}
	}
	else if(n<=10)
	{
		string s;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++) s.push_back(c[i]);
		}
		if(hu(s)) 
		{
			cout<<0;
			return 0;
		}
	}
	
	return 0;
}
