#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
//		if (cf[a[i]] == 1) {
//			x = max(x, a[i]);
//		}
//		cf[a[i]] = 1;
	}
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			cout << a[i];
			break;
		}
	}
	return 0;
}