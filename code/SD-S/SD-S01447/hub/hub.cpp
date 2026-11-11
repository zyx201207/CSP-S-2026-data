#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define inf 1e18
using namespace std;
vector<int>g[510];
int vis[510];
int n,k;
int lowbit(int x)
{
	return x&-x;
}
bool check(int x)
{
	int cnt=0;
	while(x)cnt++,x-=lowbit(x);
	return cnt==k;
}
void dfs(int x,int w,int fa)
{
	if(vis[x]>w)vis[x]=w;
	else return;
	for(auto i:g[x])
	{
		if(i==fa)continue;
		dfs(i,w+1,x);
	}
}
void solve()
{
	memset(g,0,sizeof(g));
	memset(vis,0x3f,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<(2<<k);i++)
	{
		if(check(i))continue;
		for(int j=0;j<n;j++)
		{
			if((1<<j)&i)
			{
				dfs(j+1,0,j);
			}
		}
		int res=0;
		for(int j=1;j<=n;j++)
		{
			res=max(res,vis[j]);
		}
		ans=min(res,ans);
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(1); 
//	int c,t;
//	cin>>c>>t;
//	while(t--)
//	{
//		solve();
//	}
	return 0;
}
/*
作者大大给我选进去吧
真服了最后没时间了
uid：16947747 
天上的星星不说话	地下的孩子想妈妈
肚子飞	肚子飞	肚子你要飞 
*/

