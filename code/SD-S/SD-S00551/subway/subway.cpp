#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5010, INF = 1000000000000000007;
vector<pair<int, int> > G[N];
int w[N], dis[N], ans[N][N], m;
void make_edge(int u, int v, int w)
{
	G[u].push_back({v, w});
	G[v].push_back({u, w});

	return;
}
int cnt;
void dij(int st)
{
	for (int i = 1; i <= cnt; i += 1) dis[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

	dis[st] = 0; q.push({0, st});
	while (!q.empty())
	{
		int d = q.top().first, u = q.top().second; q.pop();
		if (dis[u] != d) continue;
		for (auto y: G[u])
		{
			int v = y.first, dd = y.second;
			if (dis[v] > (dis[u] + dd))
			{
				dis[v] = dis[u] + dd;
				q.push({dis[v], v});
			}
		}
	}

	for (int i = 1; i <= m; i += 1) ans[st][i] = dis[i];
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	int c, n, d, T;
	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; i += 1) cin >> w[i];

	cnt = m;
	for (int i = 1; i <= n; i += 1)
	{
		int num; cin >> num;
		for (int j = 1; j <= num; j += 1)
		{
			int idx, val; cin >> idx >> val;
			make_edge((cnt += 1), idx, val);
			if (j != 1) make_edge(cnt - 1, cnt, 0);
		}
	}

	for (int st = 1; st <= m; st += 1) dij(st);

	while (T--)
	{
		int x, y; cin >> x >> y;
		cout << w[x] + w[y] + ans[x][y] << endl;
	}
	return 0;
}
