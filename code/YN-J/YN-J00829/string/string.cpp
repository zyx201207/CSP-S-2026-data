#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	deque<pair<ll, char>> dq;
	for (int i = 0; i < n; i++) {
		ll x;
		char c;
		cin >> x >> c;
		dq.push_front({x, c});
	}
	ll ans = 0;
	while (dq.size() > 1) {
		ll k1 = dq.front().first, k2 = dq.back().first;
		char r1 = dq.front().second, r2 = dq.back().second;
		dq.pop_front();
		dq.pop_back();
		if (r1 != r2)
			ans += min(k1, k2);
		if (k1 > k2)
			dq.push_front({k1 - k2, r1});
		else if (k1 < k2)
			dq.push_back({k2 - k1, r2});
	}
	cout << ans;
	return 0;
}