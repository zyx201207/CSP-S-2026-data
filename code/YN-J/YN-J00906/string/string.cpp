#include <bits/stdc++.h>
using namespace std;

long long n, a[200005], ans;
char ch[200005];

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> ch[i];
	}

	long long i = 1, j = n;

	while (i < j) {
		long long cost = min(a[i], a[j]);

		if (ch[i] != ch[j]) {
			ans += cost;
		}

		a[i] -= cost;
		a[j] -= cost;

		if (a[i] <= 0) {
			i++;
		}

		if (a[j] <= 0) {
			j--;
		}
	}

	cout << ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}