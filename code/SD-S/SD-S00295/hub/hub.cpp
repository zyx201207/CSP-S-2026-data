#include <bits/stdc++.h>

using namespace std;

namespace PTqwq {
	
int readqwq() {
	int x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 1e6 + 50;

int n, k;
vector<int> g[N];

namespace SubtaskBF {
	int dis[25][25], dsu[25];
	int findFa(int x) {
		return dsu[x] == x ? x : dsu[x] = findFa(dsu[x]);
	}
	void dfs(int u, int fa, int d, int rt) {
		dis[rt][u] = d;
		for (auto v : g[u]) {
			if (v != fa) {
				dfs(v, u, d + 1, rt);
			}
		}
	}
	void LinkG(int x, int y) {
		x = findFa(x);
		y = findFa(y);
		if (x != y) {
			dsu[x] = y;
		}
	}
	void solveQry1() {
		for (int i = 1; i <= n; ++ i) {
			dfs(i, 0, 0, i);
		}
		int ans = n - 1;
		for (int i = 0; i < (1 << n); ++ i) {
			vector<int> st;
			for (int j = 0; j < n; ++ j) {
				if ((i >> j) & 1) {
					st.push_back(j + 1);
				}
				dsu[j + 1] = j + 1;
			}
			for (auto x : st) {
				for (auto y : g[x]) {
					if ((i << 1) & (1 << y)) {
						LinkG(x, y);
					}
				}
			}
			if (st.size() == k) {
				int curMax = 0, cntPop = 0;
				for (auto x : st) {
					if (dsu[x] == x) cntPop ++;
				}
				for (int x = 1; x <= n; ++ x) {
					int curMin = n + 1;
					for (auto y : st) {
						curMin = min(curMin, dis[x][y]);
					}
					curMax = max(curMax, curMin); 
				}
				if (cntPop <= 2) {
					ans = min(ans, curMax);
				}
			}
		}
		printf("%d\n", ans);
	}
}

namespace Subtask1 {
	int anc[N];
	int cnt, mp[4050][4050], MaxDep[4050];
	int ansVc[12050][4050];
	priority_queue<pair<int, int>> Q;
	
	void preDfs(int u, int fa) {
		MaxDep[u] = 0;
		for (auto v : g[u]) {
			if (v != fa) {
				preDfs(v, u);
				MaxDep[u] = max(MaxDep[u], MaxDep[v] + 1);
			}
		}
	}
	
	void QueryTop(int d, int x) {
		if (Q.empty()) {
			ansVc[d][0] = min(ansVc[d][0], x);
		} else {
			int y = Q.top().first;
			ansVc[d][y] = min(ansVc[d][y], x);
		}
	}
	
	void update_nodes(int u, int fa) {
		for (auto v : g[u]) {
			if (v != fa) {
				Q.emplace(MaxDep[v] + 1, v);
				anc[v] = u;
			}
		}
	}
	
	void queryDFS(int u, int fa) {
		preDfs(u, fa);
		cnt ++;
		mp[u][fa] = cnt;
		anc[u] = fa;
		while (!Q.empty()) {
			Q.pop();
		}
		update_nodes(u, fa);
		for (int i = 0; i <= n; ++ i) {
			ansVc[cnt][i] = n + 1;
		}
		QueryTop(cnt, 1);
		int totI = 1;
		while (!Q.empty()) {
			totI ++;
			int x = Q.top().second; Q.pop();
			update_nodes(x, anc[x]);
			QueryTop(cnt, totI);
		}
		for (int i = 1; i <= n; ++ i) {
			ansVc[cnt][i] = min(ansVc[cnt][i], ansVc[cnt][i - 1]);
		}
	}
	
	int curDP[N], dir[N], dep[N];
	
	void dfs(int u, int fa, int d) {
		anc[u] = fa;
		MaxDep[u] = 0;
		dir[u] = d;
		for (auto v : g[u]) {
			if (v != fa) {
				dfs(v, u, d == 0 ? v : d);
				MaxDep[u] = max(MaxDep[u], MaxDep[v] + 1);
			}
		}
	}
	
	void rdfs(int u, int fa, int d) {
		dep[u] = d;
		int fstMax = -100;
		int scdMax = -100;
		for (auto v : g[u]) {
			if (v != fa) {
				int w = MaxDep[v] + 1;
				if (w > fstMax) {
					scdMax = fstMax;
					fstMax = w;
				} else {
					scdMax = max(scdMax, w);
				}
			}
		}
		for (auto v : g[u]) {
			if (v != fa) {
				if (MaxDep[v] + 1 != fstMax) {
					curDP[v] = max(0, fstMax);
				} else {
					curDP[v] = max(0, scdMax);
				}
				rdfs(v, u, d + 1);
			}
		}
	}
	
	void solveQry() {
		cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			queryDFS(i, 0);
		}
		for (int i = 1; i <= n; ++ i) {
			for (auto j : g[i]) {
				queryDFS(i, j);
			}
		}
		int ans = n - 1;
		for (int i = 1; i <= n; ++ i) {
			while (ans > 0) {
				if (ansVc[mp[i][0]][ans - 1] <= k) {
					ans --;
				} else {
					break;
				}
			}
		}
		for (int i = 1; i <= n; ++ i) {
			curDP[i] = 0;
			dfs(i, 0, 0);
			rdfs(i, 0, -1);
			for (int j = i + 1; j <= n; ++ j) {
				int x = mp[i][dir[j]];
				int y = mp[j][anc[j]];
				int curMin = 0;
				for (int z = j; z != i && anc[z] != i; z = anc[z]) {
					curMin = max(curMin, min(dep[z], dep[j] + 1 - dep[z]) + curDP[z]);
				}
				while (ans > curMin) {
					if (ansVc[x][ans - 1] + ansVc[y][ans - 1] <= k) {
						ans --;
					} else {
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}

void Solve() {
	int curC = readqwq();
	int T = readqwq();
	for (int i = 1; i <= T; ++ i) {
		n = readqwq();
		k = readqwq();
		for (int j = 1; j <= n; ++ j) {
			g[j].clear();
		}
		for (int j = 1; j < n; ++ j) {
			int x = readqwq();
			int y = readqwq();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		Subtask1::solveQry();
	}
}
	
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
