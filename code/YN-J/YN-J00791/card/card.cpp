#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m;
int a[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1 && a[1] != 1) {
		cout << 2 << ' ';
	} else if (m == 2) {
		if (a[2] != a[1]) {
			cout << 3 << ' ';
			if (a[3] != a[2]) {
				cout << 4 << ' ';
			} else {
				cout << 5 << ' ';
			}
		} else {
			cout << 2 << ' ';
			if (a[3] == a[1]) {
				cout << 3 << ' ';
			} else {
				cout << 4 << ' ';
			}
		}
	}
	return 0;
}

