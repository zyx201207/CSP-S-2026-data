#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5, M = 1005, W = 50005;

struct Edge
{
	int v, w;
};

int c, t, n, d, cur;
int x[N], dist[M][M], cnt[M][M];
int id[W], len[W], dist2[W], cnt2[W];
vector<Edge> g[W];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

struct seg_tree
{
	struct node
	{
		int l, r;
	} tr[4 * N];
	void build(int p, int l, int r)
	{
		tr[p] = {l, r};
		len[p] = r - l + 1;
		cur = max(cur, p);
		if (l == r)
		{
			id[l] = p;
			return;
		}
		int mid = (l + r) >> 1;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
		g[p].push_back({p * 2, 0});
		g[p].push_back({p * 2 + 1, 0});
	}
	void modify(int p, int l, int r, int k)
	{
		if (l > r) return;
		if (l <= tr[p].l && tr[p].r <= r)
		{
			g[k].push_back({p, 1});
			return;
		}
		int mid = (tr[p].l + tr[p].r) >> 1;
		if (l <= mid) modify(p * 2, l, r, k);
		if (r > mid) modify(p * 2 + 1, l, r, k);
	}
} ST;

int bfs(int st)
{
	memset(dist2, 0x3f, sizeof(dist2));
	memset(cnt2, 0, sizeof(cnt2));
	deque<int> dq;
	dq.push_front(id[st]), dist2[id[st]] = 0, cnt2[id[st]] = 1;
	while (dq.size())
	{
		int u = dq.front();
		dq.pop_front();
		for (Edge v : g[u])
		{
			if (dist2[v.v] > dist2[u] + v.w)
			{
				dist2[v.v] = dist2[u] + v.w;
				cnt2[v.v] = cnt2[u];
				if (!v.w) dq.push_front(v.v);
				else dq.push_back(v.v);
			}
			else if (dist2[v.v] == dist2[u] + v.w)
			{
				dist2[v.v] = dist2[u] + v.w;
				cnt2[v.v] += cnt2[u];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (cnt2[id[i]] == 2) res += len[id[i]];
	return res;
}

void solve()
{
	n = read(), d = read();
	for (int i = 1; i <= n; i++)
		x[i] = read();
	if (n == 1)
	{
		printf("0\n");
		return;
	}
	if (c <= 6)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = 1e9, cnt[i][j] = 0;
		for (int i = 1; i <= n; i++)
			dist[i][i] = 0, cnt[i][i] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (x[j] - x[i] <= d) dist[i][j] = cnt[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = i + 1; k < j; k++)
				{
					if (dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						cnt[i][j] = cnt[i][k] * cnt[k][j];
					}
					else if (dist[i][j] == dist[i][k] + dist[k][j])
					{
						cnt[i][j] += cnt[i][k] * cnt[k][j];
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (cnt[i][j] == 2) ans++;
		printf("%lld\n", ans);
	}
	else if (c == 11 || c == 12)
	{
		int dd = x[2] - x[1];
		if (dd > d + 1)
		{
			printf("0\n");
			return;
		}
		int len = d / dd;
		if (len == 1)
		{
			printf("0\n");
			return;
		}
		len = len * 2 - 1;
		printf("%lld\n", max(0ll, n - len));
	}
	else
	{
		ST.build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			int r = upper_bound(x + i, x + n + 1, x[i] + d) - x - 1;
			ST.modify(1, i + 1, r, id[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += bfs(i);
		printf("%lld\n", ans);
		for (int i = 1; i <= cur; i++)
			g[i].clear();
		cur = 0;
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) solve();
	return 0;
}

/*
24pts at 16:30
32pts at 17:27
*/