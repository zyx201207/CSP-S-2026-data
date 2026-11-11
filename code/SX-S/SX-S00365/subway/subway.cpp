#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int tmp = 0, tmp2 = 0;

struct x {
	int id, u, v;
} xian[10005];//路线

struct node {
	int id, w, qian;

} q1[100005]; /*模拟队列*/
bool cmp(node a, node b) {
	return a.w > b.w;
}

void insert(node x) {
	q1[++tmp] = x;
	sort(q + 1, q + tmp + 1, cmp);
}

bool emqte() {
	return tmp == 0;
}

node ppop() {
	tmp--;
	return q1[tmp + 1];
}
x zx[505][505];

int w[505]/*出入站*/, t[505][1010]/*路线上下[地铁站][地铁线]*/;
int a[505], vis[505];/*宽搜*/

int dp[505][505];/*结果*/
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		int t1, a1 = 0, a2;
		for (int j = 1; j <= k; j++) {
			a2 = a1;
			cin >> a1 >> t1;
			t[a1][i] = t1;
			if (j >= 2) {
				xian[++tmp2] = {i, a1, a2};
				xian[++tmp2] = {i, a2, a1};
			}
		}
	}
	for (int i = 1; i <= tmp; i++) {
		int u = xian[i].u;
		zx[u][++zx[u][0].id] = xian[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(a, 0x3f, sizeof a);
		memset(vis, 0, sizeof vis);
		insert({i, 0, 0});
		while (!emqte()) {
			node st = ppop();

		}
	}
	return 0;
}