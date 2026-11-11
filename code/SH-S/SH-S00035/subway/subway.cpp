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

const int N = 510, M = 5e5 + 10;
int n, m, d, q, p[M], dis[N][N], t[M], a[M];
int kk[M];
struct subwaynode{
	int id, tim;
};
vector<subwaynode> sub[M];
void solve1(){
	// 1-8 32pts
	n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) p[i] = read();
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 1, m) dis[i][i] = 0;
	rep(i, 1, n){
		int kkk = read();
		rep(j, 1, kkk){
			a[j] = read(), t[j] = read();
		}
		rep(j, 1, kkk)
			rep(k, j + 1, kkk){
				dis[a[j]][a[k]] = min(dis[a[j]][a[k]], t[j] + t[k]);
				dis[a[k]][a[j]] = min(dis[a[k]][a[j]], t[j] + t[k]);
			}
	}
	rep(k, 1, m)
		rep(i, 1, m)
			rep(j, 1, m)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--){
		int u = read(), v = read();
		printf("%lld\n", dis[u][v] + p[u] + p[v]);
	}
}
void solve2(){
	// 9-15,22,23 68pts O(n^3 + m*d^2 + q*d^2)
	n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) p[i] = read();
	rep(i, 1, n){
		kk[i] = read();
		rep(j, 1, kk[i]){
			int aa = read(), tt = read();
			sub[aa].push_back(subwaynode{i, tt});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 1, n) dis[i][i] = 0;
	rep(x, 1, m){
		repp(i, 0, sub[x].size()){
			repp(j, 0, sub[x].size()){
				dis[sub[x][i].id][sub[x][j].id] = min(dis[sub[x][i].id][sub[x][j].id], sub[x][i].tim + sub[x][j].tim);
			}
		}
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--){
		int u = read(), v = read();
		int res = 1e18;
		repp(i, 0, sub[u].size()){
			repp(j, 0, sub[v].size()){
				res = min(res, dis[sub[u][i].id][sub[v][j].id] + sub[u][i].tim + sub[v][j].tim);
			}
		}
		printf("%lld\n", res + p[u] + p[v]);
	}
}
void solve3(){
	// goal: 100pts m*d^2 -> m*d O(n^3 + m*d^2 + q*d^2) 
	n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) p[i] = read();
	rep(i, 1, n){
		kk[i] = read();
		rep(j, 1, kk[i]){
			int aa = read(), tt = read();
			sub[aa].push_back(subwaynode{i, tt});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 1, n) dis[i][i] = 0;
	rep(x, 1, m){
		repp(i, 0, sub[x].size()){
			repp(j, 0, sub[x].size()){
				dis[sub[x][i].id][sub[x][j].id] = min(dis[sub[x][i].id][sub[x][j].id], sub[x][i].tim + sub[x][j].tim);
			}
		}
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--){
		int u = read(), v = read();
		int res = 1e18;
		repp(i, 0, sub[u].size()){
			repp(j, 0, sub[v].size()){
				res = min(res, dis[sub[u][i].id][sub[v][j].id] + sub[u][i].tim + sub[v][j].tim);
			}
		}
		printf("%lld\n", res + p[u] + p[v]);
	}
}
void solve(){
	int c = read();
	if (c <= 8) solve1();
	else if (c <= 15 || c == 22 || c == 23) solve2();
	else solve3();
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int t = 1;
	while (t--) solve();
	return 0;
}
