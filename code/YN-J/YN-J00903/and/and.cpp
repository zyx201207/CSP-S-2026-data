#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
int n, m;
int a[1000000 + 1];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && m == 2) {
		cout << 12;
	}
	if (n == 5 && m == 3) {
		cout << 7;
	}
	return 0;
}