// CSP 2026 rp++
// 多测清空
// 保证 sumn 手动清空
// 四倍线段树 
// 滚动数组清空
// long long 要不要开
// 开了会不会 MLE
// 代码过编译
// freopen 写对
// 文件名写对 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define repp(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define perr(i, a, b) for (int i = (a); i > (b); i--)
#define endl '\n'
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
inline int read(){
	int res = 0, f = 1; char c = getchar();
	while (!isdigit(c)){ if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
	return res * f;
}

// Definitions.

const int N = 310;
int n, d, dis[N][N], dis2[N][N], dis3[N][N], a[N];
bool vis[N];
struct edge{
	int nxt, val;
};
bool operator > (const edge &x, const edge &y){
	return x.val > y.val;
}
vector<int> g[N];
priority_queue<edge, vector<edge>, greater<edge> > q;
void dijkstra(int s){
	while (!q.empty()) q.pop();
	rep(i, 1, n) vis[i] = 0;
	dis[s][s] = 0;
	vis[s] = 0;
	q.push(edge{s, 0});
	while (!q.empty()){
		int x = q.top().nxt;
		q.pop();
		if (vis[x]) continue;
		repp(i, 0, g[x].size()){
			int y = g[x][i];
			int nw = dis[s][y] + 1;
			if (dis[s][y] > dis[s][x] + 1){
				dis3[s][y] = dis2[s][y];
				dis2[s][y] = dis[s][y];
				dis[s][y] = dis[s][x] + 1;
				if (!vis[y]) q.push(edge{y, dis[s][y]});
			}
			else if (dis2[s][y] > dis[s][x] + 1){
				dis3[s][y] = dis2[s][y];
				dis2[s][y] = dis[s][x] + 1;
			}
			else if (dis3[s][y] > dis[s][x] + 1){
				dis3[s][y] = dis[s][x] + 1;
			}
		}
	}
}
void solve1(){
	rep(i, 1, n)
		rep(j, 1, n)
			dis[i][j] = dis2[i][j] = dis3[i][j] = 0x3f3f3f3f3f3f3f3f;
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, n)
		rep(j, i + 1, n)
			if (a[j] - a[i] <= d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
	rep(i, 1, n) dijkstra(i);
//	rep(i, 1, n){
//		rep(j, 1, n)
//			if (dis[i][j] > 1e18) printf("inf ");
//			else printf("%3lld ", dis[i][j]);
//		puts("");
//	}
//		puts("");
//	rep(i, 1, n){
//		rep(j, 1, n)
//			if (dis2[i][j] > 1e18) printf("inf ");
//			else printf("%3lld ", dis2[i][j]);
//		puts("");
//	}
//		puts("");
//	rep(i, 1, n){
//		rep(j, 1, n)
//			if (dis3[i][j] > 1e18) printf("inf ");
//			else printf("%3lld ", dis3[i][j]);
//		puts("");
//	}
	int ans = 0;
	rep(i, 1, n)
		rep(j, i + 1, n)
			if (dis[i][j] == dis2[i][j] && dis[i][j] != dis3[i][j] && dis2[i][j] != dis3[i][j])
				ans++;
	printf("%lld\n", ans);
}
void solve(int cas){
	// 多测不清空，亲人两行泪
	rep(i, 1, n) g[i].clear();
	n = read(), d = read();
	rep(i, 1, n) a[i] = read();
	if (n <= 300) solve1(); 
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), t = read();
	while (t--) solve(c);
	return 0;
}

/*

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

AC:
12

Myans:
14
*/
