#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, K, st, ed;
long long w[500100];

long long tp[510][2];

long long mp[1100][1100], ff[1100][1100];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	//cout << 1;
	for (int i = 1; i <= n; i++) {
		cin >> K;
		//int x = 1;
		for (int j = 1; j <= K; j ++)
			cin >> tp[j][0] >> tp[j][1];
		//x++;

		for (int j = 1; j < K; j++) {
			for (int jj = j + 1; jj <= K; jj++) {
				//add(tp[j][0],tp[jj][0],tp[j][1]+tp[jj][1]);
				mp[tp[j][0]][tp[jj][0]] = tp[j][1] + tp[jj][1];
				mp[tp[jj][0]][tp[j][0]] = tp[j][1] + tp[jj][1];
			}
		}
	}


	//cout << 1;
	/*for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mp[i][j] << ' ';
		}
		cout << endl;
	}*/
	memset(ff, 0x3f3f3f3f, sizeof(ff));
	for (int i = 1; i <= m; i++)
		ff[i][i] = 0;

	//cout << 1;
	for (int i = 1; i <= m; i++) {
		//cout << 1;
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				if (mp[k][j] != 0)
					ff[i][j] = min(ff[i][j], ff[i][k] + mp[k][j]);
			}
		}
	}
	while (q--) {
		cin >> st >> ed;
		cout << w[st] + w[ed] + min(ff[st][ed], ff[ed][st]) << endl;
	}
	return 0;
}