#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int n, d, x[N], dis[N][N], cnt[N][N], ans; 
void solve()
{
	cin >> n >> d;
	ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> x[i];
		for(int j = 1 ; j <= n ; j ++)
		{
			dis[i][j] = 1e18;
			cnt[i][j] = 0;
		}
		dis[i][i] = 1;
		cnt[i][i] = 1;
		dis[i - 1][i] = 1;
		cnt[i - 1][i] = 1;
	}
	int tmp = x[1];
	for(int i = 1 ; i <= n ; i ++) x[i] -= tmp;
	for(int i = 1 ; i < n ; i ++)
	{
		for(int j = i + 2 ; j <= n ; j ++)
		{
			int plc = lower_bound(x + i, x + j, x[j] - d) - x;
			if(plc == i)
			{
				dis[i][j] = 1;
				cnt[i][j] = 1;
				continue;
			}
			dis[i][j] = dis[i][plc - 1] + 1;
			for(int k = plc ; k < j ; k ++)
			{
				cnt[i][j] += cnt[i][k];
			}
			if(cnt[i][j] == 2) ans ++;
		}
	}
	cout << ans << '\n';
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1; cin >> T >> T;
	while(T --) solve();
	return 0;
}

