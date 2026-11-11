/*
 * @file
 * @author
 * @date
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

constexpr int N = 1e6 + 5;

typedef struct Edge {
	int x, nx;
}eg;
eg e[N << 1];
int head[N], num;
void add_edge(int from, int to) {
	e[++num] = {to, head[from]};
	head[from] = num;
}

void clear(int n) {
	memset(head, 0, sizeof(int) * ((n << 1) | 1));
	num = 0;
}

bool 

// 钦定
void dfsqd(int cnt) {
	for (int i = 1; i <= )
}

void work() {
	int n = read(), k = read();
	clear(n);
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

}

int main() {
	#ifndef DEBUG
	file(hub);
	#endif

	int c = read(), t = read();
	while (t--) {
		work();
	}

	return 0;
}

