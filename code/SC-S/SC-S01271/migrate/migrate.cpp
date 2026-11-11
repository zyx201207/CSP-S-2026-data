#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
ll c, t, a[N];
ll n, d;
bool check(ll mid) {
	if (a[mid] - a[1] <= d && a[n] - a[mid] > d)
		return 1;
	else return 0;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		bool flag = 1;
		cin >> a[1];
		for (int i = 2; i <= n; i++) {
			cin >> a[i];
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
				flag = 0;
		}
		if (flag == 1) {
			ll D = a[2] - a[1];
			if (d < D) cout << "0\n";
			else if (d / D != 2) cout << "0\n";
			else cout << n - 4 + 1 << "\n";
		} else {
			ll l = 1, r = n;
			while (l <= r) {
				ll mid = (l + r) >> 1;
				if (check(mid)) l = mid + 1;
				else r = mid;
				if (l == r) break;
			}
			cout << (l - 1)*(n - l) << "\n";
		}
	}
	return 0;
}