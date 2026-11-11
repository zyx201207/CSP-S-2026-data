#include <bits/stdc++.h>
using namespace std;
int a[200010], ans = -1e7 - 5;
int n, m;

void solve1() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (m == 1) {
		cout << a[n];
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	cout << ans;
}

void solve2() {
	cin >> a[1];
	ans = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		ans &= a[i];
	}
	cout << ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	if (n <= 2000 && m <= 2) {
		solve1();
	} else if (n == m) {
		solve2();
	} else {
		cout << 0;
	}

	return 0;
	//zmh
}