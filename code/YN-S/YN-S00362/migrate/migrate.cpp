#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 10;
int c, t;

void solve() {
	int n, d;
	int a[maxn];
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int m = a[2] - a[1];
	if (m > d) {
		cout << 0 << endl;
		return;
	}
	int cnt = d / m;
	int sum = 0;
	for (int i = 2; i <= n; ++i) {
		if (i % 2 == 0) {
			if (cnt % 2 == 0) {
				if (n == 4)
					sum += 2;
				else if ((i - 1) / cnt < 2)
					sum += 2;
			} else {
				if (cnt == 1)
					sum += 0;
				else if ((n - 1) / cnt == 0)
					sum += 0;
				else if ((n - 1) / cnt == 1)
					sum += 2;
			}
		} else {
			if (cnt % 2 == 0)
				sum += 0;
			else {
				if (cnt == 1)
					sum += 0;
				else if ((i - 1) / cnt == 0)
					sum += 0;
				else if ((i - 1) / cnt == 1)
					sum += 2;
			}
		}
	}
	cout << sum << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		solve();
	}
}