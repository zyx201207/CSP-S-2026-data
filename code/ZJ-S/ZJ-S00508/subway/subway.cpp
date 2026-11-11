#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
#define pii pair<ll, ll>
#define mkp(x, y) make_pair(x, y)
#define pl p << 1
#define pr p << 1 | 1
using namespace std;
constexpr ll MOD = 998244353ll, inf = 1ll << 60;
//bool st;
ll Case, tt;
ll n, m, k, qq;
ll w[500010];
ll dis[10010][10010];
vector<pii> t[500010];
vector<pii> G[10010];
vector<vector<pii>> a;
struct node
{
	ll x, d;
	bool operator < (const node &t) const
	{
		return d > t.d;
	}
};
//bool ed;

void solve()
{
	cin >> n >> m >> k >> qq;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		ll cnt;
		cin >> cnt;
		a[i].resize(cnt + 1);
		for (int j = 1; j <= cnt; j++)
		{
			cin >> a[i][j].first >> a[i][j].second;
			ll u = i;
//			ll u = (ll)t[a[i][j].first].size() * m + a[i][j].first;
			for (int k = 0; k < t[a[i][j].first].size(); k++)
			{
				ll v = t[a[i][j].first][k].first;
				ll w = a[i][j].second + a[t[a[i][j].first][k].first][t[a[i][j].first][k].second].second;
				G[u].push_back(mkp(v, w));
				G[v].push_back(mkp(u, w));
//				ll v = k * m + a[i][j].first;
//				ll w = a[i][j].second + a[t[a[i][j].first][k].first][t[a[i][j].first][k].second].second;
//				G[u].push_back(mkp(v, w));
//				G[v].push_back(mkp(u, w));
			}
//			if (j > 1)
//			{
//				ll v = ((ll)t[a[i][j - 1].first].size() - 1) * m + a[i][j - 1].first;
////				D(v), DE(u);
//				G[v].push_back(mkp(u, 0ll));
//				G[u].push_back(mkp(v, 0ll));
//			}
			t[a[i][j].first].push_back(mkp(i, j));
		}
	}
	for (int s = 1; s <= n; s++)
	{
		for (int e = 1; e <= n; e++)
			dis[s][e] = inf;
		priority_queue<node> q;
		q.push(node{s, dis[s][s] = 0});
		while (q.size())
		{
			ll u = q.top().x, d = q.top().d; q.pop();
			if (d > dis[s][u])
				continue;
			for (auto x : G[u])
				if (dis[s][x.first] > dis[s][u] + x.second)
					q.push(node{x.first, dis[s][x.first] = dis[s][u] + x.second});
		}
	}
	while (qq--)
	{
		ll s, e;
		cin >> s >> e;
		ll res = w[s] + w[e];
		ll mn = inf;
		for (int i = 0; i < t[s].size(); i++)
		{
			ll u = t[s][i].first;
			for (int j = 0; j < t[e].size(); j++)
			{
				ll v = t[e][j].first;
				mn = min(mn, dis[u][v] + a[t[s][i].first][t[s][i].second].second + a[t[e][j].first][t[e][j].second].second);
			}
//			D(u), DE(dis[u]);
		}
		cout << res + mn << '\n';
	}
}

int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (cin >> Case, tt = 1; tt--; )
		solve();
//	cout << (&st - &ed) / 1024 / 1024;
	return 0;
}