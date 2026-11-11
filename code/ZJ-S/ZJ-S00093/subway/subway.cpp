#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long int ll;
constexpr int N = 505, M = 5e5 + 5, INF = 0x3f3f3f3f, D = 20;

void read(ll &x);
void write(ll x);

int sub[M][D], wig[M][D];
ll c, n, m, d, q, k, u, v, slug, cat, w[M], cnt[M], G[N][N];

int main(void)
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	
	memset(G, INF, sizeof G);
	
	for (int i = 1; i <= n; i++) G[i][i] = 0;
	
	for (int i = 1; i <= m; i++) read(w[i]);
	
	for (int i = 1; i <= n; i++)
	{
		read(k);
		
		while (k --> 0)
		{
			read(slug);
			read(cat);
			cnt[slug]++;
			sub[slug][cnt[slug]] = i;
			wig[slug][cnt[slug]] = cat;
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= cnt[i]; j++)
		{
			for (int k = j + 1; k <= cnt[i]; k++)
			{
				ll u = sub[i][j], v = sub[i][k];
				G[u][v] = std::min(G[u][v], ll(wig[i][j]) + ll(wig[i][k]));
				G[v][u] = std::min(G[v][u], ll(wig[i][j]) + ll(wig[i][k]));
			}
		}
	}
	
	for (int k = 1; k <= n; k++)
	{
		for (int u = 1; u <= n; u++)
		{
			for (int v = 1; v <= n; v++)
			{
				if (u == v) continue;
				G[u][v] = std::min(G[u][v], G[u][k] + G[k][v]);
			}
		}
	}
	
	while (q --> 0)
	{
		read(u);
		read(v);
		ll ans = 0x3f3f3f3f3f3f3f3f;
		
		for (int i = 1; i <= cnt[u]; i++)
		{
			for (int j = 1; j <= cnt[v]; j++)
			{
				ll x = sub[u][i], y = sub[v][j];
				ans = std::min(ans, G[x][y] + wig[u][i] + wig[v][j]);
			}
		}
		
		ans += w[u] + w[v];
		write(ans);
		putchar('\n');
	}
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

void read(ll &x)
{
	x = 0;
	char ch = getchar();
	
	while (!isdigit(ch)) ch = getchar();
	
	while (isdigit(ch))
	{
		x = x * 10 + (ch ^ '0');
		ch = getchar();
	}
}

void write(ll x)
{
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ '0');
}

