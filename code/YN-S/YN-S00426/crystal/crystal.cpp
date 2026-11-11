#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans = 1;
long long m;
const int N = 5e5 + 5;
int a[N];

bool check_1() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			return false;
		}
	}
	return true;
}

bool check_2() {
	int x = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != x) {
			return false;
		}
	}
	return true;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (check_1()) {
		int num;
		for (int i = 1; i <= n; i++) {
			num = i * i - i;
			if (num >= 2 * m) {
				cout << i;
				return 0;
			}
		}
		cout << 1;
	} else if (check_2()) {
		int num, x = a[2] - a[1];
		for (int i = 1; i <= n; i++) {
			num = i * i - i;
			if (num * x >= 2 * m) {
				cout << i;
				return 0;
			}
		}
		cout << 1;
	} else {
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			int m1 = m;
			for (int j = i; j >= 1; j--) {
				int num = abs(a[j] - a[i]);
				if (num <= m1) {
					cnt++;
					m1 -= num;
				} else {
					break;
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
	}
	return 0;
}