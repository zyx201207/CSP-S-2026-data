#include <iostream>
#include <queue>
#define ll long long
#define pii pair<ll, int>
using namespace std;
const int N = 510, M = 5e5 + 10, K = 10000010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int CASE, n, m, d, q;
ll c[M];
struct edge
{
	int nxt, to;
	ll val;
}s[K << 1];
int head[K], idx;
void add(int u, int v, ll w)
{
	s[++ idx] = {head[u], v, w};
	head[u] = idx;
}
ll dist[M + N];
int vis[M + N];
void dijkstra(int sta)
{
	priority_queue <pii, vector <pii>, greater <pii> > q;
	q.push({0, sta});
	for (int i = 1; i <= m + n; i ++) dist[i] = inf, vis[i] = 0;
	dist[sta] = 0;
	while (!q.empty())
	{
		pii t = q.top();
		q.pop();
		ll w1 = t.first;
		int u = t.second;
		if (vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for (int i = head[u]; i; i = s[i].nxt)
		{
			int v = s[i].to;
			ll w2 = s[i].val;
			if (dist[v] > w1 + w2)
			{
				dist[v] = w1 + w2;
				q.push({dist[v], v});
			} 
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> CASE >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++)
		{
			int a;
			ll t;
			cin >> a >> t;
			add(a, i + m, t);
			add(i + m, a, t);
		}
	}
	while (q --)
	{
		int u, v;
		cin >> u >> v;
		dijkstra(u);
		ll ans = c[u] + c[v] + dist[v];
		cout << ans << '\n';
	}
	return 0;
}

