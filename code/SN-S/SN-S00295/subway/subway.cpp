#include<bits/stdc++.h>

const int MAXM = 5e5 + 5, MAXN = 500 + 5, MAXD = 20 + 5;

typedef long long LL; const LL inf = 9e18;

int cc, n, m, dd, q, w[MAXM], k[MAXN];

std::vector<int> a[MAXN], t[MAXN];

LL d[MAXN][MAXN]; int S[MAXM][MAXD], I[MAXM][MAXD], tot[MAXM];

inline int read()
{
	int ans = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) f = (ch == '-' ? -1 : f), ch = getchar();
	while(isdigit(ch)) ans = (ans << 1) + (ans << 3) + (ch ^ 48), ch = getchar();
	return ans * f;
}

inline void write(LL x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cc = read(), n = read(), m = read(), dd = read(), q = read();
	for(int i = 1; i <= m; i++)
		w[i] = read();
	for(int i = 1; i <= n; i++)
	{
		k[i] = read(); a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for(int j = 1; j <= k[i]; j++)
			a[i][j] = read(), t[i][j] = read(), S[a[i][j]][++tot[a[i][j]]] = i, I[a[i][j]][tot[a[i][j]]] = j;
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			d[i][j] = d[j][i] = inf;
			
	for(int i = 1; i <= m; i++)
	{
		int limit = tot[i];
		for(int j = 1; j < limit; j++)
			for(int k = j + 1; k <= limit; k++)
				d[S[i][j]][S[i][k]] = d[S[i][k]][S[i][j]] = std::min(d[S[i][j]][S[i][k]], 1ll * t[S[i][j]][I[i][j]] + t[S[i][k]][I[i][k]]);
	}
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(d[i][k] != inf && d[k][j] != inf)
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
					
	for(int _ = 1, u, v; _ <= q; _++)
	{
		u = read(), v = read(); LL ans = inf;
		
		for(int i = 1; i <= tot[u]; i++)
			for(int j = 1; j <= tot[v]; j++)
				ans = std::min(ans, d[S[u][i]][S[v][j]] + t[S[u][i]][I[u][i]] + t[S[v][j]][I[v][j]]);
		ans += w[u] + w[v];
		
		write(ans); putchar('\n');
	}
	
	return 0;
}
