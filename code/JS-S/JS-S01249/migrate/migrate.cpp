#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 300 + 5;
int TT = 1;
int a[N];
int f[N][N], g[N][N];

void solve()
{
	int c, T; cin >> c >> T;
	while (T--){
		int n, d; cin >> n >> d;
		for1(i, 1, n) cin >> a[i];
		if (n <= 9){
			for1(i, 1, n) for1(j, 1, n) f[i][j] = oo << 1, g[i][j] = 0;
			for1(i, 0, (1 << n) - 1) if (__builtin_popcount(i) > 1){
				int fir = -1, lst = -1;
				bool fl = 1;
				for1(j, 0, n - 1)
					if (i >> j & 1){
						if (lst != -1) fl &= (a[j + 1] - a[lst] <= d);
						else fir = j + 1;
						lst = j + 1;
					}
				if (fl){
					int w = __builtin_popcount(i);
					if (w < f[fir][lst]) f[fir][lst] = w, g[fir][lst] = 1;
					else if (w == f[fir][lst]) g[fir][lst]++;
				}
			}
			int ans = 0;
			for1(i, 1, n)
				for1(j, i + 1, n)
					ans += (g[i][j] == 2);
			cout << ans << "\n";
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();

	return 0;
}
