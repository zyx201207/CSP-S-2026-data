#include<bits/stdc++.h>
using namespace std;
#define int long long

struct A
{
	int x, sum;
};

int c, m, n, d, q, b[500005], f[510][510];
vector<A> a[500005];

inline int read()
{
	char c;
	int sum = 0;
	while(c < '0' || c > '9') c = (char)getchar();
	while(c >= '0' && c <= '9') sum = sum * 10 + (int)(c - '0'), c = (char)getchar();
	return sum;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int n2 = read();
		for (int j = 1; j <= n2; j++)
		{
			int x, sum;
			x = read(), sum = read();
			a[x].push_back({i, sum});
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int n2 = (int)a[i].size();
		for (int j = 0; j < n2; j++)
			for (int k = 0; k < n2; k++)
				f[a[i][j].x][a[i][k].x] = min(f[a[i][j].x][a[i][k].x], a[i][j].sum + a[i][k].sum);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q--)
	{
		int u, v, ans = 1e18;
		u = read(), v = read();
		for (A i : a[u])
			for (A j : a[v])
				ans = min(ans, i.sum + j.sum + f[i.x][j.x]);
		printf("%lld\n", ans + b[u] + b[v]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}