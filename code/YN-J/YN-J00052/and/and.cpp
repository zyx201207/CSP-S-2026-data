#include <bits/stdc++.h>
using namespace std;
int a[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		cout << mx;
		return 0;
	}
	if (m == 2) {
		int mx = -1;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				mx = max(mx, a[i] & a[j]);
			}
		}
		cout << mx;
		return 0;
	}
	if (m == n) {
		int mx = a[1];
		for (int i = 2; i <= n; i++) {
			mx = mx & a[i];
		}
		cout << mx;
		return 0;
	}
	int ans = 0, mx = -1;
	for (int i = 1; i <= n - m + 1; i++) {
		ans = a[i];
		for (int j = i + 1; j <= m + i - 1; j++) {
			ans = ans & a[j];
		}
		mx = max(mx, ans);
	}
	cout << mx;
	return 0;
}