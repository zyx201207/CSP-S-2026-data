#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const long long mxm = 3e18 + 7;
long long w[550000],f[550][550], t[550000][25][2], idx[550000], b;
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i ++ ) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			if (i == j) f[i][j] = 0;
			else f[i][j] = mxm;
		}
	}
	int tx, ax, kx;
	for (int i = 0; i < n; i ++ ) {
		cin >> kx;
		for (int j = 0; j < kx; j ++ ) {
			cin >> ax >> tx;
			t[ax][idx[ax]][0] = i;
			t[ax][idx[ax]][1] = tx;
			for (int kk = 0; kk < idx[ax]; kk ++ ) {
//				cout << "sb" << tx << ax;
				f[i][t[ax][kk][0]] = min (f[i][t[ax][kk][0]], tx + t[ax][kk][1]);
				f[t[ax][kk][0]][i] = f[i][t[ax][kk][0]];
			}
			idx[ax] ++ ;
		}
	}
//	for (int i = 0; i < n; i ++ ) {
//		for (int j = 0; j < n; j ++ ) {
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	for (int k = 0; k < n; k ++ ) {
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
//	for (int i = 0; i < n; i ++ ) {
//		for (int j = 0; j < n; j ++ ) {
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	int x, y;
	while (q -- ) {
		cin >> x >> y;
		long long mn = mxm, s = 0;
		for (int i = 0; i < idx[x]; i ++ ) {
			for (int j = 0; j < idx[y]; j ++ ) {
//				cout << i << j << t[x][i][0] << t[y][j][0] << " ss" << endl;
				
				mn = min (f[t[x][i][0]][t[y][j][0]] + t[x][i][1] + t[y][j][1], mn);
//				cout << mn << endl;
			}
		}
		cout << mn + w[x - 1] + w[y - 1] << endl;
	}
	return 0;
}
