#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, qq, pos, w[maxn], fa[maxn][25], dis[maxn][25], dep[maxn];
bool vis[maxn];
vector<pair<int, int>> edge[maxn];
struct node {
	int id, s, t;
} q[maxn];
bool cmp(node a, node b) {
	return a.s < b.s;
}
void dfs(int u, int f) {
	fa[u][0] = f;
	rep(j, 1, 20) {
		fa[u][j] = fa[fa[u][j-1]][j-1];
		dis[u][j] = dis[u][j-1] + dis[fa[u][j-1]][j-1];
	}
	for (pair<int, int> p : edge[u]) {
		int v = p.first, ww = p.second;
		if (v != f and !vis[v]) {
			vis[v] = 1;
			fa[v][0] = u;
			dis[v][0] = ww;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}
int solve(int s, int t) {
	int res = 0;
	if (dep[s] < dep[t]) {
		swap(s, t);
	} per(i, 20, 0) {
		if (dep[fa[s][i]] >= dep[t]) {
			res += dis[s][i];
			s = fa[s][i];
		}
	} if (s == t) {
		return res;
	} per(i, 20, 0) {
		if (fa[s][i] != fa[t][i]) {
			res += dis[s][i];
			res += dis[t][i];
			s = fa[s][i];
			t = fa[t][i];
		}
	}
	return res + fa[s][0] + fa[t][0];
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	rep(i, 1, m) {
		cin >> w[i];
	}
	pos = m;
	dep[1] = 1;
	rep(i, 1, n) {
		int num;
		cin >> num;
		rep(j, 1, num) {
			int x, t;
			cin >> x >> t;
			++pos;
			edge[pos].push_back({x, t});
			edge[x].push_back({pos, t});
			if (j > 1) {
				edge[pos-1].push_back({pos, 0});
				edge[pos].push_back({pos-1, 0});
			}
		}
	}
	dfs(1, 0);
	rep(i, 1, qq) {
		int s, t;
		cin >> s >> t;
		cout << w[s] + w[t] + solve(s, t) << endl;
	} 
} 
/*
//freopen
frepoen
frpoene
退役快乐！
SD-S00999祭。
owo qwq TwT ovo qvq TvT o_o q_q T_T qoq ToT
password: Oct31==Dec25?
差点忘了在代码里用那种语言会被休息三年了。——at 18:21 
*/
