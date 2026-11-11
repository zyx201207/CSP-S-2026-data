#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll N = 2e5 + 10;
ll a[N];

ll cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];

	return 0;
}
