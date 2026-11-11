#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int c, n, m, dd, q, d[N][N], w[500005], a[N][N], t[N][N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j <= k; j ++){
			for(int l = 1; l <= k; l ++){
				d[a[i][j]][a[i][l]] = 0;
			}
		}
	}
	for(int i = 1; i <= q; i ++){
		int s, e;
		cin >> s >> e;
		cout << 4*t[1][1]+w[s]+w[e] << '\n';
	}
	return 0;
}