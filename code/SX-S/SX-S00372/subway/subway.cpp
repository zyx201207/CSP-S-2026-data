#include <bits/stdc++.h>
using namespace std;
int c, m, n, d, q, started, ended, steps, line1, line2, change_station, change1, change2;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int jinzhan[m + 5] = {}, zhantai[n + 5][m + 5] = {}, chuzhan[n + 5][m + 5] = {};
	for (int i = 1; i <= m; i++) {
		cin >> jinzhan[i];
	}
	for (int i = 0; i < n; i++) {
		int ki = 0;
		cin >> ki;
		for (int j = 1; i <= ki * 2 + 1; i++) {
			if (j / 2 != 0) {
				cin >> zhantai[i][j / 2 + 1];
			} else {
				cin >> chuzhan[i][j / 2 + 1];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> started >> ended;
		steps += jinzhan[started] ;
		steps += jinzhan[ended];
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (zhantai[j][k] == started) {
					if (chuzhan[j][k] < change1)
						change1 = chuzhan[j][k];
					line1 = j;
				}
				if (zhantai[j][k] == ended) {
					if (chuzhan[j][k] < change2)
						change2 = chuzhan[j][k];
					line2 = j;

				}
			}
		}
		steps += change1;
		steps += change2;
		if (line1 == line2) {
			cout << steps	 ;
			return 0;
		}
		if (line1 != line2) {
			for (int l = 1; l <= n; l++) {
				for (int k = 1; k <= m; k++) {
					for (int j = 1; j <= m; j++) {
						if (zhantai[l][k] == zhantai[l][j]) {
							if (chuzhan[l][k] + jinzhan[k] < change_station) {
								change_station = chuzhan[l][k] + jinzhan[k];
							}
						}
					}
				}
			}
		}
		steps += change_station;
	}
	cout << steps;
	return 0;
}
