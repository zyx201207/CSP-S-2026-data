# include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
long long f[N], a[N], q[N], flg[N], n, d;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
		while(t -- )
		{
			cin >> n >> d;
			for(int i = 1;i <= n;i ++ ) cin >> a[i];
			long long h = 1, t = 0, ans = 0;
			for(int i = 1;i <= n;i ++ )
			{
				h = 1, t = 0;
				for(int j = 1;j <= n;j ++ ) q[j] = 0, f[j] = 1e18, flg[j] = 1;
				f[i] = 1, q[ ++ t] = i;
				for(int j = i + 1;j <= n;j ++ )
				{
					if(a[j] - a[j - 1] > d) break;
					while(h <= t && a[j] - a[q[h]] > d) h ++ ;
					long long tmp = 0;
					for(int k = h;k <= t;k ++ ) 
					{
						if(f[q[k]] == f[q[h]]) tmp += flg[q[k]];
						if(tmp > 2)
						{
							flg[j] = 0;
							break;
						}
					}
					if(h <= t) 
					{
						flg[j] *= tmp;
						f[j] = min(f[j], f[q[h]] + 1);
						if(flg[j] == 2) ans ++ ;
					}
					while(h <= t && f[q[t]] > f[j]) t -- ;
					q[ ++ t] = j;
				}
			}
			
			cout << ans << "\n";
		}
	return 0;
}