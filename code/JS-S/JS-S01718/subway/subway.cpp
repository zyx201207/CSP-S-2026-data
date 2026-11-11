#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 5e5;

int w[M + 5];
int k[M + 5];
int a[M + 5][4];
int t[M + 5][4];

int c, n, m, d, q;
int ans;

vector<int> g[M + 5];

void dfs1(int fa, int aim) {
	if (fa == aim)
		return;
	for (int v : g[fa]) {
		if (v != fa) {
			cout << v;
			dfs1(v, aim);			
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		ans += w[i];
	}
	//if (c >= 7 && c <= 11) {
		for (int i = 1; i <= n; i++) {
			int l; 
			cin >> l;
			for (int j = 1; j <= l; j++) {
				cin >> a[i][j] >> t[i][j];
				ans += a[i][j];
			}
			g[a[i][1]].push_back(a[i][2]);
			g[a[i][2]].push_back(a[i][1]);
		}
		for (int i = 1; i <= q; i++) {
			int bsta, fsta;
			cin >> bsta >> fsta;
			dfs1(bsta, fsta);
		}
		cout << ans << '\n';
	//}
	return 0;
}
