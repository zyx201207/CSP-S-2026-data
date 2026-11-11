#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 999999999999999999ll;
int n, x[2000005], c, t, d, f[5005][5005], g[5005][5005], pre[2000005];
vector<int> v;
int p;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		p = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
			while(p < i && x[i]-x[p] > d) p++;
			pre[i] = p;
		}
		int A = 1;
		for(int i = 2; i <= n; i++)
			if(x[i]-x[i-1] != x[2]-x[1])
				A = 0; 
		if(A)
		{
			int k = d/(x[2]-x[1]);
			if(k < 2)
			{
				cout << 0 << '\n';
//				continue;
			}
			else cout << max(0ll, n-2*k+1) << '\n';
			continue;
		}
		if(n <= 5000)
		{
//			cout << n << ' ' << d << '\n'; 
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
//				cout << x[i] << ' ';
				f[i][i] = 0;
				g[i][i] = 1;
				for(int j = i+1; j <= n; j++)
				{
					f[i][j] = inf;
					g[i][j] = 1;
				}
			}
//			cout << '\n';
			for(int l = 1; l <= n; l++)
			{
				for(int r = l+1; r <= n; r++)
				{
					for(int k = max(l, pre[r]); k < min(pre[r]+3, r); k++)
					{
						if(f[l][r] > f[l][k]+1)
						{
							f[l][r] = f[l][k]+1;
							g[l][r] = g[l][k];
						}
						else if(f[l][r] == f[l][k]+1)
						{
							g[l][r] += g[l][k];
							g[l][r] = min(g[l][r], 3ll);
						}
					}
					if(g[l][r] == 2) cnt++;
//					cout << l << ' ' << r << ' ' << g[l][r] << '\n';
				}
			}
			cout << cnt << '\n';
			continue;
		}
		cout << 0 << '\n'; 
//		l = 1;
//		r = 1;
//		int ans = 0;
//		while(r <= n)
//		{
//			while(r < n && x[r+1]-x[r] <= d) r++;
//			v.clear();
//			for(int i = l; i <= r; i++)
//				if(i == l || i == r || x[i+1]-x[i-1] <= d)
//					v.push_back(i);
//			for(int i = 1; i < v.size()-1; i++)
//				ans += (v[i+1]-v[i])*(v[i]-v[i-1])+(v[i+1]-v[i-1]);
//			l = r = r+1; 
//		}
//		cout << ans << '\n';
	}
	return 0;
}

