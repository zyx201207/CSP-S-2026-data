#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

int c,t;

int n,k;
const int maxn = 1e6 + 10;
pii e[20];
int dis[maxn];
vector<int> G[maxn];

void solve_bl()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++) G[i].clear();
	for(int i = 1;i < n;i++) 
	{
		int u,v;cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[i] = {u,v};
	}
	
	int ans = 1e9;
	for(int S = 0;S < (1 << n);S++)
	{
		queue<int> q;
		for(int i = 1;i <= n;i++) dis[i] = 1e9;
		
		int bs = 0,ds = 0;
		for(int i = 1;i <= n;i++) if(S & (1 << (i - 1))) 
		{
			ds++;
			q.push(i);
			dis[i] = 0;
		}
		
		for(int i = 1;i < n;i++) 
		{
			int u = e[i].fi,v = e[i].se;
			if((S & (1 << (u-1)) ) && (S & (1 << (v-1)))) bs++;
		}
		
		if(ds - bs != 2) continue;
		if(ds != k) continue;
		
		while(q.size())
		{
			int u = q.front();
			q.pop();
			for(int v : G[u]) if(dis[v] == (int)(1e9))
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		
		int mx = 0;
		for(int i = 1;i <= n;i++) mx = max(mx,dis[i]);
		ans = min(ans,mx);
	} 
	cout << ans << '\n';
	return;
}

//int ans,f[maxn],g[maxn],dep[maxn],fat[maxn];
//void dfs(int u,int fa)
//{
//	dep[u] = dep[fa] + 1;
//	fat[u] = fa;
//	f[u] = g[u] = 1;
//	for(int v : G[u])
//	{
//		if(v == fa) continue;
//		dfs(v,u);
//		if()
//	}
//}
//void solve(int id)
//{
//	dfs(id,0);
//	
//}
//void sol()
//{
//	cin >> n >> k;
//	for(int i = 1;i <= n;i++) G[i].clear();
//	ans = 1e9;
//	
//	for(int i = 1;i < n;i++)
//	{
//		int u,v;cin >> u >> v;
//		G[u].push_back(v);
//		G[v].push_back(u);
//	}
//	
//	for(int i = 1;i <= n;i++) solve(i);
//	cout << ans << '\n';
//	return 0;
//}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	if(c <= 3) 
	{
		while(t--) solve_bl();
		return 0;
	}
//	if(c == 7 || c == 11 || c == 12)
//	{
//		while(t--) sol();
//		return 0;
//	}
	return 0;
}
