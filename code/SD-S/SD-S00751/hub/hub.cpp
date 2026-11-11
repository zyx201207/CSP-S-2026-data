#include<bits/stdc++.h>
using ll=long long;
using namespace std;
using pii=pair<int,ll>;
const int N=105;

int n,k;
vector<int> G[N];
bool vis[N];

int dfs(int u,int fa)
{
	if(vis[u]) return 0;
	int mn=1e9;
	for(int v:G[u])
	{
		if(v==fa) continue;
		mn=min(mn,dfs(v,u));
	}
	return mn+1;
}

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(i>>(j-1)&1) cnt++,vis[j]=1;
			else vis[j]=0;
		if(cnt!=k) continue;
		int dis=0;
		for(int j=1;j<=n;j++)
			dis=max(dis,dfs(j,0));
		ans=min(ans,dis);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,_;cin>>cid>>_;
	while(_--) solve();
	return 0;
}

/*
为什么结尾要是爆炸呢 
*/
