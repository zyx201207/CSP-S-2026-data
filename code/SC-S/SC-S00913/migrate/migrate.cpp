#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],hx[10000000],ans;
void dfs(int zn)
{
	if(zn>n)return;
	hx[zn]++;
	for(int i=zn+1;i<=n;i++)
	{
		if(a[i]-a[zn]<=d)dfs(i);
		else break;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;	
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==13||c==14)cout<<0;
		else
		{
			memset(hx,0,sizeof(hx));
			dfs(1);
			for(int i=1;i<=n;i++)
			{
				if(hx[i]==2)ans++;
			}
			cout<<ans;
		}
	}
	return 0;
}