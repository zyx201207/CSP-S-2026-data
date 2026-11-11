#include <bits/stdc++.h>

using namespace std;

int c, t;
int a[2000006];
int p[5005][5005];
int mnlen = 1e9;
void dfs(int n, int d, int st, int ed, int x, int len) {
	if (x == ed) {
		if (len < mnlen) {
			mnlen = len;
			p[st][ed] = 0;
			p[st][ed]++;
		} else if (len == mnlen) {
			p[st][ed]++;
		}
		return;
	}
	for (int i = x + 1; i <= n; i++) {
		if (abs(a[x] - a[i]) <= d) {
			dfs(n, d, st, ed, i, len + 1);
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mnlen = 1e9;
				dfs(n, d, i, j, i, 0);
				if (p[i][j] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
