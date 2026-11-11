//#include <bits/stdc++.h>

//using namespace std;
//#define ll long long
//
//int main() {
////	freopen("and.in", "r", stdin);
////	freopen("and.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	ll n, m, ma = 0;
//	cin >> n >> m;
//	if (m == n) {
//		long long ans = (2 << 31) - 1;
//		for (int i = 1; i <= n; i++) {
//			ll a;
//			cin >> a;
//			ans = (ans & a);
//		}
//		cout << ans;
//		return 0;
//	}
//	for (int i = 1; i <= n; i++) {
//		ll a;
//		cin >> a;
//		for (int i = 1; i <= 31; i++) {
//			if (a == (2 << i) - 1) {
//				ma = max(ma, a);
//				break;
//			}
//		}
//	}
//	cout << ma;
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m, ma;
	cin >> n >> m;
	ll ans = (2 << 31) - 1;
	for (int i = 1; i <= n; i++) {
		ll o;
		cin >> o;
		ans = (ans & o);
	}
	cout << ans;
//	bool f = 1, fl = 1, fla = 1;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		if (a[i] != i - 1)
//			fl = 0;
//		if (a[i] > 4)
//			fla = 0;
//		bool ls = 0;
//		for (int j = 0; j <= 31; j++) {
//			if (a[i] == (2 << i) - 1) {
//				ls = 1;
//			}
//		}
//		if (ls == 0)
//			f = 0;
//	}
//	if (f == 1) {
//		for (int i = 1; i <= n; i++) {
//			ma = max(ma, a[i]);
//		}
//	} else if (fl) {
//		ma = a[n];
//	} else if (fla) {
//		ma = 3;
//	} else {
//		sort(a + 1, a + 1 + n);
//		for (int i = 31; i >= 1; i--) {
//			if (a[n - m + 2] > (2 << i) - 1)
//				ma = (2 << i) - 1;
//		}
//	}
//	cout << ma;
	return 0;
}