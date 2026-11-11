#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[100001], k[100001], t[1001][1001], st, la, st1, la1, a[1001][1001], sum[100001] = {}, numx[2],
    numy[2],
    o = 0,
    numx1[2], numy1[2];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> a[i][j] >> t[i][j];

		}
	}
	while (q--) {

		cin >> st >> la ;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k[i]; j++) {
				if (a[i][j] == st) {
					numx[0] = i;
					numy[0] = j;
				}
				if (a[i][j] == la) {
					numx1[0] = i;
					numy1[0] = j;
				}
			}
		}
		if (numx[0] == numx1[0]) {
			for (int j = numy[0]; j <= numy1[0]; j++) {
				o += t[numx[0]][j];
				o += w[j];
			}
		}
	}
//	int sp[10001], esp[10001], time = 0, ti = 0, time1;
//	if (numx[0] != numx1[0]) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < k[i]; j++) {
//				if (a[numx[0]][i] == a[numx1[0]][j]) {
//					time++;
//					sp[time] = i;
//					esp[time] = j;
//				}
//
//			}
//		}
//	}
//	time1 = time;
//	time = 0;
//	while (time <= time1) {
//		for (int i = 0; i < sp[time]; i++) {
//			sum[time] += t[numx[0]][i] += w[i];
//			cout << t[numx[0]][i] << " " << w[i] << " ";
//			ti++;
//		}
//		if ( ti < esp[time]) {
//
//			for (int i = ti; i < esp[time]; i++) {
//				sum[time] += t[numx1[0]][i] += w[i];
//				cout << t[numx[0]][i] << " " << w[i] << " ";
//			}
//		} else {
//			for (int i = ti; i >= esp[time]; i--) {
//				sum[time] += t[numx1[0]][i] += w[i];
//				cout << t[numx[0]][i] << " " << w[i] << " ";
//			}
//		}
//		time++;
//	}
//
//	sort(sum, sum + time1);
	cout << o;
	return 0;
}
//0 3 7 20 2
// 8 3 6 1 7 2 9
// 3 1 4 2 5 5 100
//3 2 6 3 1 7 2
// 4 3 2 5 100 4 6 6 7
// 1 6
// 2 3
