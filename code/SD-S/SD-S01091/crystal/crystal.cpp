#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
namespace IO {
const int SIZ = 1 << 20;
char buf[SIZ], *nw, *ed;
inline char getchar() {
	if (nw == ed) ed = buf + fread(buf, sizeof(char), SIZ, stdin), nw = buf;
	return *(nw++);
}
template<typename T> void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	x *= f;
}
template<typename T, typename ...Args> void read(T &x, Args &...args) {
	read(x), read(args...);
}
}
using IO::read;
using ll = long long;
const int N = 5e5 + 10;
ll a[N], s[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	read(n, m);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	auto calc = [&](int l, int r) {
		return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
	};
	int ans = 0;
	for (int l = 1, r = 0; l <= n; l++) {
		while (r < n && calc(l, r + 1) <= m) r++;
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
}
