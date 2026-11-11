/*
 * @file crystal
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
	putchar_unlocked(x % 10 + '0');
	return ;
}

constexpr int N = 5e5 + 5;

i64 a[N];

void work() {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	std::sort(a + 1, a + 1 + n);
	int l = 1, r = 1;
	int ans = 0;
	// needed operations
	i64 ndop = 0;
	while (r < n) {
		r++;
		ndop += (a[r] - a[r - 1]) * (r - l);
		while (ndop > m) {
			ndop -= a[r] - a[l++];
		}
		ans = max(ans, r - l + 1);
	}
	print(ans);
	pn;
	return ;
}

int main() {
	#ifndef DEBUG
	file(crystal);
	#endif

	work();

	return 0;
}

// g++ -g crystal.cpp -o crystal -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O2 -static
// g++ -g crystal.cpp -o crystal -Wall -Wextra -Wshadow -Wpedantic -Warray-bounds -std=c++14 -O0 -fsanitize=address,undefined,bounds

/*
首先简化题意

有 n 个数，你可以进行 m 次操作，每次操作将一个数加 1，求最多可以使得多少个数相同。

（假设我们已经排好序了）

m <= 1e18，最多应该是带个 \log m。

二分？二分值域，二分出最后这些数字等于多少

每次 check 最坏是 O(n) 的，时间复杂度 O(n \log 值域)，可以通过。

首先我们知道不可能让这些 a_i 超过大于自己的位置，因为超过了也没有意义。也就是说上界为 max

不对，假了。对于值域是没有单调性的

但是如果二分数字的数量呢？这个时候就和 m 相关了。

那么我们如何求出最长的呢？

不对！哪里有这么复杂！这是个双指针！

20 min 出思路

复杂度 O(n \log n)，\log 来自排序。

15:00 AC
*/