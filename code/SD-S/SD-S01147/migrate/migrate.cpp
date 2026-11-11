#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
typedef long long ll;

int C, T;
int n;
ll d;
int pre[N];
ll h[N];
int f[N][N], g[N][N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T --)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i ++) scanf("%lld", &h[i]);
		for (int i = n, j = n; i; i --)
		{
			while (j > 1 && h[i] - h[j - 1] <= d) j --;
			pre[i] = j;
		}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) g[i][j] = 0x3f3f3f3f, f[i][j] = 0;
		for (int i = 1; i <= n; i ++) g[i][i] = 0, f[i][i] = 1;
		for (int l = 1; l <= n; l ++)
			for (int r = l + 1; r <= n; r ++)
				g[l][r] = min(g[l][r], g[l][max(l, pre[r])] + 1);
				
		for (int len = 2; len <= n; len ++)
			for (int l = 1; l + len - 1 <= n; l ++)
			{
				int r = l + len - 1;
				for (int k = l; k < r; k ++)
					if (h[r] - h[k] <= d && g[l][k] + 1 == g[l][r])
						f[l][r] = min(3, f[l][r] + f[l][k]);
			}
		ll res = 0;
		for (int l = 1; l <= n; l ++)
			for (int r = l + 1; r <= n; r ++)
				if (f[l][r] == 2) res ++;
		printf("%lld\n", res);
	}
	
	return 0;
}
