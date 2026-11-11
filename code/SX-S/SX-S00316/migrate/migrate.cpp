#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl "\n"
using namespace std;
const int M = 2e6+10;
int c, t, n;
ll a[M], d, s;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fast;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		s = a[2] - a[1];
		if (d % 2 == 0) {
			cout << (n % d) + s << endl;
		} else {
			if (n % 2 == 0) {
				cout << n / d << endl;
			} else {
				cout << n / d - s << endl;
			}
		}
	}
	return 0;
}
