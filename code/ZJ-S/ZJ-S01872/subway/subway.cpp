%:include <bits/stdc++.h>
using namespace std;

# define il inline

using i64 = long long;

il void read (int &x) {
	x = 0;
	char ch = getchar ();
	int negative = 0;
	for (; !isdigit (ch); ch = getchar ())
		negative = (ch == '-');
	for (; isdigit (ch); ch = getchar ())
		x = (x << 3) + (x << 1) + (ch & 15);
	negative ? x = -x : 0;
}

il void read_i64 (i64 &x) {
	x = 0;
	char ch = getchar ();
	int negative = 0;
	for (; !isdigit (ch); ch = getchar ())
		negative = (ch == '-');
	for (; isdigit (ch); ch = getchar ())
		x = (x << 3) + (x << 1) + (ch & 15);
	negative ? x = -x : 0;
}

char stk [32];

il void write (int x) {
	if (x < 0) {
		putchar ('-');
		x = -x;
	}
	if (x == 0) {
		putchar ('0');
		return ;
	}
	int tp = 0;
	while (x) {
		stk [++tp] = (x % 10) | 48;
		x /= 10;
	}
	while (tp) {
		putchar (stk [tp--]);
	}
}

il void write_i64 (i64 x) {
	if (x < 0) {
		putchar ('-');
		x = -x;
	}
	if (x == 0) {
		putchar ('0');
		return ;
	}
	int tp = 0;
	while (x) {
		stk [++tp] = (x % 10) | 48;
		x /= 10;
	}
	while (tp) {
		putchar (stk [tp--]);
	}
}

constexpr int N = 505;

constexpr int M = 5e5 + 5;

constexpr int K = 5e5 + 5;

constexpr i64 INF = 1e12;

int c, n, m, d, q, w [M];
i64 dis [N][N];

vector <pair <int, int> > way [M];

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	
	read (c);
	read (n), read (m);
	read (d), read (q);
	
	for (int i = 1; i <= m; i++)
		read (w [i]);
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				dis [i][j] = INF;
		
	for (int i = 1; i <= n; i++) {
		int k;
		read (k);
		for (int j = 0; j < k; j++) {
			int p, t;
			read (p), read (t);
			way [p].emplace_back (i, t);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (const auto x : way [i]) {
			const int s = x.first;
			const int p = x.second;
			for (const auto y : way [i]) {
				const int t = y.first;
				const int q = y.second;
				dis [s][t] = min (dis [s][t], (i64) p + q);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis [i][j] = min (dis [i][j], dis [i][k] + dis [k][j]);
				
	for (int i = 1; i <= q; i++) {
		int u, v;
		read (u), read (v);
		i64 ans = INF;
		for (const auto x : way [u]) {
			const int s = x.first;
			const int p = x.second;
			for (const auto y : way [v]) {
				const int t = y.first;
				const int q = y.second;
				ans = min (ans, dis [s][t] + p + q);
			}
		}
		write_i64 (ans + w [u] + w [v]);
		putchar ('\n');
	}
	
	return 0;
}
