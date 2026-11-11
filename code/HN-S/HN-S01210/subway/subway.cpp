#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int k[505], a[500005][505], t[500005][505];
int ting[505]; 
int tai[505][505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		int v;
		cin >> v;
		ting[i] = v;
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			tai[a[i][j]][i] = t[i][j];
		}
	}

	while(q--) {
		int x, y, time = 0;
		cin >> x >> y;
		for(int k = x; k <= y; k++) {
			time += ting[k];
			for(int i = 1; i <= n; i++) {
				if(tai[k][i] > 0) {
					time += tai[k][i];
					break;
				}
			}
		}
		cout << time << endl;
	}
	return 0;
}
