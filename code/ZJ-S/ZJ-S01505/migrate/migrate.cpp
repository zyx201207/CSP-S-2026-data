#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
long long a[N], dp[N];
long long seg[N * 4];
int lst[N], s[N];
long long n, d;
//ll
int Calc(int l, int r, int x) {
	int best = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (s[mid] <= x) {
			best = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return best;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t; cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		if (n <= 3000) {
			int l = 1;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				while (a[i] - a[l] > d) l++;
				lst[i] = l;
			}
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) dp[j] = s[j] = 0;
				dp[i] = 1; dp[i - 1] = 0;
				s[i] = 0;
//				cout << i << '\n';
				for (int j = i + 1; j <= n; j++) {
					int L = max(i, lst[j]);
					s[j] = s[max(i, L)] + 1;
					dp[j] = dp[Calc(L, j - 1, s[L])] - dp[max(i - 1, L - 1)];
					if (dp[j] == 2) ans++;
//					cout << j << ' ' << s[j] << ' ' << dp[j] << '\n';
					dp[j] += dp[j - 1];
				}
//				cout << ans << ' ';
			}
			cout << ans << '\n';
		}
		else {
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			if (a[2] - a[1] > d) cout << "0\n";
			else if (a[n] - a[1] <= d) cout << "0\n";
			else if ((a[2] - a[1]) * 2 > d) cout << "0\n";
			else {
				int _ = d / (a[2] - a[1]);
				cout << n - _ - _ + 1 << '\n';
			}
//			else cout << n - 4 + 1 << '\n';
		}
//		cin >> n >> d;
//		long long ans = 0;
//		for (int i = 1; i <= n; i++)
//			dp[i] = 0;
//		Add(1, 1);
//		int l = 1, _ = 1, __ = -1;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			while (a[i] - a[l] > d) l++;
////			lst[i] = l;
//			if (i == l) {
//				_ = i; __ = -1;
//				continue;
//			}
//			int _x = Find(1, n, 1, l, i - 1);
//			cout << _x << '\n';
//			if (_x == 2) {
//				if (__ == -1) __ = i;
//				ans += __ - _;
//			}
//			if (_x > 2) {
//				Change(1, n, 1, l, l, 1);
//				Change(1, n, 1, l + 1, i - 1, 1);
//				_ = l;
//				__ = -1;
//			}
//			Add(i, _x);
//		}
//		cout << ans << '\n';
//		cin >> n >> d;
//		long long ans = 0;
//		for (int i = 1; i <= n; i++)
//			dp[i] = 0;
//		Add(1, 1);
//		int l = 1, _ = 1, __ = -1;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			while (a[i] - a[l] > d) l++;
////			lst[i] = l;
//			if (i == l) {
//				_ = i; __ = -1;
//				continue;
//			}
//			int _x = Find(i - 1) - Find(l - 1);
//			cout << _x << '\n';
//			if (_x == 2) {
//				if (__ == -1) __ = i;
//				ans += __ - _;
//			}
//			if (_x > 2) {
//				Add(l, -(Find(l) - Find(l - 1) - 1);
//				
//				_ = l;
//				__ = -1;
//			}
//			Add(i, _x);
//		}
//		cout << ans << '\n';
//		long long n, d; cin >> n >> d;
//		int l = 1, _ = 1, flg = 0, tmp = 0, id = -1;
//		long long ans = 0;
//		for (int i = 1; i <= n; i++)
//			dp[i] = lst[i] = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			while (a[i] - a[l] > d) l++;
//			lst[i] = l;
//			if (i - l > 1) {
//				if (dp[l] == dp[l + 1]) {
//					if ((i - l > 2 && dp[l] == dp[l + 2]) || (flg == 1 && dp[l] != id)) {
//						_ = l; flg = 0; tmp = 0;
//						dp[_]--;
//					}
//					else {
//						flg = 1, tmp = lst[l];
//						id = dp[l];
//					}
//				}
//			}
//			if (i == l) {
//				_ = i; flg = 0; tmp = 0;
//				id = 0;
//			}
//			ans = ans + flg * (tmp - _ + 1);
//			dp[i] = dp[l] + 1;
////			cout << ans << ' ';
//		}
//		cout << ans << '\n';
	}
	return 0;
}