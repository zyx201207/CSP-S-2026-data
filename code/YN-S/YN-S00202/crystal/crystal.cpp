#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], aa[N], ans = 0;

bool ch(int x) {
	long long as = LONG_LONG_MAX;
	for (int i = 1; i <= n - x; i++) {
		long long cc = a[i + x - 1], ca = 0;
		bool f = 1;
		for (int j = i; j < i + x; j++) {
			ca += abs(a[j] - cc);
			if (ca > m) {
				f = 0;
				break;
			}
//			if (x == 4 && a[i] == -3 && a[i + x - 1] == 2) {
//				cout << ca << " ";
//			}
		}
//		if (a[i] == -3 && x == 4) {
		//	cout << a[i] << " " << a[i + x - 1] << " " << ca << " " << cc << " " << cb << " " << cc + 1 << endl;

//		}
		if (f) {
			as = min(as, ca);
			//	cout << "AAA  " << a[i] << " " << a[i + x - 1] << "\n " << ca << " " << cc << endl;
		}
	}
	return as <= m;
}


bool ch2(int x, int y) {
	long long cc = (a[1] + a[1 + x - 2]), ca = 0;
	for (int i = 1; i <= x - 1; i++) {
		if (ca > m - abs(a[i] - a[x]))
			return 0;
		ca += abs(a[i] - a[x]);
	}
//	cout << x << " " << ca << endl;
	return ca <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n > 5000) {
		long long cc = a[2] - a[1], ll = 1, rr = n;
		while (ll <= rr) {
			long long mm = (ll + rr) / 2;
			if (ch2(mm, cc)) {
				ll = mm + 1;
				ans = mm;
			} else
				rr = mm - 1;
		}
		cout << ans;
		return 0;
	}
	long long l = 1, r = n;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (ch(mid)) {
			l = mid + 1;
			ans = mid;
		} else
			r = mid - 1;
	}
	cout << ans;

	return 0;
}
