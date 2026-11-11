#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

namespace Yukari {
const int N = 2e6 + 10;
int n, nxt[N], pre[N], lenr[N], lenl[N], cntnxt[N], cntpre[N]; ll D, X[N];

void Main() {
	cin >> n >> D;
	for (int i = 1; i <= n; i ++) cin >> X[i];

	for (int i = 1, p = 1; i <= n; i ++) {
		while (p < n && X[p + 1] - X[i] <= D) ++ p;
		nxt[i] = p; cntnxt[p] += (p != i);
	}
	for (int i = n, p = n; i >= 1; i --) {
		while (p > 1 && X[i] - X[p - 1] <= D) -- p;
		pre[i] = p; cntpre[p] += (p != i);
	}
	for (int i = 1; i <= n; i ++)
		lenl[i] = cntnxt[i] + ((nxt[pre[i]] == i && pre[i] != i) ? lenl[pre[i]] : 0);
	for (int i = n; i >= 1; i --)
		lenr[i] = cntpre[i] + ((pre[nxt[i]] == i && nxt[i] != i) ? lenr[nxt[i]] : 0);
	ll ans = 0;

	// Case 1
	for (int p = 1; p < n; p ++) if (nxt[pre[p]] == p + 1 && pre[nxt[p + 1]] == p) {
		if (pre[p] == p || nxt[p + 1] == p + 1 || nxt[p] == p + 1 || pre[p + 1] == p) 
			continue;
		ans += 1ll * lenl[pre[p]] * lenr[nxt[p + 1]];
	}
	// Case 2
	for (int p = 1; p < n; p ++) if (pre[p] != p && nxt[p] != p + 1 && nxt[pre[p]] == p + 1) {
		ans += 1ll * lenl[pre[p]] * cntpre[p];
	}
	// Case 3
	for (int p = 1; p < n; p ++) if (nxt[p + 1] != p + 1 && pre[p + 1] != p && pre[nxt[p + 1]] == p) {
		ans += 1ll * lenr[nxt[p + 1]] * cntnxt[p + 1];
	}
	// Case 4
	for (int p = 1; p < n; p ++) if (pre[p] != p && nxt[p + 1] != p + 1 && nxt[p] != p + 1 && pre[p + 1] != p) {
		ans += 1ll * cntpre[p] * cntnxt[p + 1];
	}

	cout << ans << "\n";
	for (int i = 1; i <= n; i ++)
		X[i] = 0, pre[i] = nxt[i] = lenl[i] = lenr[i] = cntnxt[i] = cntpre[i] = 0;
	return ;
}

}

int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int typ, _; cin >> typ >> _;
	while (_ --) Yukari::Main();

	return 0;
}