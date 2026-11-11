#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1e9;

ll n, d;
ll x[2000006];
int nxt[2000006];
int blk[2000006];
int blke[2000006];
int cntb = 0;
int dep[2000006];

//struct P{
//	ll x;
//	ll d;
//	bool operator < (const P &y) const {
//		if (this -> d != y.d) return this -> d < y.d;
//		else return x < y.x;
//	}
//} tab[2000006];
//
//
//
//int query(int dp, ll l, ll r) {
//	// [l, r)
//	int posl = lower_bound(tab + 1, tab + 1 + n, {l, dp}) - tab;
//	int posr = lower_bound(tab + 1, tab + 1 + n, {r, dp}) - tab;
//	return posr - posl;
//}

namespace ST{
	
int st[2000006][31];
int lg2[2000006];
void init() {
	for (int i = 2; i <= n; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
}

void build() {
	lg2[1] = 0;
	
	for (int i = 1; i <= n; i++) {
		st[i][0] = dep[i];
//		cerr << st[i][0] << ' ';
	}
//	cerr << endl;
	
	for (int j = 1; j <= 25; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//			cerr << st[i][j] << ' ';
		}
//		if (n - (1 << j) + 1 > 0) cerr << endl;
	}
}

int query(int l, int r) {
	if (l > r) return INF;
	int len = lg2[r - l];
	return min(st[l][len], st[r - (1 << len) + 1][len]);
}

}

ll res = 0;
bool mono[2000006];

void solve2(int maxr) {
	int r = 1;
	for (int i = 1; i <= maxr; i++) {
//		int j = i;
		while (r < maxr && x[r + 1] - x[i] <= d) r++;
//			if (r + 1 > maxr || blk[r + 1] != blk[r]) break;
		nxt[i] = r;
//		cerr << i << " -> " << nxt[i] << ' ';
//		cerr << endl;
	}
	
//	for (int i = 1; i <= maxr; i++) {
//		cerr << nxt[i] << ' ';
//	}
//	cerr << endl;
	
	dep[maxr] = 0;
	for (int i = maxr - 1; i > 0; i--) {
		dep[i] = dep[nxt[i]] + 1;
//		cerr << dep[i] << ' ';
	}
//	cerr << endl;
	
//	for (int i = 1; i <= n; i++) {
//		tab[i] = {x[i], dep[i]};
//	}
//	
//	sort(tab + 1, tab + 1 + n);
	
	ST::build();
	
	int l = blke[blk[maxr] - 1] + 1; r = blke[blk[maxr] - 1] + 2;
	if (r > maxr) return;
	while (r > l) {
		while (r < maxr && x[r + 1] - x[l] <= d) r++;
//		int cnt = query(dep[l] - 1, x[l], x[r]);
		int mind = ST::query(l + 1, r - 1);
//		cerr << l << ' ' << r << ' ' << mind << endl;
		if (mind >= dep[l]) {
			mono[l] = true;
		}
		l++;
	}
	
	l = blke[blk[maxr] - 1] + 1; r = blke[blk[maxr] - 1] + 1;
	int cntm = 0;
	while (r > l) {
		while (mono[l]) l++;
		while (r < maxr && x[r + 1] - x[l] <= d) {
			r++;
			if (mono[r]) cntm++;
		}
		
		if (cntm == 2) res++;
		l++;
	}
}


void clear() {
//	res = 0;
//	cntb = 0;
	
	for (int i = 0; i <= n; i++) {
		nxt[i] = 0;
	}
}

void solve() {
	cin >> n >> d;
	res = 0;
	cntb = 0;
	
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	
	ST::init();
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	
	blk[1] = ++cntb;
	for (int i = 2; i <= n; i++) {
		if (x[i] - x[i - 1] > d) {
			blke[cntb] = i - 1;
			blk[i] = ++cntb;
		} else blk[i] = cntb;
	}
	blke[cntb] = n;
	
	for (int i = 2; i <= n; i++) {
		clear();
		solve2(i);
	}
	
//	res = ll(n) * ll(n - 1) / 2 - res;
	
	cout << res << '\n';
	cerr << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	
	for (int i = 0; i < t; i++) {
		solve();
	}
}
