#include <bits/stdc++.h>
#define int long long
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 510;
const int MAXM = 5e5 + 10;
int T, n, m, d, q;
int toLand[MAXM];
vector<pair<int, int> > useLine[MAXN];
int k[MAXN];
int dist[MAXN][MAXN];
int toLine[MAXN][MAXN];
vector<int> g[MAXN];
void dijkstra(int st)
{
	for(int i = 1; i <= n; i++) toLine[st][i] = LINF;
	struct node{
		int v, t;
		bool operator < (const node &other) const {
			return t > other.t;
		}
	};
	priority_queue<node> q;
	q.push({st, 0});
	while(!q.empty())
	{
		int u = q.top().v, t = q.top().t;
		q.pop();
		if(toLine[st][u] <= t) continue;
		toLine[st][u] = t;
		for(int v = 1; v <= n; v++)
		{
			if(u != v && t + dist[u][v] < toLine[st][v])
			{
				q.push({v, t + dist[u][v]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> T >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> toLand[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			int a, t;
			cin >> a >> t;
			useLine[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dist[i][j] = LINF;
		}
	}
	for(int sta = 1; sta <= m; sta++)
	{
		for(pair<int, int> a : useLine[sta])
		{
			int i = a.first, t1 = a.second;
			for(pair<int, int> b : useLine[sta])
			{
				int j = b.first, t2 = b.second;
				if(i == j) dist[i][j] = 0;
				else if(dist[i][j] > t1 + t2) dist[i][j] = t1 + t2;
			}
		}
	}
	for(int i = 1; i <= n; i++) dijkstra(i);
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = LINF;
		for(pair<int, int> a : useLine[x])
		{
			for(pair<int, int> b : useLine[y])
			{
				ans = min(ans, a.second + b.second + toLine[a.first][b.first]);
			}
		}
		ans += toLand[x] + toLand[y];
		cout << ans << "\n";
	}
	return 0;
}