#include <bits/stdc++.h>
#define Int long long
using namespace std;

const int N = 2e6 + 10;
const int INF = 1e9 + 10;

int n, ans = INF; bool st[N], vis[N];
vector <int> g[N];

void Reset()
{
	for (int i = 1 ; i < N; i++) g[i].clear();
	return;
}

void dfs (int k, int x)
{
	if (k == 0)
	{
		queue <int> q;
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) if (st[i]) q.push(i), vis[i] = true;
		int cnt = -1;
		while (!q.empty())
		{
			cnt++;
			int tot = q.size();
			while (tot--)
			{
				int top = q.front();
				q.pop();
				for (int v : g[top])
				{
					if (!vis[v]) q.push(v), vis[v] = true;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (st[i]) continue;
		int flag = 0;
		for (int v : g[i])
		{
			if (st[v])
			{
				flag = 1;
				break;
			}
		}
		if (!flag && x == 0) continue;
		st[i] = true;
		dfs(k - 1, x - (flag ^ 1));
		st[i] = false;
	}
	return;
}

void solve()
{
	Reset(); ans = INF;
	int k; cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(k, 2);
	cout << ans << '\n';
	return;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, T = 1; cin >> c >> T;
	while (T--) solve();
	return 0;
}

//17:36,Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh NoTime!

