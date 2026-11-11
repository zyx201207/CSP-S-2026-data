#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, dp[2000005], c, d, q;
ll a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "w", stdin);
	freopen("migrate.out", "r", stdout);

	while (q--) {
		cin >> n >> d;
		memset(dp, 0, sizeof(dp));
		map<ll, int> mp1;
		map<int, ll> mp2;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			mp1[a] = i;
			mp2[i] = a;
		}
		int k = a[2] - a[1] / d;
		if (d == 0) {
			cout << 0;
			continue;
		}
		for (int i = 1; i <= )
		}
	return 0;
}