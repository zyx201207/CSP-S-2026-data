#include <bits/stdc++.h>
#define int long long
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 15;
int c, T;
int n, k;
int count1(int x)
{
	int res = 0;
	while(x)
	{
		res += x & 1;
		x >>= 1;
	}
	return res;
}
vector<int> g[MAXN];
unordered_set<int> hub;
int p[MAXN];
int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
bool check()
{
	for(int u : hub)
	{
		for(int v : g[u])
		{
			if(hub.count(v))
			{
				int fu = find(u), fv = find(v);
				if(fu != fv) p[fv] = fu;
			}
		}
	}
	unordered_set<int> cnt;
	for(int i : hub) cnt.insert(p[i]);
	return cnt.size() <= 2;
}
int dist[MAXN];
void bfs(int st)
{
	queue<pair<int, int> > q;
	q.push({st, 0});
	while(!q.empty())
	{
		int u = q.front().first, t = q.front().second;
		q.pop();
		if(t >= dist[u]) continue;
		dist[u] = t;
		for(int v : g[u])
		{
			if(dist[v] > t + 1)
			{
				q.push({v, t + 1});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = LINF;
		for(int mask = 0; mask <= (1 << n) - 1; mask++)
		{
			if(count1(mask) != k) continue;
			hub.clear();
			for(int i = 1; i <= n; i++)
			{
				if((mask >> (i - 1)) & 1) hub.insert(i);
			}
			for(int i : hub) p[i] = i;
			if(!check()) continue;
			for(int i = 1; i <= n; i++) dist[i] = LINF;
			for(int i : hub) bfs(i);
			int cur = 0;
			for(int i = 1; i <= n; i++) cur = max(cur, dist[i]);
			ans = min(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}