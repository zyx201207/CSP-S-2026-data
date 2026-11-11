#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 510, M = 8e5 + 10, K = 510, INF = 0x3f3f3f3f3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int n, m, q;
int a[N];
int len[K][N];
bool t[N];
void add(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
void spfa(int st)
{
	memset(t, 0, sizeof t);
	int a = st - m;
	queue<int> q;
	q.push(st);
	t[st] = 1;
	len[a][st] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		t[u] = 0;
		for (int i = h[u]; ~i; i = ne[i])
		{
			int v = e[i], siz = w[i];
			if (len[a][v] > len[a][u] + siz)
			{
				len[a][v] = len[a][u] + siz;
				if (!t[v])
				{
					q.push(v);
					t[v] = 1;
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(len, 0x3f, sizeof len);
	memset(h, -1, sizeof h);
	int c, d;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
	{
		int k;
		int u = m + i;
		cin >> k;
		for (int j = 1; j <= k; j ++)
		{
			int v, w;
			cin >> v >> w;
			add(u, v, w), add(v, u, w);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		int u = m + i;
		spfa(u);
	}
	while (q --)
	{
		int u, v;
		cin >> u >> v;
		int ans = a[u] + a[v];
		int sum = INF;
		for (int i = 1; i <= n; i ++)
			if (sum > len[i][u] + len[i][v])
				sum = len[i][u] + len[i][v];
		ans += sum;
		cout << ans << "\n";
	}
	return 0;
}
