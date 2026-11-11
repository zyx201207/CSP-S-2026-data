#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int c, n, d;
int a[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
	}
	return 0;
}

