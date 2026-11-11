//c, n, m, d, q 会不会有一点..了

#include <bits/stdc++.h>
#define int long long
const int MAXN = 520; // 我以前会在这里放三个数字
const int MAXM = 5e5 + 20;
const int INF = 1e18;
void gtmn(int& r, int p) { r = std::min(r, p); }
void gtmx(int& r, int p) { r = std::max(r, p); }

// 忘带卫生纸了, 无语了

int c, n, m, d, q;
int w[MAXM];
int trans[MAXM][22][2], translen[MAXM]; // 你不准当跨性别者(这是不是违规词啊 前面放地铁线路, 后面放到站台的时间

int v[MAXN][MAXN];
void build() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) v[i][j] = INF;
	for (int i = 1; i <= m; i++) {
		for (int st = 0; st < translen[i]; st++) {
			int st_line = trans[i][st][0], st_t = trans[i][st][1];
			for (int ed = 0; ed < translen[i]; ed++) {
				int ed_line = trans[i][ed][0], ed_t = trans[i][ed][1];
				if (ed_line == st_line) { v[st_line][ed_line] = v[ed_line][st_line] = 0; continue; }
				
				gtmn(v[st_line][ed_line], st_t + ed_t);
				gtmn(v[ed_line][st_line], st_t + ed_t);
			}
		}
	}
}

// 我好像不会写 floyd 了
void calc() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				gtmn(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) { scanf("%lld", &w[i]); translen[i] = 0; }
	
	for (int i = 1; i <= n; i++) {
		int k; scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			int sta, t; scanf("%lld %lld", &sta, &t);
			trans[sta][translen[sta]][0] = i; trans[sta][translen[sta]++][1] = t;
		}
	}
	
	build();
	calc();
	
	while (q--) {
		int st, ed; scanf("%lld %lld", &st, &ed);
		int ans = INF;
		for (int i = 0; i < translen[st]; i++) {
			for (int j = 0; j < translen[ed]; j++) {
				int st_line = trans[st][i][0], st_t = trans[st][i][1];
				int ed_line = trans[ed][j][0], ed_t = trans[ed][j][1];
				gtmn(ans, v[st_line][ed_line] + w[st] + w[ed] + st_t + ed_t);
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}

//换乘用时 1e9, 这里是地狱吗

// 大虾高举双钳, 威风不减当年!

// 大常数选手依旧不会卡常