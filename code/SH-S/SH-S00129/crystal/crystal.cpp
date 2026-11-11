//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 5e5 + 10;
//int n, m, ans, a[N], s[N];
//signed main() {
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		s[i] = s[i - 1] + a[i];
//	}
//	sort(a + 1, a + 1 + n);
//	int i = 1, j = 0;
//	while (i <= n) {
//		int now = 0;
//		int tmp = a[i];
//		for (j = i + 1; j <= n; j++) {
//			if (a[j] != tmp) {
//				break;
//			}
//		}
//		int mx = 0;
//		for (int k = i - 1; k >= 1; k--) {
//			int sum = (i - k) * a[i] - (s[i - 1] - s[k - 1]);
////			cout << k << ' ' << sum << '\n';
//			if (sum <= m) {
//				mx = k;
//			}
//			else break;
//		}
//		now = j - mx;
//		// cout << j << '\n';
//		cout << i << ' ' << j << ' ' << mx << '\n';
//		i = j;
//		ans = max(ans, now);
//	}
//	cout << ans << '\n';
//	return 0;
//} 
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, ans, a[N], s[N];
bool check(int x, int i) {
	return (i - x) * a[i] - (s[i - 1] - s[x - 1]) <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
//		cout << a[i] << ' ';
		s[i] = s[i - 1] + a[i];
	}
//	int i = 1, j = 0;
	for (int i = 1; i <= n; i++) {
		int now = 0;
//		int tmp = a[i];
//		for (j = i + 1; j <= n; j++) {
//			if (a[j] != tmp) {
//				break;
//			}
//		}
		int l = 1, r = i - 1, mx = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				mx = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
//		for (int k = i - 1; k >= 1; k--) {
//			int sum = (i - k) * a[i] - (s[i - 1] - s[k - 1]);
////			cout << k << ' ' << sum << '\n';
//			if (sum <= m) {
//				mx = k;
//			}
//			else break;
//		}
		now = i - mx + 1;
		// cout << j << '\n';
//		cout << i << ' ' << j << ' ' << mx << '\n';
//		i = j;
		ans = max(ans, now);
	}
	cout << ans << '\n';
	return 0;
} 
