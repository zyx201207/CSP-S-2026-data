#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
ll a[99999];
ll n;

void dfs(ll st, ll d, ll cnt) {
	if (st == n) {
		if (cnt == n / d + n % d)
			ans++;
		return ;
	}
	for (int i = st + 1; i <= n; i++) {
		if (a[i] <= a[st] + d) {
			dfs(i, d, cnt + 1);
		} else
			break;
	}
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		dfs(1, d, 0);
		cout << ans / 2 << endl;
	}
	return 0;
}
