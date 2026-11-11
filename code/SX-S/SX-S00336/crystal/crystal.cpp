#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[501000], c[501000];
int cnt = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		c[i] = a[i + 1] - a[i];
	}
	for (int i = 1; i <= n; i++) {
		int ans = 1;
		for (int j = 1, sum = 0; j <= n, sum <= m; j++) {
			sum += j * c[j];
			if (sum <= m) {
				ans++;
			}
		}
		cnt = max(cnt, ans);
	}
	cout << cnt;
	return 0;
}
