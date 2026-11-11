/*
 * @file migrate.cpp
 * @author Federico Prask
 * @date	2026-10-31
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
	putchar_unlocked(x % 10 + '0');
	return ;
}

constexpr int N = 2e6 + 5;

i64 a[N];

void solveA() {
	int n = read(), d = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	if (n == 1) {
		print(0);
		pn;
		return ;
	}
	int k = a[2] - a[1];
	if (d < 2 * k || d >= 3 * k) {
		print(0);
		pn;
		return ;
	}
	if (n & 1) {
		print(((1ll * n * n) - (n << 2) + 3) / 4);
	} else {
		print(((1ll * n * n) - (n << 2) + 4) / 4);
	}
	pn;
	return ;
}

typedef struct Edge{
	int x, nx;
}eg;
eg e[N << 1];
int head[N], num;
void add_edge(int from, int to) {
	e[++num] = {to, head[from]};
	head[from] = num;
}

std::unordered_map<int, std::pair<int, int>>mp;

i64 bfs(int x) {
	mp.clear();
	std::queue<std::pair<int, int>>q;
	q.push({x, 0});
	while (!q.empty()) {
		auto [x, st] = q.front();
		for (int i = head[x]; i; i = e[i].nx) {
			int y = e[i].x;
			if (mp.find(y) != mp.end()) {
				if (mp[y].first == st + 1) {
					mp[y].second++;
					q.push({y, st + 1});
				} else if (mp[y].first > st + 1) {
					mp[y] = {st + 1, 1};
					q.push({y, st + 1});
				} 
			} else {
				mp[y] = {st + 1, 1};
				q.push({y, st + 1});
			}
		}
	}
	i64 ans = 0;
	for (auto x : mp) {
		int i = x.first;
		auto [aa, bb] = x.second;
		if (bb == 2) {
			ans ++;
		}
	}
	return ans;
}

void solvebl() {
	int n = read(), d = read();
	memset(head, 0, sizeof(int) * (num + 1));
	num = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[i] > d) {
				break;
			}
			add_edge(i, j);
		}
	}
	i64 res = 0;
	for (int i = 1; i <= n; i++) {
		res += bfs(i);
	}
	print(res);
	pn;
	return ;
}

void work(int c) {
	if (c >= 11 && c <= 12) {
		solveA();
	} else {
		solvebl();
	}
}

int main() {
	#ifndef DEBUG
	file(migrate);
	#endif

	int c = read(), t = read();
	while (t--) {
		work(c);
	}

	return 0;
}
// g++ -g migrate.cpp -o migrate -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O2 -static
// g++ -g migrate.cpp -o migrate -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O0 -fsanitize=address,undefined,bounds

/*
谁把我水偷了去养红黑树去了！

我要渴死了!
*/

/*
首先考虑什么时候会形成双径岛屿对。

由于是 “最短路径恰好有两条”

肯定是只会有一次，而且是交错，如下：

u 1 2 1 2 1 2 1 2 1 2 1 2 v

因为如果从 2 到 1 必然会出现长度增加 1 的情况，这是不合理的

先看特殊性质和暴力哪个好写。

首先我还没有想明白如何写判定是否是“双径岛屿对”

暴力方法是直接建图，然后跑 bfs，然后看第一次到达 v 时就不再 push 了，然后这个时候不断 pop，看是否是恰好两个。

然后这个时候可以做一个优化，首先根据 x 有序，然后我们对于每一个节点去做 bfs，然后去做更新

需要注意的是，对于队首，只有右侧的点入队，左侧的点进行更新。

复杂度？最坏 O(n^3)？我不知道。

然后考虑 Subtask A。

设公差为 k，非常好做。

若 d < 2k 或 d >= 3k，则为 0

若 d >= 2k 且 d < 3k，则为 \sum_{i = 1}^n \left \lfloor \frac{n - (i + 1)}{2} \right \rfloor

这个东西好像与奇偶性有关，那我们分别讨论 n - i 为奇数与 为偶数的情况。

成立条件就是两个节点之间有偶数个点。

n 为奇数时候的式子是 \frac{n^2 - 4n + 3}{4}

为偶数的式子是 \frac{n^2 - 4n + 4}{4}

完了完了，不对。
*/