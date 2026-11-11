#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dis[901000];
ll n, m, cnt = 1, ans, mx, w;
priority_queue<ll>que;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	w = m;
	for (ll i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		que.push(x);
	}
	for (ll i = 1; i < n; ++i) {
		ll x = que.top();
		que.pop();
		ll y = que.top();
		dis[i] = x - y;
	}
	for (ll i = 1; i < n; ++i) {
		for (ll j = i; j < n; ++j) {
			ans += dis[j];
			w -= ans;
			if (w < 0)
				break;
			if (w >= 0) {
				cnt++;
			}
		}
		ans = 0;
		w = m;
		if (cnt > mx)
			mx = cnt;
		cnt = 1;
	}
	cout << mx << '\n';
	return 0;
}

