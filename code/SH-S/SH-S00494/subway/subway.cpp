#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii; // first是编号，second是站台距离 
constexpr int MAXN = 5e5 + 5;
constexpr int MAXM = 20 + 2;
constexpr int MAXQ = 1e5 + 5;

int c;
int n; // 站点数
int m; // 线路数 
int d, q;
vector<int> a[MAXM];
struct station
{
	int w;
	unordered_map<int, int> t;
} s[MAXN];
pii r[MAXQ]; // 出行计划 
vector<pii> e[MAXN]; // 边集数组 

void add(int u, int v, int w)
{
	e[u].push_back({v, w});
//	e[v].push_back({u, w});
} 

int dis[MAXM][MAXN];

void spfa(int st)
{
	memset(dis, 0x3f, sizeof(dis));
	bitset<MAXN> vis;
	queue<pii> q;
	for (auto it :s[st].t)
	{
		dis[it.first][st] = it.second;
		vis[st] = true;
		q.push({it.first, st});
	}
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		const int u = t.second, f = t.first;
		vis[u] = false;
		for (auto i : e[u])
		{
			const int v = i.first, w = i.second;
			if (w == f)
				dis[w][v] = min(dis[w][v], dis[w][u]);
			else
				dis[w][v] = min(dis[w][v], dis[f][u] + s[u].t[w] + s[u].t[f]);
			if (!vis[v])
				q.push({w, v}), vis[v] = true;
//			cerr << u << " to " << v << ", line " << f << " to " << w << ", dis " << dis[w][v] << endl;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i].w;
	for (int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			a[i].push_back(x);
			if (j != 0)
				add(a[i][j - 1], x, i);
			s[x].t[i] = y;
		}
	}
	for (int i = 1; i <= q; i++)
		cin >> r[i].first >> r[i].second;
	for (int i = 1; i <= q; i++)
	{
		spfa(r[i].first);
		int mn = LLONG_MAX;
		const int add = s[r[i].first].w + s[r[i].second].w;
		for (int j = 1; j <= m; j++)
			mn = min(mn, dis[j][r[i].second] + add + s[r[i].second].t[j]);
		cout << mn << "\n";
	}
	for (int i = 1; i <= n; i++)
		for (auto j :e[i])
//			cerr << i << " " << j.first << " " << j.second << endl;
	return 0;
}
