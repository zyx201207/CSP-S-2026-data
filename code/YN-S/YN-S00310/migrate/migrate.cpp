#include <bits/stdc++.h>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int MAXN = 2 * 1e6 + 10;
int c, t;
int n;
ll d;
ll a[MAXN];
ll sum = 0;
ll ans = 0;

bool dfs(ll i, ll num) {
	if (sum > 2)
		return 0;
	if (a[i] + d < a[i + 1] || i > n) {
		sum++;
	} else {
		int k = 1;
		while (d > a[i + k] - a[i] && i + k <= n) {
			dfs(a[i + k], num + 1);
			k++;
		}
	}
	if (sum == 2)
		return 1;
	return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	OI
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n - 4; ++i) {
			ans += dfs(i, 0);
		}
		cout << ans << "\n";
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/