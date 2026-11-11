#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 5010 + 10;
ll c, T, n, d, f[N][N], g[N][N], a[N], ans;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T --)
	{
		cin >> n >> d;
		ans = 0;
		for(ll i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for(ll i = 1; i <= n; i ++)
		{
			for(ll j = 1; j <= n; j ++)
			{
				f[i][j] = 100000000;
				g[i][j] = 0;
			} 
		}
		for(ll i = 1; i <= n; i ++)
		{
			for(ll j = i; j <= n; j ++)
			{
				if(a[j] - a[i] <= d) f[i][j] = g[i][j] = 1;
			} 
		}
		
		for(ll i = 1; i <= n; i ++)
		{
			for(ll j = i; j <= n; j ++)
			{
				for(ll k = i; k < j; k ++)
				{
					if(f[i][k] + f[k][j] < f[i][j])
					{
						f[i][j] = f[i][k] + f[k][j];
						g[i][j] = g[i][k] * g[k][j];
					}
					else if(f[i][k] + f[k][j] == f[i][j])
					{
						g[i][j] += g[i][k] * g[k][j];
					}
				}
			}
		}
		ans = 0;
		for(ll i = 1; i <= n; i ++)
		{
			for(ll j = i; j <= n; j ++)
			{
				if(g[i][j] == 2) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
