#include <bits/stdc++.h>
//#define int long long

using namespace std;

int _;
inline int read() {char ch = getchar(); int s = 0, w = 1; while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) putchar('-'), x *= -1; if (x > 9) write(x / 10); putchar(x % 10 + '0');}

string c1, s1, c2, s2;
bool f;

inline bool check(char a, char b) {
	if (a <= 'C' && b <= 'C') return 1;
	if (a > 'C' && b > 'C') return 1;
	return 0;
}

inline bool check2(char a, char b) {
	if (a == b + 1) return 1;
	if (a + 1 == b) return 1;
	return 0;
}

inline void solve() {
	cin >> c1 >> s1 >> c2 >> s2;
//	cout << s1.substr(0, 2) << '\n';
	if (c1 == c2) putchar('1'), f = 1;
	else putchar('0');
	if (f && s1.substr(0, 2) == s2.substr(0, 2)) putchar('1');
	else putchar('0'), f = 0;
	if (f && check(s1[2], s2[2])) putchar('1');
	else putchar('0'), f = 0;
	if (f && check2(s1[2], s2[2])) putchar('1');
	else putchar('0'), f = 0;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	_ = 1;
//	_ = read();
	while (_--) solve();
	return 0;
}