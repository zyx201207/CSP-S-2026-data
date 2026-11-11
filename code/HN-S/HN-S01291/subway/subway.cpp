#include <iostream>
#include <random>
#include <cstring>
#include <tuple>
#include <algorithm>
#define popcount __builtin_popcount
#define stop_sync do { ios::sync_with_stdio(false); cin.tie(nullptr); } while (0)
#define fileio(s) do { freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout); } while (0)
#define rep(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define repl(i, a, b) for (int i = (int) (a); i < (int) (b); i++) 
#define per(i, a, b) for (int i = (int) (a); i >= (int) (b); i--)
#define nocpy const auto &
#define endl '\n'
#define all(iter) (iter).begin(), (iter).end()
#define pred(it, expr) [&] (nocpy it) { return (expr); }
#define comp(lhs, rhs, expr) [&] (nocpy lhs, nocpy rhs) { return (expr); }
#define update_v(v, expr, func) (v) = func((v), (expr))
#define zeroize(v) memset(v, 0x00, sizeof(v))
#define invalidate_max(v) memset(v, 0x3f, sizeof(v))

// 是个人物, 预处理指令写 19 行 
 
using namespace std;
using i64 = long long;

constexpr int MAXN = 5e2 + 10, MAXM = 5e5 + 10;


i64 closure[MAXN][MAXN]; 	// 从一个线路的站台走上另一个线路的站台, 至少需要多少步行时间.
						  	// 问题就在于这个数组要怎么算, 大概率是 Floyd
							// 没关系, 出题人还是很良心的, 一个车站连出去的边很少, 平方建图就行 
							// 回答询问的时候也是平方级别的, 对于两个地铁口, 直接加上走进站内的时间和 (u -> i -> j -> v) 去一个 min 就好, 也是平方
							// 只求能 1e8 - 2e8 卡过去了, 依旧是别样的常数大战, 能赢吗
							// 希望 Computers are faster nowdays 是真的吧
							// 哇我刚看了一眼才发现 sumK 是固定的, 竟然没有各个车站独立的吗, 这把有了 
							// 给所有车站都连一条边就行, CCF 你人太好了 
							
						   
struct Edge { i64 v, w; };
 
vector<Edge> to[MAXM];

inline int read() {
	int d = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) d = d * 10 + (c - '0'), c = getchar();
	return d;
} 

int c, n, m, d, q;
i64 dw[MAXM]; 

void input() {
	c = read(), n = read(), m = read(), d = read(), q = read();
	rep(i, 1, m) dw[i] = read();
	rep(i, 1, n)  {
		int ki = read(); 
		rep(j, 1, ki) { int v = read(), w = read(); to[v].push_back({i, w}); }
	}
}

void preprocess() {
	invalidate_max(closure); rep(i, 1, n) closure[i][i] = 0; 
	rep(i, 1, m) {
		repl(l, 0, to[i].size()) repl(r, l + 1, to[i].size()) {
			nocpy e1 = to[(size_t) i][(size_t) l], e2 = to[(size_t) i][(size_t) r]; // 好吧我也不知道少 copy 4 个 byte 算不算卡常
			update_v(closure[e1.v][e2.v], e1.w + e2.w, std::min); 
			update_v(closure[e2.v][e1.v], e2.w + e1.w, std::min);
		}
	} 
}

void floyd() {
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
		update_v(closure[i][j], closure[i][k] + closure[k][j], std::min);
}

// 大概是 4e7 的复杂度吧 
i64 answer_query() {
	int l = read(), r = read();
	i64 ret = LLONG_MAX;
	repl(i, 0, to[l].size()) repl(j, 0, to[r].size()) {
		nocpy e1 = to[(size_t) l][(size_t) i], e2 = to[(size_t) r][(size_t) j];
		update_v(ret, e1.w + closure[e1.v][e2.v] + e2.w, std::min);
	}
	return dw[l] + ret + dw[r];
}


int main() {
	stop_sync;
	fileio("subway");
	input();
	preprocess();
	floyd();
	while (q--) cout << answer_query() << endl;
	return 0;
} 
