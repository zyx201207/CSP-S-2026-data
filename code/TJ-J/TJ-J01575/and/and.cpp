#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 1) {
		cout << a[1];
		return 0;
	}
	if (m == 2) {
		int maxx = INT_MIN;
		for (int i = 2; i <= n; i++) {
			maxx = max(maxx, a[1] & a[i]);
		}
		cout << maxx;
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	return 0;
}
