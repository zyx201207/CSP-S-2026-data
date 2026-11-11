#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int x[N], s[N][N], c[N][N];
int n, m;

int zhao(int u, int v, int cnt) {
	if (u >= v) {
		if (s[u][v] >= cnt) {
			s[u][v] = cnt;
			c[u][v] = 1;
		} else {
			c[u][v]++;
		}
		return 0;
	}
	for (int i = u; i < n; i++) {
		for (int j = v - 1; j >= 0; j--) {
			zhao(i, j, cnt + 1);
		}
	}
	return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c1, t;
	cin >> c1 >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			for (int j = 0; j < n; j++) {
				c[i][j] = 0;
			}
		}
		zhao(0, n - 1, 0);
		int su = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//cout << c[i][j] << " ";
				if (c[i][j] == 2) {
					su++;
				}
			}
			cout << endl;
		}
		cout << su << endl;
	}
	return 0;
}
