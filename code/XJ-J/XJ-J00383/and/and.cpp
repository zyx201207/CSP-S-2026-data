#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,a[200005],s[200005],su;
bool v[2005];
void dfs(int st)
{
	if(st==m+1)
	{
		ll nu=s[1];
		for(int i=2;i<st;i++)
		{
			nu=nu&s[i];
		}
		su=max(nu,su);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			s[st]=a[i];
			v[i]=1;
			dfs(st+1);
			v[i]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<su;
	return 0;
}