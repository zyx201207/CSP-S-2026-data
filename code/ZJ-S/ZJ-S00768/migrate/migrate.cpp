#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;

int n, m, a[N];

int dis[5005][5005], vis[5005][5005];
void solve1 ()
// n <= 5000
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	memset (dis, 0x3f, sizeof dis);
	memset (vis, 0, sizeof vis);
	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		int lst = i;
		vis[i][i] = 1;
		dis[i][i] = 0;
		for (int j = i + 1; j <= n; j ++)
		{
			while (lst < j && a[j] - a[lst] > m) lst ++;
//			cout << i << " " << j << " " << lst << "\n";
			dis[i][j] = min (dis[i][j], dis[i][lst] + 1);
			vis[i][j] = min (3ll, vis[i][lst] + (dis[i][lst + 1] == dis[i][lst] ? vis[i][lst + 1] : 0) + (dis[i][lst + 2] == dis[i][lst] ? vis[i][lst + 2] : 0));
			if (vis[i][j] == 2) ans ++;
		}
	}
//	for (int i = 1; i <= n; i ++)
//		for (int j = 1; j <= n; j ++)
//			cout << vis[i][j] << " \n"[j == n];
//	for (int i = 1; i <= n; i ++)
//		for (int j = 1; j <= n; j ++)
//			cout << dis[i][j] << " \n"[j == n];
	cout << ans << "\n";
}


signed main ()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
		
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	
	int c, T; cin >> c >> T;
	while (T --) solve1 ();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
