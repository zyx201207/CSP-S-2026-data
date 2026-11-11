#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 7e6 + 6;
struct Trie {
	int c, lp, rp, op;
} tr[M];
int n, m, a[N], mx, ans, t = 1;
string s = " ";
void dfs(int x, int c, int res) {
	if (c == m) {
		ans = max(ans, res);
		return ;
	}
	if (x > n) {
		if (c != m) return ;
		ans = max(ans, res);
		return ;
	}
	dfs(x + 1, c, res);
	if (c == 0) dfs(x + 1, c + 1, a[x]);
	else dfs(x + 1, c + 1, res & a[x]);
	return ;
}
int qpow(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	int t = qpow(x >> 1);
	if (x & 1) return t * t << 1;
	return t * t;
}
void insert(int x) {
	int p = 1;
	//cout << "\n" << x << ":\n";
	for (int i = 30; i >= 0; i--) {
		tr[p].c++;
		//cout << i << " " << p << " " << (x & qpow(i)) << " " << tr[p].op << "\n";
		if (i == 0) break;
		if (x & qpow(i - 1)) {
			if (tr[p].lp == 0) {
				tr[p].lp = ++t;
			}
			p = tr[p].lp; tr[p].op = 1;
		} else {
			if (tr[p].rp == 0) tr[p].rp = ++t;
			p = tr[p].rp;
		}
	}
	return ;
}
void query(int x) {
	int p = 1;
	for (int i = 30; i >= 0; i--) {
		s += (char)(tr[p].op + 48);
		//cout << p << " " << tr[p].lp << " " << tr[tr[p].lp].c;
		//cout << " " << tr[p].rp << " " << tr[tr[p].rp].c << "\n";
		if (tr[p].lp != 0 && tr[tr[p].lp].c >= m) p = tr[p].lp;
		else if (tr[p].rp != 0 && tr[tr[p].rp].c >= m) p = tr[p].rp;
		else break;
	}
	return ;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; insert(a[i]);
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			for (int k = j + 1; k <= n; k++) {
//				ans = max(ans, a[i] & a[j] & a[k]);
//				if (ans == 7) cout << i << " " << j << " " << k << "\n";
//			}
//		}
//	}
//	cout << ans; return 0;
	if (n == m) {
		for (int i = 2; i <= n; i++) a[i] &= a[1];
		cout << a[1]; return 0;
	} else if (m == 1) {
		for (int i = 2; i <= n; i++) a[1] = max(a[1], a[i]);
		cout << a[1]; return 0;
	} else if (m == 2) {
		mx = a[1] & a[2];
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) mx = max(mx, a[i] & a[j]);
		cout << mx; return 0;
	} else if (n <= 20) {
		dfs(1, 0, qpow(30) - 1); cout << ans; return 0;
	}
	query(1); int ll = s.size() - 1;
	for (int i = 1; i <= ll; i++) {
		if (s[i] == '1') ans += qpow(ll - i);
	}
	cout << ans;
	return 0;
}