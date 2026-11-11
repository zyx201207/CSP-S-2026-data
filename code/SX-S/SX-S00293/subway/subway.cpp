#include <bits/stdc++.h>
#define N 500005
using namespace std;
int c, n, m, d, q;
int w[N];
vector<int> t[505];
vector<int> a[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subwap.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	if (n == 1) {
		while (q--) {
			int x, y;
			cin >> x >> y;
			int t1, t2;
			for (int i = 0; i < (int)t[1].size(); i++) {
				if (a[1][i] == x) {
					t1 = t[1][i];
				}
				if (a[1][i] == y) {
					t2 = t[1][i];
				}
			}
			cout << w[x] + w[y] + t1 + t2;
		}
	}
	return 0;
}
