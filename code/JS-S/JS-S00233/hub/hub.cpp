//So breathe for a minute,breathe for a minute
//I'll be ok
#include <bits/stdc++.h>
using namespace std;

int n,k;

const int N = 1e6 + 5;

vector < int > g[N];

int lowbit(int x)
{
	return (x & (-x));
}

int pct(int x)
{
	int ret = 0;
	while (x)
	{
		x -= lowbit(x);
		ret++;
	}
	return ret;
}

int fa[N],dis[105][105];

int get(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void merge(int x,int y)
{
	x = get(x),y = get(y);
	if (x != y) fa[y] = x;
}

bool vis[N];

bool check(int s)
{
	for (int i = 1;i <= n;i++)
		fa[i] = i,vis[i] = 0;
	for (int i = 1;i <= n;i++)
		if (s & (1 << (i - 1)))
		{
			for (auto v : g[i])
				if (s & (1 << (v - 1))) merge(i,v);
		}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (s & (1 << (i - 1))) cnt += (vis[get(i)] == 0),vis[get(i)] = 1;
	if (cnt <= 2) return 1;
	return 0;
}

void dfs(int now,int u,int fa)
{
	dis[now][u] = dis[now][fa] + 1;
	for (auto v : g[u])
		if (v != fa) dfs(now,v,u);
}

void solve(int c)
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		g[i].clear();
	for (int i = 1;i < n;i++)
	{
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n <= 10)
	{
		int ans = INT_MAX;
		for (int i = 1;i <= n;i++)
			dis[i][0] = -1,dfs(i,i,0);
		for (int s = 1;s < (1 << n);s++)
			if (pct(s) == k && check(s))
			{
				int t = 0;
				for (int i = 1;i <= n;i++)
				{
					int now = INT_MAX;
					for (int j = 1;j <= n;j++)
						if (s & (1 << (j - 1))) now = min(now,dis[i][j]);
					t = max(t,now);
				}
				ans = min(ans,t);
			}
		cout << ans << endl;
	}
	
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin >> c >> t;
	for (;t > 0;t--)
		solve(c);
	return 0;
}
