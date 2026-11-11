#include <bits/stdc++.h>
using namespace std;
int a[1000001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	sort(a + 1, a + n + 1);
	int ans;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= cnt / n && a[i + 1] > cnt / n) {
			ans = a[i];
			for (int j = i - 1; j >= 1; j--) {
				if (a[i] - a[j] <= m) {
					m -= (a[i] - a[j]);
					a[j] = a[i];
				} else
					break;
			}
		} else if (a[i] >= cnt / n && m > 0 && a[i] > a[i - 1]) {
			int x = a[i] - a[i - 1], s = 0;
			for (int k = 1; k < i; k++) {
				if (a[k] == a[i - 1])
					s += x;
			}
			if (m >= s) {
				for (int k = 1; k < i; k++) {
					if (a[k] == a[i - 1])
						a[k] = a[i];
				}
				m -= s;
				ans = a[i];
			} else
				m = 0;
		}
		if (m == 0)
			break;
	}
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == ans) {
			t++;
		}
	}
	cout << t;
	return 0;
}