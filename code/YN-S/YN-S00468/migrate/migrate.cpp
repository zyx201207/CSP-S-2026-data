#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, n;
int a[N];
int times;

void pd(int l, int r) {
	if (l == r) {
		times++;
	} else {
		for (int i = l + 1; i <= c; i++) {
			if (a[i] - a[l] <= n)
				pd(i, r);
		}
	}

}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int id, T;
	cin >> id >> T;
	for (int t = 1; t <= T; t++) {
		cin >> c >> n;
		for (int i = 1; i <= c; i++) {
			cin >> a[i];
		}
		int sc = 0;
		for (int i = 1; i <= c; i++) {
			for (int j = i + 1; j <= c; j++) {
				times = 0;
				pd(i, j);
				if (times == 2)
					sc++;
			}
		}
		cout << sc - 1 << "\n";
	}

	return 0;
}