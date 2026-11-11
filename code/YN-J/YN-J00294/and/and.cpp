#include <bits/stdc++.h>
using namespace std;
int n, m, ans, maxx = INT_MIN;
long long a[200005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = n; i >= 1 + m; i--) {

		ans = 0;

		for (int j = i; j > i - m + 1; j--) {

			ans = a[j] & a[j - 1];
		}

		maxx = max(maxx, ans);
	}

	cout << maxx;
	return 0;
}