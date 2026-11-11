#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;
int c, t;
long long n, d;
long long x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		long long cha, o, ku;
		cha = (x[2] - x[1]);
		o = d / cha;
		ku = (2 * o);
		if (ku > n) {
			cout << "0" << endl;
		} else {
			cout << (n - ku + 1) << endl;
		}
	}
	return 0;
}
