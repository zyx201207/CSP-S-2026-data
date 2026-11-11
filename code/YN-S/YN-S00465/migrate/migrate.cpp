#include <bits/stdc++.h>
#define int long long
using namespace std;
int c;
int T;
int n;
int d;
const int N = 2 * 1e6;
int a[N];
int diff[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	while (T --) {

		cin >> n >> d;
		int f = 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		int j = 1;
		for (int i = 2; i <= n; i ++, j ++) {
			diff[j] = a[i] - a[i - 1];
		}
		for (int i = 1; i < j - 1; i ++) {
			if (diff[i] != diff[i + 1])
				f = 1;
			//	cout << diff[i] << ' ';
		}
		if (f == 0) {
			int sd = diff[2] - diff[1];
			if (sd / d >= 2) {
				cout << (1 + n - 2) * (n - 2) / 2  << '\n';
			} else {
				cout << 0;
			}
		}

	}
	return 0;
}