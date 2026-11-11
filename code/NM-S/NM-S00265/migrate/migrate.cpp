#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],sum,ans,mia;
void dfs(long long u,long long v,long long k)
{
	if(u==v)
	{
		if(k<mia)sum=1,mia=k;
		else if(k==mia)sum++;
		return;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(a[i]-a[u]<=d)dfs(i,v,k+1);
		else break;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum=0,mia=LLONG_MAX;
				dfs(i,j,0);
				if(sum==2)ans++;
			}
		}
		cout <<ans<<'\n';
	}
	return 0;
}