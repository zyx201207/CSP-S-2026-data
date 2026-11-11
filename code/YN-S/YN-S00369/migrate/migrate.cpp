#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=2e6+5;
int c,t,n;
ll d,ans;
ll x[MAXN];
bool vis[MAXN];
vector<int>g[MAXN];
vector<vector<ll>>cnt;
inline void dfs(int u,int st)
{
	for(int&v:g[u])
	{
		if(vis[v]||llabs(x[v]-x[u])>d)
			continue;
		cnt[st][v]++,vis[v]=true,dfs(v,st),vis[v]=false;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i],g[i].emplace_back(i-1);
		cnt.resize(n+1);
		for(int i=1;i<=n;i++)
			dfs(i,i);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(cnt[i][j]==2)
					ans++;
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
			g[i].clear(),vis[i]=false;
	}
	return 0;
}
