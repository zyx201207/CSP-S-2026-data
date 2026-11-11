#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
vector<int> g[1005];
ll x[N];
int vis[1005][1005], dis[1005][1005], cnt[1005][1005];
void bfs(int st)
{
	dis[st][st] = 0, cnt[st][st] = 1;
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (vis[st][x])
			continue;
		vis[st][x] = 1;
		for (int i : g[x])
		{
			if (dis[st][i] > dis[st][x] + 1)
			{
				dis[st][i] = dis[st][x] + 1;
				cnt[st][i] = cnt[st][x];
				q.push(i);
			}
			else if (dis[st][i] == dis[st][x] + 1)
				cnt[st][i] += cnt[st][x];
		}
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
			for (int j = i; j <= n; j++)
				dis[i][j] = 0x3f3f3f3f, vis[i][j] = 0, cnt[i][j] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			for (int j = 1; j < i; j++)
				if (x[i] - x[j] <= d)
					g[j].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			bfs(i);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans += (cnt[i][j] == 2);
		cout << ans << '\n';
	}
	return 0;
}
