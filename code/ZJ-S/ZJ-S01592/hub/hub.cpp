#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+10;
vector<int> g[N];
int f[N], dep[N], dis[N], dp[N][35], n, k, ans;
bool used[N];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(int x, int fa)
{
	dep[x]=dep[fa]+1;
	dp[x][0]=fa;
	dis[x]=dis[fa]+1;
	for(int i=1;i<=30;i++)
		dp[x][i]=dp[dp[x][i-1]][i-1];
	for(auto y:g[x])
		if(y!=fa) dfs(y, x);
}
int lca(int x, int y)
{
	if(dep[x]<dep[y]) swap(x, y);
	for(int i=30;i>=0;i--)
		if(dep[dp[x][i]]>=dep[y]) x=dp[x][i];
	if(x==y) return x;
	for(int i=30;i>=0;i--)
		if(dp[x][i]!=dp[y][i]) x=dp[x][i], y=dp[y][i];
	return dp[x][0];
}
void solve(int x, int cnt)
{
	if(x>n)
	{
		if(cnt<k) return ;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=n;i++)
		{
			if(!used[i]) continue;
			for(auto j:g[i]) if(used[j]) f[find(i)]=find(j);
		}
		set<int> se;
		for(int i=1;i<=n;i++)
			if(used[i]) se.insert(find(i));
		if(se.size()>2) return ;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int mn=1e18;
			for(int j=1;j<=n;j++)
			{
				if(!used[j]) continue;
				mn=min(mn, dis[i]+dis[j]-2*dis[lca(i, j)]);
			}
			res=max(res, mn);
		}
		ans=min(ans, res);
		return ;
	}
	solve(x+1, cnt);
	if(cnt<k) used[x]=1, solve(x+1, cnt+1), used[x]=0;
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear(), dep[i]=dis[i]=dp[i][0]=0;
		for(int i=1, u, v;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dis[0]=-1;
		dfs(1, 0);
		solve(1, 0);
		cout<<ans<<'\n';
	}
	return 0;
}