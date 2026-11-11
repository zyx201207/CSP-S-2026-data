#include<bits/stdc++.h>

const int MAXN = 2e6 + 5;

typedef long long LL;

const LL inf = 5e18;

int cc, tt, n; LL d, x[MAXN];

LL f[MAXN], sum[MAXN], g[MAXN];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &cc, &tt), x[0] = -inf;
	while(tt--)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
				
		LL ans = 0;
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				sum[j] = 0;
			f[i] = sum[i] = 1, g[i] = 0;
			for(int j = i + 1; j <= n; j++)
			{
				LL _left = i, _right = j - 1, L = -1, R = -1;
				while(_left <= _right)
				{
					int mid = _left + ((_right - _left) >> 1);
					if(x[j] - x[mid] <= d)
						L = mid, _right = mid - 1;
					else _left = mid + 1;
				}
				
				if(L == -1) { g[j] = inf, f[j] = 0, sum[j] = sum[j - 1]; continue; }
				_left = i, _right = j - 1;
				while(_left <= _right)
				{
					int mid = _left + ((_right - _left) >> 1);
					if(g[mid] == g[L])
						R = mid, _left = mid + 1;
					else if(g[mid] < g[L])
						_left = mid + 1;
					else _right = mid - 1;
				} g[j] = g[L] + 1, f[j] = sum[R] - sum[L - 1], sum[j] = sum[j - 1] + f[j];
			}
			for(int j = i + 1; j <= n; j++)
				ans += (f[j] == 2);
		}
				
		printf("%lld\n", ans);
	}
	return 0;
}
