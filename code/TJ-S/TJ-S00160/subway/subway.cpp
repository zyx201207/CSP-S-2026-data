#include <bits/stdc++.h>
using namespace std;

namespace z {

#define int long long
const int N = 5e5 + 5;
int w[N];
int f[505][505];
vector<pair<int, int>> ve[N];
void main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	int C, n, m, D, q; cin >> C >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		f[i][i] = 0;
		int k; cin >> k;
		while(k--) {
			int x, t; cin >> x >> t;
			ve[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= m; i++) {
		for(auto tmp1 : ve[i]) {
			int x = tmp1.first, t1 = tmp1.second;
			for(auto tmp2 : ve[i]) {
				int y = tmp2.first, t2 = tmp2.second;
				f[x][y] = min(f[x][y], t1 + t2);
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q--) {
		int x, y, ans = 1e18; cin >> x >> y;
		for(auto tmp1 : ve[x]) {
			int x1 = tmp1.first, t1 = tmp1.second;
			for(auto tmp2 : ve[y]) {
				int x2 = tmp2.first, t2 = tmp2.second;
				ans = min(ans, f[x1][x2] + t1 + t2);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}

#undef int 

}

int main() {
	z::main();
	return 0;
}

