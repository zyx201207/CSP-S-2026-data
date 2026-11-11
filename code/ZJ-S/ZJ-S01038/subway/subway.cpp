#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, m, d, q, w[N], a[N], t[N][N], dist[N][N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c >> m >> n >> d >> q;
	for(int i = 1;i <= n;i ++) cin >> w[i];
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 1;i <= m;i ++) {
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++) {
			cin >> a[j];
			cin >> t[i][a[j]];
		}
		for(int j = 1;j <= k;j ++) {
			for(int l = 1;l <= k;l ++) {
				dist[a[j]][a[l]] = t[i][a[j]] + t[i][a[l]];
			}
		}
	}
	for(int i = 1;i <= n;i ++)
		dist[i][i] = 0;
	for(int k = 1;k <= n;k ++)
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//	for(int i = 1;i <= n;i ++)
//		for(int j = 1;j <= n;j ++)
//			cout << i << ' ' << j <<' ' << ' ' << dist[i][j] << '\n';
	for(int i = 1;i <= q;i ++) {
		int x, r;
		cin >> x >> r;
		cout << dist[x][r] + w[x] + w[r] << '\n';
	}
	return 0;
}