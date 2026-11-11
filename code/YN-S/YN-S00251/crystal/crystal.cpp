#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, cnt = 0;
ll a[500005];
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen(" crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll cur = a[n / 2];
	for (ll i = 1; i <= n; i++) {
		if (i == n / 2)
			continue;
		ll tmp = abs(cur - a[i]);
		q.push(tmp);
	}
	while (!q.empty()) {
		ll tmp = q.top();
		q.pop();
		m -= tmp;
		if (m >= 0)
			cnt++;
		else
			break;
	}
	cout << cnt + 1;
	return 0;
}