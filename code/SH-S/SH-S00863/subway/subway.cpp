#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int N = 510;
const int M = 5e5 + 10;

struct line
{
	int n, t;
};

int c, n, m, d, q;
int idx, w[M];
bool vis[N];
ll dist[N], ans[N][N];
ll tg[N][N];
vector<pii> g[2 * M];
vector<line> lines[M];

void fxkmin(ll &a, ll b)
{
	a = min(a, b);
	return;
}

void dijkstra(int st)
{
	priority_queue<pli, vector<pli>, greater<pli>> q;
	memset(vis, 0, sizeof vis);
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	q.push({0, st});
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
//		cout << u << "\n";
		for (int v = 1; v <= n; ++v)
		{
			ll w = tg[u][v];
			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
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
	
	cin >> c >> n >> m >> d >> q;
	idx = m;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		++idx;
		for (int j = 1; j <= k; ++j)
		{
			int a, t;
			cin >> a >> t;
			g[a].push_back({t, idx});
			g[idx].push_back({t, a});
			lines[a].push_back({i, t});
		}
	}
	memset(tg, 0x3f, sizeof tg);
	for (int i = 1; i <= m; ++i)
	{
		for (int x = 0; x < (int)lines[i].size(); ++x)
		{
			for (int y = x + 1; y < (int)lines[i].size(); ++y)
			{
				line a = lines[i][x];
				line b = lines[i][y];
				ll d = a.t + b.t;
				fxkmin(tg[a.n][b.n], d);
				fxkmin(tg[b.n][a.n], d);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		dijkstra(i);
		ans[i][i] = 0;
		for (int j = 1; j <= n; ++j)
		{
			ans[i][j] = dist[j];
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ll minn = INT64_MAX;
		for (line st : lines[x])
		{
			for (line ed : lines[y])
			{
				ll tmp = ans[st.n][ed.n];
				tmp += st.t + ed.t;
				minn = min(minn, tmp);
			}
		}
		cout << minn + w[x] + w[y] << "\n";
	}
	return 0;
}
 
