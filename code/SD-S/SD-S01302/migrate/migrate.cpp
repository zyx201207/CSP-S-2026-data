#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int C, T;
int n, d;
int x[N], min_t, k;

void dfs(int u, int v, int t, string s) {
	if (t > min_t)return;
	if (u == v) {
//		cout << s << " ";
		if (t < min_t) {
			min_t = t;
			k = 0;
		}
		else {
			k ++;
		}
		return;
	}
	for (int i = u + 1; i <= n; i ++) {
		if (x[i] > x[u] + d) break;
		if (x[i] - x[u] <= d) {
			dfs(i, v, t + 1, s + char(i + '0'));
		}
	}
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> C >> T;
	while (T --) {
		cin >> n >> d;
		bool f = false;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> x[i];
		}
		int d1 = x[2] - x[1];
		for (int i = 3; i <= n; i ++) {
			if (x[i] - x[i - 1] != d1) f = true;
		}
		if (f == true) {
			for (int i = 1; i <= n; i ++) {
				for (int j = i + 2; j <= n; j ++) {
					min_t = 0x3f3f3f3f;
					k = 0;
					dfs(i, j, 0, "");
					if (k == 2) {
						ans ++;
					}
				}
			}
			cout << ans << "\n";
		}
		else {
			cout << n - (ceil(d / d1) + 1) << "\n";
		}
	}
	
	return 0;
}
