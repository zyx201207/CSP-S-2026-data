#include <bits/stdc++.h>
using namespace std;

int n, c, m, d, q;
int ss, s, k; //临时变量
int w[500005];//第i个地铁口走到展厅要w[i]的时间

struct node {
	int aim, time;
} e[1005][1005];
int f[500005];

inline int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

inline void megre(int x, int y) {
	f[find(y)] = find(x);
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> n >> c >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> s >> ss;
			e[i][s].aim = 1; //第i号线经过s站口
			e[i][s].time = ss; //从s展厅走到i号线要 ss 秒的时间

		}
	}
	return 0;
}
/*
这或许是一道最小生成树问题;
从第i到第j个点,之间的边权为
*/




