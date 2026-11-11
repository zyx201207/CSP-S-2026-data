/*
给定坐标轴上 n 个点和跳跃距离 d
每次可以从 x 到达 [x, x + d] 上的点
求有多少点对间的最短跳跃次数路径恰好有两条
考虑深刻理解条件
首先，每次跳跃尽量长的距离到达尽量远的点，
可以知道最少跳跃次数
首先，可以用 floyd n^3 求出答案 获得 24 分
猜想这两个方案一定是 正、反 方向的贪心
这个猜想是对的
把反方向的贪心正过来一起跳
如果过程中两个点之间有其他中间的点，那么不合法
跳跃过程中必须恰好有一个不同点，且之间无其他点
从左往右尽力跳，每到一个位置就回头望，中间隔 0 点且不同 ++ans
n^2 的实现一下 40
如果是等差序列，那么看成是自然序列然后每次跳 l = m / d
必须长度为 2l - 1 才只有两个方案
如果 2l - 1 < 0 或是 > n 则输出 0
否则输出 n + 1 - (2l - 1)
48
如果存在一个点能中转所有点
那么跳跃次数 <= 2
可以枚举一对相邻点
要求 a_i, a_{i + 1} 是 x, y 的必经点
则 a_{i - 1} 无法到达 a_y, a_{i + 1} 无法到达 a_x
用 a_i, a_{i + 1} 限定 x，用 a_{i - 1}, a_i 限定 y
先求出 bk 然后处理
56
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e6 + 5, inf = 2e18;
int C, T, n, m, a[N], ans, bk[N], rk[N];
bool vis[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> m, ans = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		int mx = -inf, mn = inf;
		for (int i = 1; i < n; ++i)
			mx = max(mx, a[i + 1] - a[i]), mn = min(mn, a[i + 1] - a[i]);
		if (mx == mn) { // 是等差序列
			int l = m / mx; l = 2 * l;
			if (l == 2 or n + 1 - l < 0 or n + 1 - l > n) cout << 0 << '\n';
			else cout << n + 1 - l << '\n';
		} else if (n <= 5000) {
			for (int o = 1; o <= n; ++o) {
				for (int i = o, pos = o; i <= n; ++i) {
					while (a[pos] + m < a[i]) ++pos; // 跳不过来就往右
					bk[i] = pos, vis[i] = 0;
				}
				vis[o] = 1;
				for (int i = o, lst = o, cnt = 0; i <= n; ++i) {
					if (cnt > 1) break;
					/*
					如果 cnt > 1 则 break
					跳到一个位置的时候要回头望，
					所以我们维护当前点回头望的点的坐标 pos
					我们还需维护 A 型结构区分数量 cnt
					计算当前回头望的 A 型结构区分数量 tmp
					检查 tmp + cnt 以统计答案
					如果当前是 lst 向前望的点 那么需要更新 cnt
					如果当前不能再向后跳则 break
					*/
					int tmp = lst - bk[i];
					if (tmp == 1 and !vis[bk[bk[i]]]) ++tmp;
					ans += (tmp + cnt == 1);
					if (a[lst] + m < a[i + 1]) cnt += tmp, lst = i, vis[i] = 1;
					if (a[i] + m < a[i + 1]) break;
				}
			}
			cout << ans << '\n';
		} else {
			for (int i = 1, pos = 1; i <= n; ++i) { // 求出 bk
				while (a[pos] + m < a[i]) ++pos; // 跳不过来就往右
				bk[i] = pos;
			}
			for (int i = n, pos = n; i >= 1; --i) {
				while (a[pos] - m > a[i]) --pos;
				rk[i] = pos;
			}
			for (int i = 2; i < n - 1; ++i) 
				ans += (bk[i + 2] - bk[i + 1]) * (rk[i] - rk[i - 1]);
			cout << ans << '\n';
		}
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

0 1
2 3
-1 2

0 4
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987

0 1
9 3
1 2 3 4 5 6 7 8 9

0 4
5 5
1 2 5 7 8
7 4
1 3 4 5 7 8 9
7 6
2 5 7 8 10 11 12
8 7
1 4 5 7 8 11 12 13
*/