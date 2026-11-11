#include <bits/stdc++.h>
//#define int long long

using namespace std;

int _;
inline int read() {char ch = getchar(); int s = 0, w = 1; while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) putchar('-'), x *= -1; if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 5e5 + 5;
int n, m, a[N], lst[N], pre[N], ans[N];
stack<int> qu;

inline void solve() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) pre[j] = 0;
		for (int j = 1; j <= m; ++j) lst[j] = 0;
		for (int j = i; j <= n; ++j) {
			if (!lst[a[j]]) qu.push(j);
			else {
				while (!qu.empty()) {
//					cout << j << ' ' << qu.top() << '\n';
					if (a[qu.top()] != a[j]) {
						lst[a[qu.top()]] = pre[qu.top()];
//						pre[qu.top()] = 0;
						qu.pop();
						continue;
					} 
//					pre[j] = qu.top();
					qu.pop();
					break;
				}
				qu.push(j);
			}
			lst[a[j]] = j;
		}
		while (!qu.empty()) ++ans[a[qu.top()]], qu.pop();
//		cout << '\n';
	}
	for (int i = 1; i <= m; ++i) write(ans[i]), putchar(' ');
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	_ = 1;
//	_ = read();
	while (_--) solve();
	return 0;
}
/*
4 2
3 15 12 12

*/