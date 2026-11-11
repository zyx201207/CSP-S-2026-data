#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m;
	int k[m] = {};

	int a[n];//每张牌
	int b[n][n] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 4; i >= 1; i--) { //大游戏局数
		for (int j = 1; j <= i; j++) { //每局游戏
			int u = j;
			bool f = false;
			for (int x = 1; x <= n; x++) { //拿牌
				if (b[n + i - 1][x] == a[j]) {
					for (int z = x; z <= n; z++) {
						b[n + i - 1][z] = 0;
					}
					u = x;
					f = true;
					break;
				}
			}
			//----------
			b[n + 1 - i][u] = a[j];
		}

	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << b[i][j] << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= m; p++) {
			for (int j = 1; j <= n; j++) {
				if (b[i][j] == m) {
					k[m]++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << k[m] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}