#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 510;
const int maxm = 5e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int test, n, m, d, q, cntr, cnte, idx, X, Y, top, answer;
int wei[maxm], pass[maxm], head[maxm], stk[maxn];
bool vis[maxm];
vector<int> num[maxn], tim[maxn];
vector<pair<int,int>> color[maxm];
struct Graph {
	int u, v, col, nxt;
} edge[maxm << 1];
struct Route {
	int u, v, bel;
} route[maxn][maxn];

void addedge(int u, int v, int col) {
	edge[idx].u = u;
	edge[idx].v = v;
	edge[idx].nxt = head[u];
	edge[idx].col = col;
	head[u] = idx++;
}

void dfs(int u, int fth) {
	if (u == Y) {
		cntr++;
		cnte = 0;
		while(top) {
			int tp = stk[top--];
			route[cntr][++cnte].u = edge[tp].u;
			route[cntr][cnte].v = edge[tp].v;
			route[cntr][cnte].bel = edge[tp].col;
		}
		return;
	}
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].v;
		if (!vis[v]) {
			vis[v] = true;
			stk[++top] = i;
			dfs(v, u);
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf ("%lld", &test);
	scanf ("%lld %lld %lld %lld", &n, &m, &d, &q);
	
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= m; i++) {
		scanf ("%lld", &wei[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &pass[i]);
		
		for (int j = 1; j <= pass[i]; j++) {
			int nnum, ttim;
			scanf ("%lld %lld", &nnum, &ttim);
			num[i].push_back(nnum), tim[i].push_back(ttim);
			color[nnum].push_back(make_pair(i, j)); // 第 i 条线路的第 j 个
		}
		
		for (int j = 0; j < (int)num[i].size() - 1; j++) {
			addedge(num[i][j], num[i][j + 1], i);
			addedge(num[i][j + 1], num[i][j], i);
		}
	}
	
	for (int T = 1; T <= q; T++) {
		scanf ("%lld %lld", &X, &Y);
		
		answer = inf;
		cntr = cnte = top = 0;
		memset(stk, 0, sizeof(stk));
		memset(vis, false, sizeof(vis));
		vis[X] = true;
		dfs(X, 0);
		
		for (int i = 1; i <= cntr; i++) { // X -> Y 有 cntr 条路线，目前考虑第 i 条 
			int res = 0, B = route[i][cnte].bel, minn = inf;
			
//			cout << route[i][cnte].u << ' ' << route[i][cnte].v << ' ' << B << '\n';
			res += wei[X];
//			cout << (int)color[X].size() << '\n';
			for (int it = 0; it < (int)color[X].size(); it++) { // 找到该点对应线路的 time 
				if (color[X][it].first == B) {
					minn = min(minn, tim[B][color[X][it].second - 1]); // tim[i] 是 vector 下标 0 开始 
				}
			}
			res += minn;
			// 初始站进站用时 
			
//			cout << res << ' ' << cnte << '\n';
			
			for (int j = cnte; j > 1; j--) { // 枚举到第 j 条边 
				int u = route[i][j].u, v = route[i][j].v, bel = route[i][j].bel;
				int nxt_u = v, nxt_v = route[i][j - 1].v, nxt_bel = route[i][j - 1].bel;
				
//				cout << u << ' ' << v << ' ' << nxt_v << '\n';
				
				if (bel != nxt_bel) { // 两条边不为同一线路 需要换乘 
					for (int it = 0; it < (int)color[v].size(); it++) {
						if (color[v][it].first == bel) {
							res += tim[bel][color[v][it].second - 1];
						}
						if (color[v][it].first == nxt_bel) {
							res += tim[nxt_bel][color[v][it].second - 1];
						}
					}
				}
			}
			// 途中换乘用时 
			
			B = route[i][1].bel;
			res += wei[Y];
			minn = inf;
			
			for (int it = 0; it < (int)color[Y].size(); it++) {
				if (color[Y][it].first == B) {
					minn = min(minn, tim[B][color[Y][it].second - 1]);
				}
			}
			res += minn;
			// 目的地出站用时 
			
			answer = min(answer, res);
		}
		printf ("%lld\n", answer);
	}
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

可尤其是在下过雨的午后 会想和你重逢
*/