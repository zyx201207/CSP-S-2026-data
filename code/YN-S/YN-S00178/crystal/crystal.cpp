#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long
int n, m, m1;
int a[N], maxx = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	m1 = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		int sum = 1;
		m = m1;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= m) {
				sum++;
				m -= (a[i] - a[j]);
			}
		}
		maxx = max(sum, maxx);
	}
	cout << maxx;
	return 0;
}
