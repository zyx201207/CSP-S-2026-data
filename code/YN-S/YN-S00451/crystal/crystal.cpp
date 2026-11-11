#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long cnt = 1;
	for (int i = n - 1; i >= 1; i--) {
		m -= (a[n] - a[i]);
		if (m <= 0) {
			cout << cnt << "\n";
			return 0;
		}
		cnt++;
	}

	return 0;
}