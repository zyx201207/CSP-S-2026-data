#include <bits/stdc++.h>
#define ll long long
#define il inline
#define pb push_back
using namespace std;
const ll N = 5e5+5;

ll n, m;
ll ans[N];
ll a[N];

void solve() {
	ll cost = 0, tail = 1;
	a[0] = a[1];
	for (int i = 1; i <= n; i++) {
		cost += (a[i]-a[i-1]) * (i - tail);
		while (cost > m) {
			cost -= a[i] - a[tail++];
		}
		ans[i] = i - tail + 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a+1, a+n+1);

	solve();

	ll mx = -1;
	for (int i = 1; i <= n; i++) mx = max(mx, ans[i]);
	cout << mx;

	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

10 8
2 4 6 8 -10 12 14 16 18 20

*/