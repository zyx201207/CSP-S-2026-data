#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 10;

typedef long long LL;

LL n, d;
LL f[N], g[N], sum;
LL x[N];
LL ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	LL c, T;
	cin >> c >> T;
	
	while (T -- )
	{
		ans = 0;
		
		cin >> n >> d;
		
		for (int i = 1; i <= n; i ++ )
			cin >> x[i];
		
		for (int i = 1; i <= n; i ++ )
		{
			memset(f, 0x3f, sizeof f);
			memset(g, 0x3f, sizeof g);
			
			f[i] = 1;
			g[i] = 0;
			
			int l, r;
			l = r = i;
			int res;
			
			for (int j = i + 1; j <= n; j ++ )
			{
				res = 0;
				while (l <= j && x[j] - x[l] > d) l ++ ;
				
				r = l;
				while (r <= j && g[r] == g[l]) res += f[r], r ++ ;
				g[j] = g[l] + 1;
				f[j] = res;
				if (res == 2)
					ans ++ ;
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}