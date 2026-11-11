#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int a[maxn];
//int mp[maxn];
int dis[maxn],cnt[maxn];
int n,m;
int minn,ans;
void dfs(int u,int step)
{	
//	cout<<u<<" ";
	if(dis[u]<step)return;
	if(dis[u]>step)cnt[u]=0;
	dis[u]=min(dis[u],step);
	if(dis[u]==step)cnt[u]++;
	for(int i=n;i>=u+1;i--)
	{
		if(a[i]-a[u]<=m)
		{
			dfs(i,step+1);
		}
	}
	return;
}
void solve()
{
	ans=0;
	cin>>n>>m;
	int a_min=1e18;
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18;
		cnt[i]=0;
		cin>>a[i];
		a_min=min(a[i],a_min);
	}
	if(a_min<0)
	{
		for(int i=1;i<=n;i++)a[i]-=a_min,a[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
		for(int j=1;j<=n;j++)
		{
			if(cnt[j]==2)ans++;
			dis[j]=1e18;
			cnt[j]=0;
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_>>_;
	while(_--)
	{
		solve();
	}
	return 0;
} 
/*
0 1
4 2
1 2 3 4
1

0 1
5 2
1 2 3 4 5
2
*/
