#include <bits/stdc++.h>
using namespace std;
long long a[100001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n;
	cin >> n;
	int m;
	cin >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a, a + n + 1);
	int ans = a[n];

	for (int i = n ; i >= n - m + 1; i--) {

		ans &= a[i];
	}

	cout << ans;

	return 0;
}
