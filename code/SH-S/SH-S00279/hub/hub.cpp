#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5;
int ct,t,n,k,f[N],ft[N],dis[N],ans = INT_MAX;
vector<int> g[N];
bool ls[N],vis[N];
int find()
{
	queue<int> q; int ret;
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	for (int i = 1; i <= n; i++)
		if (ls[i])
			q.push(i),dis[i] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		ret = dis[x];
		for (auto y:g[x])
			if (dis[y] > dis[x] + 1)
				q.push(y),dis[y] = dis[x] + 1;
	}
	return ret;
}
void check(int x,int fa)
{
	vis[x] = 1;
	for (auto y:g[x])
		if (y != fa && ls[y])
			check(y,x);
}
void dfs(int x,int pc)
{
	if (pc > k) return ;
	if (pc + n + 1 - x < k) return ;
	if (x > n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && ls[i])
				check(i,0),cnt++;
		if (cnt > 2) return ;
		ans = min(ans,find());
	}
	dfs(x + 1,pc);
	ls[x] = 1;
	dfs(x + 1,pc + 1);
	ls[x] = 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> ct >> t;
	while (t--)
	{
		cin >> n >> k; ans = INT_MAX;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}