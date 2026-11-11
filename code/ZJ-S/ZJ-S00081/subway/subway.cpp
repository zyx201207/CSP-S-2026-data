#include<bits/stdc++.h>
using namespace std;
int l, n, m, d, q, w[250001];
int h[300001], to[500001], nxt[500001], val[500001], cnt = 0;
void add(int u, int v, int c)
{
	cnt++;
	val[cnt] = c;
	to[cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
}
int que[500001], f, e;
long long dis[300001];
void spfa(int s, int t)
{
	f = e = 0;
	que[e] = s;
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;
	while (f <= e)
	{
		int u = que[f++];
		for (int i = h[u]; i != 0; i = nxt[i])
		{
			
			int v = to[i], c = val[i];
			if (dis[v] > dis[u] + c || dis[v] == -1)
			{
				que[++e] = v;
				dis[v] = dis[u] + c;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> l >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		scanf ("%d", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf ("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			int v, c;
			scanf ("%d%d", &v, &c);
			add(m + i, v, c);
			add(v, m + i, c);
		}
	}
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		spfa(u, v);
		cout << dis[v] + w[u] + w[v] << '\n';
	}
	return 0;
}