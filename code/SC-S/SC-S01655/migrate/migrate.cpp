#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll test_number;
ll t;
ll n,d,a[1010],dp[1010],ans,minn[1010],f[1010];
void dfs(ll id,ll step)
{
	if(step>=minn[id])return;
	minn[id]=step;
	if(id>=n)
	{
		return;
	}
	for(int i=id+1;a[i]-a[id]<=d;i++)
	{
		dfs(i,step+1);
	}
	return;
}
void dfs2(ll id,ll step)
{
	if(step>=minn[id])return;
	if(step==minn[id]&&f[id])ans++;
	if(step==minn[id])f[id]=1;
	if(id>=n)
	{
		return;
	}
	for(int i=id+1;a[i]-a[id]<=d;i++)
	{
		dfs2(i,step+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>test_number;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		memset(minn,0x3f3f,sizeof minn);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=0;
		dfs(1,0);
		dfs2(1,0);
//		for(int i=1;i<=n;i++)
//		{
//			cout<<minn[i]<<' ';
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
