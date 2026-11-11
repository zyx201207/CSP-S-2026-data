#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 507;
const int maxm = 5e5 + 7;

int n, m, d;

LL w[maxm];
vector <pair <int, LL> > t[maxm];

LL dis[maxn][maxn];
struct edge
{
	int to;
	LL val;
};
vector <edge> e[maxn];

bool vis[maxn];
priority_queue <pair <LL, int>, vector <pair <LL, int> >, greater <pair <LL, int> > > pq;

void dijikstra(int s)
{
	dis[s][s] = 0;
	memset(vis, 0, sizeof(vis));
	pq.push({0, s});
	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;
		for (edge nxt : e[cur])
		{
			if (dis[s][cur] + nxt.val < dis[s][nxt.to])
			{
				dis[s][nxt.to] = dis[s][cur] + nxt.val;
				pq.push({dis[s][nxt.to], nxt.to});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++)
		{
			int a;
			LL tim;
			cin >> a >> tim;
			t[a].push_back({i, tim});
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i != j) dis[i][j] = 1e18;
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 0; j < t[i].size(); j ++)
		{
			for (int k = j + 1; k < t[i].size(); k ++)
			{
				int p1 = t[i][j].first, p2 = t[i][k].first;
				dis[p1][p2] = dis[p2][p1] = t[i][j].second + t[i][k].second;
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (dis[i][j] != 1e18) e[i].push_back({j, dis[i][j]}), e[j].push_back({i, dis[i][j]});
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i != j) dis[i][j] = 1e18;
	for (int i = 1; i <= n; i ++) dijikstra(i);
	while (q --)
	{
		int x, y;
		cin >> x >> y;
		LL ans = 1e18;
		for (int i = 0; i < t[x].size(); i ++)
		{
			for (int j = 0; j < t[y].size(); j ++)
			{
				int p1 = t[x][i].first, p2 = t[y][j].first;
				ans = min(ans, dis[p1][p2] + t[x][i].second + t[y][j].second);
			}
		}
		ans += (w[x] + w[y]);
		cout << ans << '\n';
	}
	return 0;
}

/*
也许能过吧，常数不大了其实
差不多一共要跑 1.4e8 次
RP ++;
RP ++;
RP ++;
RP ++;
RP ++;
*/