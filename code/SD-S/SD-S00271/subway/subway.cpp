#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int tmp;
	scanf("%lld", &tmp);
	return tmp;
}
void writeln(int tmp)
{
	printf("%lld\n", tmp);
}
void writesp(int tmp)
{
	printf("%lld ", tmp);
}
int c, n, m, d, q;
const int M = 6e5 + 10, N = 1010, S = 3e3 + 10;
typedef pair<int, int> pii;
vector<pii> p[M];
int k[N], W[M];
struct node
{
	int v, w, next;
}a[N];
int head[N]; 
int cnt = 0;
void add(int u, int v, int w)
{
	a[cnt] = {v, w, head[u]};
	head[u] = cnt++;
}
int dis[S][S];
int ds[M];
bool vs[M];
bool vis[S][S];
void dij(int tu)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, tu});
	dis[tu][tu] = 0;
	while (q.size())
	{
		int u = q.top().second;
		q.pop();
		if (vis[tu][u])
		{
			continue;
		}
		vis[tu][u] = 1;
		for (int i = head[u]; ~i; i = a[i].next)
		{
			int v = a[i].v, w = a[i].w;
			if (dis[tu][v] > dis[tu][u] + w)
			{
				dis[tu][v] = dis[tu][u] + w;
				q.push({dis[tu][v], v});
			}
		}
	}
}
void dj(int tu)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, tu});
	ds[tu] = 0;
	while (q.size())
	{
		int u = q.top().second;
		q.pop();
		if (vs[u])
		{
			continue;
		}
		vs[u] = 1;
		for (int i = head[u]; ~i; i = a[i].next)
		{
			int v = a[i].v, w = a[i].w;
			if (ds[v] > ds[u] + w)
			{
				ds[v] = ds[u] + w;
				q.push({ds[v], v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(head, -1, sizeof(head));
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
	{
		W[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		k[i] = read();
		for (int j = 1; j <= k[i]; j++)
		{
			int t1 = read(), t2 = read();
			add(t1, i + m, t2);
			add(i + m, t1, t2);
		}
	}
	if (m < S)
	{
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++)
		{
			dij(i);
		}
		while (q--)
		{
			int x = read(), y = read();
			int ans = W[x] + W[y]; 
			writeln(ans + dis[x][y]);
		}
	}
	else
	{
		while (q--)
		{
			memset(ds, 0x3f, sizeof(ds));
			memset(vs, 0, sizeof(vs));
			int x = read(), y = read();
			int ans = W[x] + W[y];
			dij(x); 
			writeln(ans + ds[y]);
		}
	}
	return 0;
}

