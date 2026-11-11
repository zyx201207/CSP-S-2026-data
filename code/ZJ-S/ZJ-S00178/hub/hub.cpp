#include<bits/stdc++.h>
//#define int long long
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 7;
int c, t;
int n, k, ans;
struct EDGE
{
	int to, next;
}edge[N << 1];
int h[N], idx, vis[N];
int p[N];

void Add(int u, int v)
{
	edge[++idx] = {v, h[u]};
	h[u] = idx;
}

bool check()
{
	memset(vis, 0, sizeof vis);
	queue<int> q;
	for (int i = 1; i <= k; i++) vis[p[i]] = 1;
	q.push(p[1]); vis[1] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = h[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (vis[v]) q.push(v), vis[v] = 0;
		}
	}
	for (int i = 1; i <= k; i++) if (vis[p[i]])
	{
		q.push(p[i]); vis[p[i]] = 0;
		break;
	}
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = h[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (vis[v]) q.push(v), vis[v] = 0;
		}
	}
	for (int i = 1; i <= k; i++) if (vis[p[i]]) return 0;
	return 1;
}

int dis()
{
	memset(vis, 0, sizeof vis);
	queue<pii> q;
	int res = 0;
	for (int i = 1; i <= k; i++) q.push({p[i], 0}), vis[p[i]] = 1;
	while (!q.empty())
	{
		int u = q.front().first, w = q.front().second; q.pop();
		res = max(res, w);
		for (int i = h[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!vis[v]) q.push({v, w + 1}), vis[v] = 1;
		}
	}
	return res;
}

void dfs(int ct, int i)
{
	if (k + 1 == ct)
	{
		if (!check()) return ;
		int kk = dis();
		ans = min(kk, ans);
		return ;
	}
	for (int j = i; j <= n; j++) p[ct] = j, dfs(ct + 1, j + 1);
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		memset(h, 0, sizeof h), idx = 0; ans = INF;
		cin >> n >> k;
		for (int i = 1, u, v; i < n; i++) cin >> u >> v, Add(u, v), Add(v, u);
		dfs(1, 1);
		cout << ans << '\n';
	}
	return 0;
}
/*
先lca
对于所有的点，进行删除操作，每次找树的重心
二分最小约束 
*/
