#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
bool vis[505][505];
long long sum[100005];
int dj[100005];
int lx[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> dj[i];
	}
	for (int i = 1; i <= n; i++) {
		int gs, x, y;
		cin >> gs >> x >> y;
		vis[x][y] = 1;
		lx[x][y] = i;
	}
	return 0;
}
