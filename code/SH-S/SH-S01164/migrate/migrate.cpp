#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int N = 100005;
int c, T;
int n, d, a[N];
int mn[N], cnt[N], ans;
void dfs(int c, int stp) {
//	cout << c << ' ' << stp << '\n';
	if(stp < mn[c]) {
		mn[c] = stp, cnt[c] = 1;
//		cout << "$$$" << cnt[c] << '\n';
	} 
	else if(stp == mn[c]) {
		++ cnt[c];
//		cout << "###" << cnt[c] << '\n';
	}
//		return; 
	rep(i, c + 1, n) {
		if(a[i] - a[c] <= d) {
			dfs(i, stp + 1);
		}
	}
}
void solve() {
	cin >> n >> d; rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		rep(j, 1, n) mn[j] = INT_MAX / 2;
		rep(j, 1, n) cnt[c] = 0;
//		cout << i << ':' << '\n';
		dfs(i, 0);
		rep(j, i + 1, n) {
//			cout << cnt[j] << ' ';
			if(cnt[j] == 2) ++ ans;
		}
//		cout << '\n';
		rep(j, 1, n) mn[j] = INT_MAX / 2;
		rep(j, 1, n) cnt[c] = 0;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	if(c == 11 || c == 12) { 
		while(T --) {
			cin >> n >> d; rep(i, 1, n) cin >> a[i];
			int delta = a[2] - a[1];
			int bs = d / delta;
			cout << n - 2 * bs + 1 << '\n';
		}
	} else {
		while(T --) {
		  ans = 0; 
		  solve();
		  ans = 0;
	  }
	}
	
	return 0;
} 
