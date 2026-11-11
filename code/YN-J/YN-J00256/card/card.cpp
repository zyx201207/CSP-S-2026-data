#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll N = 5e5 + 10;
ll a[N];

ll cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		cout << 1;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	for (ll i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
