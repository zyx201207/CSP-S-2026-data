#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p;

int w[10000][10000] = {0};

struct Sub {
	int sta;
	int ti;
} a[505];

struct Sta {
	int start;
	int end;
} a1[100005];

int Serch(int x, int y) {
	for (int i = 1; i <= m; i++) {
		if (w[i][x] != 0 && w[i][x] == w[i][y] )
			return i;
	}
	return 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i][i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> a[j].sta >> a[j].ti;
		}
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= x; k++) {
				if (j != k) {
					w[a[j].sta][a[k].sta] = a[j].ti;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i < j)
				w[i][j] += w[j][i];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > j)
				w[i][j] = w[j][i];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << Serch(i, j) << endl;
			if (w[i][j] == 0 && Serch(i, j)) {
				w[i][j] = w[Serch(i, j)][i] + w[j][Serch(i, j)];
				w[j][i] = w[i][j];
			}
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> a1[i].start >> a1[i].end;
		cout << w[a1[i].start][a1[i].end] + w[a1[i].start][a1[i].start] + w[a1[i].end][a1[i].end] << endl;
	}
	return 0;
}