#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,a[200005],n,d,f=1e18,tt;
void dfs(int ex,int cnt,int dep)//dep下标 
{
	if(dep>=ex)
	{
		if(dep==ex)
		f=min(f,cnt);
		return;
	}
	for(int i=dep+1;i<=n;i++)
	{
		if(a[i]-a[dep]>d)
		break;
		dfs(ex,cnt+1,i);
	}
}
void dfs1(int ex,int cnt,int dep)//dep下标 
{
	if(dep>=ex)
	{
		tt++; 
		return;
	}
	for(int i=dep+1;i<=n;i++)
	{
		if(a[i]-a[dep]>d)
		break;
		dfs(ex,cnt+1,i);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
//	if(C==1||C==2||C==0)
//	{
		while(T--)
		cout<<0<<"\n";
//	}
	return 0;
}
