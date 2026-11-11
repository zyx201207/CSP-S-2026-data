//16:22
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+10, NN = 2e6+10;
int C, x[NN], nxt[NN], f[N][N], g[N][N]; // f:length, g:types

void calc()
{
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(11 <= C && C <= 12)
	{
		int dx = x[2] - x[1];
		if(d < 2*dx)
		{
			cout << "0\n";
			return;
		}
		d /= dx;
		cout << max(0ll, n - 2*d + 1) << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) 
	{
		nxt[i] = upper_bound(x+1,x+n+1,x[i]+d)-x-1;
	}
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		f[i][j] = 1e18;
	}
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		g[i][j] = 0;
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0, g[i][i] = 1;
	for(int i = 1; i < n; i++) if(nxt[i] != i) f[i][i+1] = g[i][i+1] = 1;
	for(int l = 2; l < n; l++)
	{
		for(int i = 1; i + l <= n; i++)
		{
			int j = i + l;
			if(nxt[i] == i) f[i][j] = 0;
			else if(nxt[i] >= j) f[i][j] = g[i][j] = 1;
			else
			{
				int k = nxt[i], kw = f[k][j];
				if(nxt[i] - i == 1) 
				{
					f[i][j] = f[k][j] + 1, g[i][j] = g[k][j];
					continue;
				}
				
				int kc = k - 1, kcw = f[k-1][j];
				if(kcw > kw)
				{
					f[i][j] = kw + 1, g[i][j] = g[k][j];
					continue;
				}
				if(k - i == 2)
				{
					f[i][j] = kw + 1;
					g[i][j] = g[kc][j] + g[k][j];
					continue;
				}
				int kv = k-2, kvw = f[k-2][j];
				if(kvw == kcw)
				{
					f[i][j] = kw + 1, g[i][j] = 3;
					continue;
				}
				f[i][j] = kw + 1;
				g[i][j] = g[kc][j] + g[k][j];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	for(int j = i+1; j <= n; j++)
	{
		if(g[i][j]==2) ans++;
	}
	cout << ans << '\n';
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= n; j++)
//		cout << g[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << nxt[2];
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin >> C >> T;
	while(T--) calc();
	return 0;
}
// 16:51
/*
6 4
-3 0 1 2 3 4
*/
// 17:07 调好了 
// 17:23 性质A ok
// GOTO T4 
