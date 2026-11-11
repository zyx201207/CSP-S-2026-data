#include <bits/stdc++.h>
#define LL long long
#define ST string
#define DB double

#define fr(x, y, z) for (int x = y; x <= z; x ++ )
#define dfr(x, y, z) for (int x = y; x >= z; x -- )

using namespace std;

const int N = 5010, M = 2e6 + 5;
int c, t, n;
LL a[M], d;

int cnt[N][N], l[N], cnt2[N][N], dis[N][N];
void solve() {
	cin >> n >> d;
	if (n <= N) fr (i, 1, n) {
		l[i] = 0;
		fr (j, 1, n) dis[i][j] = cnt[i][j] = cnt2[i][j] = 0;
	}
	fr (i, 1, n) cin >> a[i];
	
	if (c == 11 || c == 12) {
		LL d2 = a[2] - a[1];
		if (d2 > d) return cout << "0\n", void();
		LL vll = d / d2 + 1;
		if (vll == 2ll) return cout << "0\n", void();
		cout << max(0ll, n - vll * 2 + 3) << '\n';
		return ;
	}
	
	int res = 0;
	fr (i, 1, n) {
		fr (j, 1, i - 1) {
			while (l[j] < i && a[i] - a[l[j]] > d) cnt[j][dis[l[j]][j]] -= cnt2[l[j]][j], l[j] ++ ;
//			cout << i << ' ' << j << ' ' << l[j] << ' ' << dis[l[j]][j] << '\n';
			if (l[j] == i) continue;
			cnt[j][dis[i][j] = dis[l[j]][j] + 1] += (cnt2[i][j] = min(3, cnt[j][dis[l[j]][j]]));
			if (cnt2[i][j] == 2) res ++ ;
		}
		cnt[i][dis[i][i] = 0] = cnt2[i][i] = 1;
		l[i] = i;
	}
	cout << res << '\n';
}

signed main() {
	 freopen("migrate.in", "r", stdin);
	 freopen("migrate.out", "w", stdout);
	 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	
	while (t -- ) solve();
	
	return 0;
}

// 48
