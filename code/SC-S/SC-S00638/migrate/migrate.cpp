#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define lowbit(x) x&(-x)

const int N = 5e3 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, d, x[N];
int L[N], R[N];
int dis[N][N];

void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	
	int p = 1;
	for (int i = 1; i <= n; i++) {
		while(p <= i && x[p] + d < x[i]) p++;
		L[i] = p;
	}
	
	p = n;
	for (int i = n; i >= 1; i--) {
		while(p >= 1 && x[p] - d > x[i]) p--;
		R[i] = p;
	}
	
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = INF;
	}
	
	for (int i = 1; i <= n; i++) {
		int lst = i + 1, r = R[i], d = 1;
		while(r <= n) {
			for (int j = lst; j <= r; j++)
				dis[i][j] = d;
			if (r == R[r]) break;
			lst = r + 1; r = R[r]; d++;
		}
	}
	
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cout << i << " " << j << " " << dis[i][j] << "\n";
	
	int ans = 0;
	
	for (int l = 1; l <= n; l++)
		for (int r = l + 3; r <= n; r++) {
			if (dis[l][r] == INF) continue;
			bool flag = false;
			for (int k = l + 1; k < r - 1; k++) {
				if (R[k] != k + 1) {
					if (dis[l][k] + dis[k][r] == dis[l][r] && 
						dis[l][k + 1] + dis[k + 1][r] == dis[l][r])
						flag = true;
					break;
				}
			}
//			if (flag) cout << l << " " << r << "\n";
			ans += flag;
		}
	
	cout << ans << "\n";
}

signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, T = 1; cin >> c >> T;
	while(T--) solve();
	return 0;
}

/*

T1T2写了1h，
苦战3小时T3竟然O(n^2)都没写出来吗...

感觉今年一等要200+...

100+100+0+15完蛋了




And nothing lasts forever~
Even cold November rain~
Yeah~

noip加油！

*/