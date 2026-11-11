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

constexpr int N = 2e6 + 6;

int n;
i64 d, a [N];

namespace subtask1 {
	// N <= 5000
	void solve () {
		read (n), read_i64 (d);
		for (int i = 1; i <= n; i++) {
			read_i64 (a [i]);
		}
		vector <pair <int, int> > f (n + 1);
		vector <pair <int, int> > h (n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			f [i] = { 0, 1 };
			
			int hd = 1, tl = 0;
			auto emplace = [&] (int p) {
				if (hd <= tl && f [p].first == h [tl].first) {
					h [tl].second += f [p].second;
				}
				else {
					h [++tl] = f [p];
				}
			};
			auto pop = [&] (int p) {
				h [hd].second -= f [p].second;
				hd += h [hd].second == 0;
			};
			emplace (i);
			
			int p = i;
			for (int j = i + 1; j <= n; j++) {
				while (a [j] - a [p] > d) {
					pop (p++);
				}
				f [j] = h [hd];
				f [j].first++;
				f [j].second = min (f [j].second, 3);
				ans += f [j].second == 2;
				emplace (j);
			}
		}
		printf ("%d\n", ans);
	}
}

namespace subtaskB {
	il void solve () {
		read (n), read_i64 (d);
		for (int i = 1; i <= n; i++)
			read_i64 (a [i]);
		vector <int> pre (n + 2, 0);
		vector <int> suf (n + 2, 0);
		pre [1] = 1;
		for (int i = 2; i <= n; i++) {
			pre [i] = pre [i - 1];
			for (; a [i] - d > a [pre [i]]; pre [i]++) ;
		}
		suf [n] = n;
		for (int i = n - 1; i >= 1; i--) {
			suf [i] = suf [i + 1];
			for (; a [i] + d < a [suf [i]]; suf [i]--) ;
		}
		
		auto move_to = [&] (int &ptr, i64 x) {
			for (; ptr && a [ptr] > x; ptr--) ;
		};
		
		i64 res = 0;
		int p = n, q = n;
		for (int i = n; i >= 1; i--) {
			if (suf [i] - i >= 2) {
				move_to (p, a [suf [i] - 1] + d);
				move_to (q, a [suf [i] - 2] + d);
				res += p - q;
			}
		}
		write_i64 (res);
		putchar ('\n');
		return ;
	}
}

namespace subtask {
	il i64 calc (
		const vector <i64> &a,
		int n, i64 d
	) {
		vector <int> pre (n + 2, 0);
		vector <int> suf (n + 2, 0);
		pre [1] = 1;
		for (int i = 2; i <= n; i++) {
			pre [i] = pre [i - 1];
			for (; a [i] - d > a [pre [i]]; pre [i]++) ;
		}
		suf [n] = n;
		for (int i = n - 1; i >= 1; i--) {
			suf [i] = suf [i + 1];
			for (; a [i] + d < a [suf [i]]; suf [i]--) ;
		}
		
		vector <int> pre_cnt (n + 2, 0);
		vector <int> suf_cnt (n + 2, 0);
		
		for (int i = 1; i <= n; i++) {
			++suf_cnt [pre [i]];
		}
		for (int i = n; i >= 1; i--) {
			++pre_cnt [suf [i]];
		}
		
		auto move_to = [&] (int &ptr, i64 x) {
			for (; ptr && a [ptr] > x; ptr--) ;
		};
		
		i64 res = 0;
		int p = n, q = n;
		for (int i = n; i >= 1; i--) {
			if (suf [i] - i >= 2) {
				move_to (p, a [suf [i] - 1] + d);
				move_to (q, a [suf [i] - 2] + d);
				if (p > q)
					res += (i64) (pre_cnt [i] + 1) * (p - q),
					res += (i64) (pre_cnt [i] + 1) * suf_cnt [p];
			}
		}
		return res;
	}
	il void solve () {
		read (n), read_i64 (d);
		vector <i64> arr { 0 };
		i64 ans = 0;
		for (int i = 1; i <= n; i++) {
			i64 x;
			read_i64 (x);
			if (arr.size () && x - arr.back () > d) {
				ans += calc (arr, (int) arr.size (), d);
				arr = { 0 };
			}
			arr.emplace_back (x);
		}
		ans += calc (arr, (int) arr.size () - 1, d);
		write_i64 (ans);
		putchar ('\n');
	}
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	int c, T;
	read (c), read (T);
	
	if (c <= 10) {
		for (int _ = 1; _ <= T; _++) {
			subtask1 :: solve ();
		}
		return 0;
	}
	
	if (c == 13 || c == 14) {
		for (int _ = 1; _ <= T; _++) {
			subtaskB :: solve ();
		}
		return 0;
	}
	
	for (int _ = 1; _ <= T; _++) {
		subtask :: solve ();
	}
	return 0;
}
