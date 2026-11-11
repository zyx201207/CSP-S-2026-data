#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[300002];
char c[300002];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];

	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	if (n == 2) {
		if (c[1] != c[2]) {
			cout << max(a[1], a[2]);
		} else
			cout << 0;

		return 0;
	}

	for (int i = 1; i <= n / 2; i++) {

		if (c[i] != c[n - i + 1]) {
			ans += max(a[i], a[n - i + 1]);
		}
	}

	cout << ans;
}