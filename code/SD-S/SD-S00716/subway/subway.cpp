#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e2 + 10;
const int M = 5e5 + 10;
const ll INF = 1e18;

struct node { int v, w; };

int n;
ll w[M];
ll to[N][N], f[N][N];
bitset<N> vis;
vector<node> t[M]; // j 能到的路线及其 t[i][j]
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> cnt;

void dij(int x)
{
	while (!cnt.empty()) cnt.pop();
	vis.reset();
	cnt.push({0, x});
	f[x][x] = 0;
	while (!cnt.empty())
	{
		auto u = cnt.top().second;
		cnt.pop();
		if (vis[u]) continue ;
		vis[u] = true;
		for (int i = 1; i <= n; i++)
		{
			if (f[x][i] > f[x][u] + to[u][i])
			{
				f[x][i] = f[x][u] + to[u][i];
				if (!vis[i]) cnt.push({f[x][i], i});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1, s, val; j <= k; j++)
		{
			cin >> s >> val;
			t[s].push_back({i, val});
		}
	}
	memset(to, 0x3f, sizeof to);
	for (int i = 1; i <= m; i++)
		for (auto u : t[i])
			for (auto v : t[i])
				to[u.v][v.v] = min(to[u.v][v.v], 0ll + u.w + v.w);
				
    //#################### 全源最短路
    memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) dij(i);
				
	for (int i = 1, x, y; i <= q; i++)
	{
		cin >> x >> y;
		ll ans = INF;
		for (auto u : t[x])
			for (auto v : t[y])
				ans = min(ans, u.w + v.w + f[u.v][v.v]);
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/

