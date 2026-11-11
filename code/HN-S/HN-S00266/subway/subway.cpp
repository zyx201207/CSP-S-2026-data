/*
 * @note n3 暴力都能过～
 * @file subway.cpp
 * @author Federico Prask
 * @date 2026-10-31
*/
#include <bits/stdc++.h>
#define file(s) \
	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)

#define pn putchar_unlocked('\n')
#define ps putchar_unlocked(' ')

template<typename T>
T min(T a, T b) { return (a < b) ? a : b; }
template<typename T, typename ... Args>
T min(T a, T b, Args ... args) { return min(min(a, b), args ...); }
template<typename T>
T max(T a, T b) { return (a > b) ? a : b; }
template<typename T, typename ... Args>
T max(T a, T b, Args ... args) { return max(max(a, b), args ...); }
template<typename T>
T gcd(T a, T b) { return std::__gcd(a, b); }
template<typename T, typename ... Args>
T gcd(T a, T b, Args ... args) { return gcd(gcd(a, b), args ...); }

using i64 = long long;
using ull = unsigned long long;
using i28 = __int128;
using f32 = double;
using ldb = long double;

inline i64 read() {
	register i64 res = 0, sgn = 1;
	register char ch = getchar_unlocked();
	for (; !isdigit(ch); ch = getchar_unlocked()) {
		if (ch == EOF) {
			return EOF;
		}
		if (ch == '-') {
			sgn = -1;
		}
	}
	for (; isdigit(ch); ch = getchar_unlocked()) {
		res *= 10;
		res += ch - '0';
	}
	return res * sgn;
}

inline char readc() {
	register char ch = getchar_unlocked();
	while (isspace(ch)) {
		ch = getchar_unlocked();
	}
	return ch;
}

inline std::string readstr() {
	register std::string res;
	register char ch = getchar_unlocked();
	for (; isspace(ch); ch = getchar_unlocked()) ;
	for (; !isspace(ch); ch = getchar_unlocked()) {
		res += ch;
	}
	return res;
}

inline void readcstr(char *s) {
	register char ch = getchar_unlocked();
	for (; isspace(ch); ch = getchar_unlocked()) ;
	for (; !isspace(ch); ch = getchar_unlocked()) {
		*(s++) = ch;
	}
	*s = '\0';
	return ;
}

inline void print(i64 x) {
	if (x > 9) {
		print(x / 10ll);
	}
	putchar_unlocked(x % 10ll + '0');
	return ;
}

constexpr int N = 505;
constexpr int M = 5e5 + 5;

// struct Node{
// 	int id;
// 	i64 val;
// };

// dis
i64 f[N][N];
// 对于站点 i：
// t[i][x] 存储了它的线路 x 的厅台时间
// std::vector<Node>t[M], w[M];
std::unordered_map<int, i64> t[M];
i64 w[M];

void work() {
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) {
		w[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		int k = read();
		for (int j = 1; j <= k; j++) {
			int ak = read(), tk = read();
			t[ak][i] = tk;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::fill(f[i] + 1, f[i] + 1 + n, (LLONG_MAX >> 2ll));
	}
	for (int i = 1; i <= m; i++) {
		int sz = t[i].size();
		for (auto [x, tx] : t[i]) {
			for (auto [y, ty] : t[i]) {
				if (x >= y) {
					continue;
				}
				f[x][y] = f[y][x] = min(f[x][y], (i64)tx + ty);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (k == i) {
				continue;
			}
			for(int j = 1; j <= n; j++) {
				if (j == k || j == i) {
					continue;
				}
				f[i][j] = f[j][i] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		int x = read(), y = read();
		i64 ans = LLONG_MAX;
		for (auto [xi, xt] : t[x]) {
			for (auto [yi, yt] : t[y]) {
				ans = min(ans, f[xi][yi] + yt + xt);
			}
		}
		// printf("%d, %d, %lld", x, y, (ans + w[x] + w[y]));
		print(ans + w[x] + w[y]);
		pn;
	}
	return ;
}

int main() {
	#ifndef DEBUG
	file(subway);
	#endif

	work();

	return 0;
}

// g++ -g subway.cpp -o subway -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O2 -static
// g++ -g subway.cpp -o subway -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O0 -fsanitize=address,undefined,bounds

/*
这个题面有点复杂。

先看范围。你说节点数量不多于 5e5？
等下，它要的是最少步行时间！

注意是步行！

首先进出站的耗时是固定的，我们只需要考虑站台/厅的交换时间。

建立虚树？应该不可能，本质上是个图。

对的对的，线路数量小于等于 500，我意识到只需要处理不同线路之间的最短时间就可以了。

跑 Floyd 是 1.25e8 的，有点卡，但是 CCF 少爷机可以冲过。

初始建立 floyd 是 O(md^2) 的 2e8 有点卡。
不过由于 \sum k 是有上限的，所以这个玩意的最大值其实是 md，1e7 可以过。

对，然后询问是最坏 O(qd^2)，也就是 4e7 的，可以冲过。
（为了查询 x,y 是否在一个线路上，同时更新非一个线路的时间。

先写吧，但是我忘记了 Floyd 到底是 j i k 还是什么了。

f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

看一下怎么提高缓存命中率

我知道了，i k j 循环。

哈哈哈哈什么叫做暴力也能切 T2。

有点吃内存，计算一下。

可以利用 \sum k <= 5e5 来做，最坏情况（std::vector 自带 3 指针，24 Bytes）

15 MB，不卡了。

!!! 最大点仅耗时 300 ms！吓哭了

等一下，它没有给最大点，我们需要自己造。

造了，850ms 左右，实测会更快。

842 881 858 878 828 864 814 891 905 807
*/