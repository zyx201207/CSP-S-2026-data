#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[1000010];

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
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[1] < a[2]) {
				break;
			}
			if (a[1] > a[2]) {
				swap(a[1], a[2]);
			}
		}
		a[1]++;
	}
	int cnt = 0, max_ = -1;
	for (int i = 1; i < n; i++) {
		cnt = 1;
		if (a[i] == a[i + 1]) {
			cnt = 2;
			int j = i + 1;
			for (; j < n; j++) {
				if (a[j] == a[j + 1])
					cnt++;
				else
					break;
			}
			i = j;
		}
		max_ = max(max_, cnt);
	}
	cout << max_;
	return 0;
}