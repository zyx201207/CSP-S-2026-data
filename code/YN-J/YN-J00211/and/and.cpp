#include <bits/stdc++.h>
using namespace std;
int n, m, a[30000002], ans, max1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n - m + 1; i++) {

		ans = a[i];

		for (int j = i + 1; j <= i + m - 1; j++) {

			ans = ans & a[j];
		}

		max1 = max(max1, ans);
		ans = 0;
	}

	cout << max1;
}