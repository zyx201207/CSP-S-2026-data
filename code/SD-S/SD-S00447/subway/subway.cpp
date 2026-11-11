#include <bits/stdc++.h>

#define int long long 

#define PII pair<int, int>

#define mkp make_pair

using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const int D = 25;
const int inf = 1e18;

struct Edge {
	int nxt;
	int w;
	int v;
};

int c, n, m, d, q;
int f[N][N]; //地铁之间的距离 
int hd[M]; //站点出发的链表头部
Edge e[M * D]; //存储边表 
int edg_cnt;
int WT[M];

void addedge(int from, int to, int tme) {
	++edg_cnt;
	e[edg_cnt].v = to;
	e[edg_cnt].w = tme;
	e[edg_cnt].nxt = hd[from];
	hd[from] = edg_cnt;
}

void readin() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> WT[i];
	}
	for (int i = 1; i <= n; ++i) {
		//读入地铁
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int arv, t;
			cin >> arv >> t;
			addedge(arv, i, t);
		} 
	}
}

void preprocess() {
	//处理
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		//枚举站点
		for (int j = hd[i]; j; j = e[j].nxt) {
			int to_1 = e[j].v;
			int w_1 = e[j].w;
			for (int k = hd[i]; k; k = e[k].nxt) {
				int to_2 = e[k].v;
				if (to_2 == to_1) continue;
				int w_2 = e[k].w;
				f[to_1][to_2] = min(f[to_1][to_2], w_1 + w_2);
			}
		}
	} 
	//floyd
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}

int getans(int x_, int y_) {
	//进入x_,出去y_
	int ans = inf;
	for (int i = hd[x_]; i; i = e[i].nxt) {
		for (int j = hd[y_]; j; j = e[j].nxt) {
			int poss_a = e[i].w + e[j].w + f[e[i].v][e[j].v];
			ans = min(ans, poss_a);
		}
	}	 
	//加上w[x_]+w[y_]
	ans += WT[x_];
	ans += WT[y_];
	return ans;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	readin();
	preprocess();
//	cout << f[1][2] << "\n";
//	cout << f[1][1] << "\n";
//	cout << f[2][2] << "\n";
	while (q--) {
		int u_, v_;
		cin >> u_ >> v_;
		cout << getans(u_, v_) << "\n";
	}
	return 0;
}
