#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int jj = 1; jj <= m; jj++) {
		vector <int> zm;
		for (int i = jj; i <= n; i++) {
			bool zf = 0;
			zm.push_back(a[i]);

		}
	}
	return 0;
}