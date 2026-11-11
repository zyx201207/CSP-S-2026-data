#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int vis[300005];
int ans[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		cout << n;
		return 0;
	}
	else if (m == 2) {
		if (a[n] == 1) {
			cout << n << " " << 1;
			return 0;
		}
	}
	return 0;
}
