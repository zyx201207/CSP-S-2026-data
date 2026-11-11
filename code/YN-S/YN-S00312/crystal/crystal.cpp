#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 50;
int a[N];
int qz[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1;
	qz[1] = 0;
	for (int i = 2; i <= n; i++) {
		qz[i] = (a[i] - a[i - 1]) * (i - 1) + qz[i - 1];
	}
	int ans = 0;
	int num = 2;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			int num = a[j] - a[i];

			if (qz[j] - num == m || qz[j] == m) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}
