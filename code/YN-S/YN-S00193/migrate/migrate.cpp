#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
int c, t, a[N], b[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n < d * 2) {
			cout << "0" << '\n';
			continue;
		}
		for (int i = 2; i <= n; i++) {
			b[i] = abs(a[i] - a[i - 1]);
		}
	}

	return 0;
}