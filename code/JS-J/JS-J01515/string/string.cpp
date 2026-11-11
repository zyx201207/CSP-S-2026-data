#include <bits/stdc++.h>
using namespace std;
using uns = unsigned;
using ull = unsigned long long;

struct Np {
	ull pla;
	ull ch[26];
	bool operator < (const Np& o) const { return pla < o.pla; }
};

Np q[200005];
uns s[200005];
uns n;
Np lll;

ull rch(ull p, uns h) {
	lll.pla = p;
	Np* base = upper_bound(q + 1, q + n + 1, lll) - 1;
	uns g = base - q;
	if (p == base -> pla || s[g + 1] != h) return base -> ch[h];
	return (base -> ch[h]) + p - (base -> pla);
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	memset(s, 0xff, sizeof s);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	ull l = 0, ans = 0;
	for (uns i = 1; i <= n; ++i) {
		char c; uns p;
		cin >> p >> c;
		q[i].pla = l += p;
		for (uns j = 0; j < 27; ++j) q[i].ch[j] = q[i - 1].ch[j];
		q[i].ch[s[i] = c - 'a'] += p;
	}
	
	
	for (uns i = 1; i <= n; ++i) {
		ull bg = q[i - 1].pla + 1;
		if (bg > l >> 1) break;
		ull ed = min(q[i].pla, l >> 1);
		ull hbg = l + 1 - ed;
		ull hed = l + 1 - bg;
		ull f = rch(hed, s[i]) - rch(hbg - 1, s[i]);
		ans += ed - bg + 1 - f;
	}
	cout << ans;
	
	return 0;
}
