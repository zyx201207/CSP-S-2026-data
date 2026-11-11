#include <bits/stdc++.h>
using namespace std;
int n, m, a[200020], mac, b[200020];
bool br[200020][32], q[200020];
vector<short> v[200020];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		q[i] = true;
		int x = a[i], c = 0;
		while (x != 0) {
			++ c;
			if (x % 2 == 1) {
				v[i].push_back(c);
				b[c] ++;
				br[i][c] = true;
			}
			x /= 2;
		}
		mac = max (mac, c);
	}
	int ans = 0, u = 0;
	for (int w = mac; w >= 1; -- w) {
		if (b[w] < m) {
			ans = ans * 2;
			continue ;
		}
		if (b[w] == n - u) {
			ans = ans * 2 + 1;
			continue;
		}
		for (int i = 1; i <= n; ++ i) {
			if (br[i][w] == false && q[i] == true) {
				int x = a[i], c = 0;
				while (x != 0) {
					++ c;
					if (x % 2 == 1) {
						b[c] --;
					}
					x /= 2;
				}
				u ++;
				q[i] = false;
			}
		}
		ans = ans * 2 + 1;
	}
	
	cout << ans;
	
	return 0;
}