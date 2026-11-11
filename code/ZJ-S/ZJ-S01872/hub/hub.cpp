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

constexpr int N = 1e6 + 5;

int n, m;
vector <int> edg [N];

int dep [N], fth [N];
int w [N], siz [N], tag [N];

void dfs (int u, int fa, int d) {
	w [u] = 1, siz [u] = 0;
	fth [u] = fa;
	dep [u] = dep [fa] + 1;
	for (const int v : edg [u]) {
		if (v == fa) {
			continue ;
		}
		if (fa == 0) {
			tag [v] = v;
		}
		else {
			tag [v] = tag [u];
		}
		dfs (v, u, d);
		siz [u] += siz [v];
		w [u] = max (w [u], w [v] + 1);
	}
	siz [u] += w [u] > d;
}

int rt = 0;

void find_rt () {
	int r = 0;
	vector <pair <int, int> > h (n + 1);
	for (int i = 1; i <= n; i++) {
		dfs (i, 0, 0);
		h [i] = { 0, 0 };
		for (const int u : edg [i]) {
			if (w [u] > h [i].first) {
				h [i].second = h [i].first;
				h [i].first = w [u];
			}
			else if (w [u] > h [i].second) {
				h [i].second = w [u];
			}
			const int k = h [i].first + h [i].second;
			if (k > r) {
				r = k;
			}
		}
	}
	int tmp = r;
	for (int i = 1; i <= n; i++) {
		if (h [i].first + h [i].second == r) {
			const int t = max (h [i].first, h [i].second);
			if (t < tmp) {
				tmp = t;
				rt = i;
			}
		}
	}
}

il bool check (int d) {
	int i = rt;
	dfs (i, 0, d);
	if (siz [i] <= m) {
		return 1;
	}
	multiset <int, greater <int> > ws;
	for (const int v : edg [i]) {
		ws.emplace (w [v]);
	}
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (u == i || v == i)
				continue ;
			if (!siz [u] || !siz [v])
				continue ;
			if (tag [u] == tag [v])
				continue ;
			ws.erase (ws.find (w [tag [u]]));
			ws.erase (ws.find (w [tag [v]]));
			const int mx = ws.empty () ? 0 : *ws.begin ();
			if (dep [u] - dep [i] + mx > d &&
				dep [v] - dep [i] + mx > d) {
				ws.emplace (w [tag [u]]);
				ws.emplace (w [tag [v]]);
				continue ;
			}
			if (siz [u] + siz [v] <= m) {
				return 1;
			}
			ws.emplace (w [tag [u]]);
			ws.emplace (w [tag [v]]);
		}
	}
	return 0;
}

void solve () {
	
	read (n), read (m);
	
	for (int i = 1; i <= n; i++)
		edg [i].clear ();
	
	for (int i = 1; i < n; i++) {
		int u, v;
		read (u), read (v);
		edg [u].emplace_back (v);
		edg [v].emplace_back (u);
	}
	
	if (m == n) {
		printf ("0\n");
		return ;
	}
	
	find_rt ();
	
	int l = 1, r = n - 1;
	int ans = 0;
	while (l <= r) {
		const int mid = l + r >> 1;
		if (check (mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf ("%d\n", ans);
}

namespace subtaskA {
	
	il void solve () {
		
		read (n), read (m);
		for (int i = 1; i <= n; i++)
			edg [i].clear ();
		for (int i = 1; i < n; i++) {
			int u, v;
			read (u), read (v);
			edg [u].emplace_back (v);
			edg [v].emplace_back (u);
		}
		if (m == n) {
			printf ("0\n");
			return ;
		}
		if (m >= n / 2) {
			printf ("1\n");
			return ;
		}
		int l = 2, r = n / 2;
		int ans = n / 2;
		while (l <= r) {
			const int mid = l + r >> 1;
			int h = n / 2 - (mid - 1) - (mid - 1) - ((mid - 1) * 2 - 1);
			if (h <= m) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		printf ("%d\n", ans);
	}
}

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	int c, T;
	read (c), read (T);
	
	if (c == 13 || c == 14) {
		while (T--) {
			subtaskA :: solve ();
		}
		return 0;
	}
	
	while (T--) {
		solve ();
	}
	return 0;
}
