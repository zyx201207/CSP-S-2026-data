#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define N 500005
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long

int c, n, m, d, q, arr[N];
int dp[505][505];
int vc_id[N][25], vc_val[N][25], num[N];

signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 );
	freopen( "subway.in", "r", stdin );
	freopen( "subway.out", "w", stdout );
	memset( dp, 0x3f, sizeof( dp ) );
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; i ++ ) cin >> arr[i];
	for ( int i = 1; i <= n; i ++ )
	{
		int k = 0;
		cin >> k;
		for ( int j = 1; j <= k; j ++ )
		{
			int x, y;
			cin >> x >> y;
			num[x] ++;
			vc_id[x][num[x]] = i, vc_val[x][num[x]] = y;
		}
	}
	for ( int i = 1; i <= m; i ++ )
	{
		for ( int j = 1; j <= num[i]; j ++ )
		{
			for ( int k = j + 1; k <= num[i]; k ++ )
			{
				dp[vc_id[i][j]][vc_id[i][k]] = vc_val[i][j] + vc_val[i][k];
				dp[vc_id[i][k]][vc_id[i][j]] = vc_val[i][j] + vc_val[i][k];
			}
		}
	}
	for ( int i = 1; i <= n; i ++ ) dp[i][i] = 0;
	for ( int k = 1; k <= n; k ++ )
	{
		for ( int i = 1; i <= n; i ++ )
		{
			for ( int j = 1; j <= n; j ++ )
			{
				if ( dp[i][k] == inf || dp[k][j] == inf ) continue;
				dp[i][j] = min( dp[i][k] + dp[k][j], dp[i][j] );
			}
		}
	}
	for ( int i = 1; i <= q; i ++ )
	{
		int x, y, ans = inf;
		cin >> x >> y;
		for ( int u = 1; u <= num[x]; u ++ )
		{
			for ( int v = 1; v <= num[y]; v ++ )
			{
				if ( dp[vc_id[x][u]][vc_id[y][v]] == inf ) continue;
				ans = min( ans, vc_val[x][u] + vc_val[y][v] + dp[vc_id[x][u]][vc_id[y][v]] );
			}
		}
		cout << ans + arr[x] + arr[y] << "\n";
	}
	return 0;
}