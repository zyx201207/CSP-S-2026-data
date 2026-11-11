#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans, rest, sum;
const int M = 5e5 + 10;
ll a[M];
ll b[M];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	rest = m;
	sum = 1;
	for (ll i = 2; i <= n; i++) {
		ans += sum * b[i];
		if (ans > rest) {
			break;
		}
		sum++;
	}
	cout << sum;
	return 0;
}