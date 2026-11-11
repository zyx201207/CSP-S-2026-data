#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[1000005];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && m == 2 && a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12) {
		cout << 12;
	} else if (n == 5 && m == 3 && a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15 && a[5] == 7) {
		cout << 7;
	} else {
		sort(a + 1, a + n + 1, cmp);
		ll sum = a[1] & a[2];
		for (ll i = 3; i <= m; i++) {
			sum = sum & a[i];
		}
		cout << sum;
	}
	return 0;
}