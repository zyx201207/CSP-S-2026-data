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

std::mt19937 myrand(time(NULL) * time(NULL) * time(NULL));

int sta[25005];

void work() {
	print(0);
	ps;
	print(500);
	ps;
	print(25000);
	ps;
	print(20);
	ps;
	print(100000);
	pn;
	i64 mx64 = 9223372036854775807ll;
	i64 mx32 = 2147473647;
	i64 mx = 1000000000;
	for (int i = 1; i <= 25000; i++) {
		i64 cur = myrand() * myrand() % mx64 * myrand() % mx + 1;
		print(cur);
		ps;
	}
	pn;
	for (int i = 1; i <= 500; i++) {
		print(1000);
		ps;
		for (int j = 1; j <= 1000; j++) {
			i64 cur = myrand() * myrand() % mx64 * myrand() % 25000 + 1;
			while (sta[cur] == 20) {
				cur = myrand() * myrand() % mx64 * myrand() % 25000 + 1;
			}
			sta[cur]++;
			print(cur);
			ps;
			cur = myrand() * myrand() % mx64 * myrand() % mx + 1;
			print(cur);
			ps;
		}
		pn;
	}
	for (int i = 1; i <= 100000; i++) {
		i64 x = myrand() * myrand() % mx64 * myrand() % 25000 + 1;
		i64 y = myrand() * myrand() % mx64 * myrand() % 25000 + 1;
		print(x);
		ps;
		print(y);
		pn;
	}
	return ;
}

int main() {
	#ifndef DEBUG
	// file();
	#endif
	freopen("subway.in", "w", stdout);

	work();

	return 0;
}
/*
最坏情况是
n = 500
25000 = 25000
d = 20
q = 100000
*/