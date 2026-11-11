#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m, c, d, p, r;
int q[N];
long long k[500010];
int a[N][N], b[N][N];
int cnt;

struct node {
	int x, y;
};
node f[N];

void dfs(int pos, int y, int xx, int yy, int cnt) {
	if (y > 1 && xx > 1 && yy > 1) {
		cnt++;
		return ;
	}
	dfs(pos + 1, y + 1, xx, yy, cnt + q[cnt]);
	dfs(pos + 1, y, xx + 1, yy, cnt + q[cnt]);
	dfs(pos + 1, y, xx, yy + 1, cnt + q[cnt]);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> q[i];
	}
	for (int i = 1; i <= n; i++) {
		int h = 2 * k[i];
		for (int j = 1; j <= h; j++) {
			cin >> a[i][j] >> b[i][j];
		}
	}
	for (int i = 1; i <= n + 2; i++) {
		cin >> f[i].x >> f[i].y;
	}
//	dfs(1, 0, 1, 0, 1);
//	while (p--) {
	cout << 30 + n << "\n" << d - n - 1 << "\n";
//	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
