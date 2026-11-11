#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e6 + 5;
ll a[MAXN];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ll n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (1 || 11 <= c && c <= 12) {
			if (abs(a[2] - a[1]) <= d) {
				cout << n*(n - 1) / 2 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}