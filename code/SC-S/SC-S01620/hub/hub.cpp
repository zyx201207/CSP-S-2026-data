#include<bits/stdc++.h>
#define cs const
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

int c,t,n,k;
cs int N=15;
vector<int> E[N];
int dis[N][N];
bool vis[N],tag[N];
void dfs0(int u,int f,int s)
{
	if(f) dis[s][u]=dis[s][f]+1;
	for(int v:E[u])
	{
		if(v==f) continue;
		dfs0(v,u,s);
	}
}
void dfs(int u,int f)
{
	vis[u]=1;
	for(int v:E[u])
	{
		if(v==f||!tag[v]) continue;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n>>k;
	fore(i,1,n) E[i].clear();
	fore(i,1,n-1)
	{
		int u,v;cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	fore(i,1,n)
	{
		dfs0(i,0,i);
	}
	int ans=1e18;
	fore(S,0,(1<<n)-1) if(__builtin_popcount(S)==k)
	{
		fore(i,1,n)
		{
			if((S>>(i-1))&1) tag[i]=1;
			else tag[i]=0;
			vis[i]=0;
		}
		int cnt=0;
		fore(i,1,n) if(tag[i]&&!vis[i])
		{
			cnt++;
			dfs(i,0);
		}
		if(cnt>2) continue;
		int res=0;
		fore(i,1,n) if(!tag[i])
		{
			int mind=1e18;
			fore(j,1,n) if(tag[j]) mind=min(mind,dis[i][j]);
			res=max(res,mind);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}

signed main()
{
#ifndef Debug
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#else
	freopen("hub2.in","r",stdin);
#endif
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
fin:18:03

exp:15
*/