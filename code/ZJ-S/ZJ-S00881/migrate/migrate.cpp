#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll C, T, n, d, x[2001000], stp[2001000], cnt[2001000], pos[2001000], cst[2001000], ma, dps, dpc, hd, tl, ans;
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	ans = 0;
	for (int i = 1; i <= n; i ++) {
		hd = 1, tl = 0;
		dps = 0, dpc = 1;
		tl ++, stp[tl] = 0, cnt[tl] = 1, pos[tl] = x[i];
		ma = 0;
		cst[0] = 1;
		for (int j = i + 1; j <= n; j ++) {
			while (x[j] - pos[hd] > d && hd <= tl) cst[stp[hd]] -= cnt[hd], hd ++;
			if (hd > tl) break;
			dps = stp[hd] + 1;
			dpc = min(cst[stp[hd]], 3ll);
			while (stp[tl] > dps && hd <= tl) cst[stp[tl]] -= cnt[tl], tl --;
			tl ++, stp[tl] = dps, cnt[tl] = dpc, pos[tl] = x[j];
			if (dps > ma) ma ++, cst[ma] = dpc;
			else cst[dps] += dpc;
			if (dpc == 2) ans ++;
		}
	}
	cout << ans << '\n';
}
void solveA() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	if (n == 1) cout << 0 << '\n';
	else {
		ll cha = x[2] - x[1];
		if (cha > d / 2) cout << 0 << '\n';
		else {
			ll tmp = d / cha;
			if (tmp * 2 <= n) cout << n - tmp * 2 + 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}
void solveB() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	if (n <= 2) cout << 0 << '\n';
	else {
		ll mid;
		for (int i = 2; i < n; i ++) if (x[i] - x[1] <= d && x[n] - x[i] <= d) {mid = i;break;}
		ll r = mid;
		while (r + 1 <= n && x[r + 1] - x[mid - 1] <= d) r ++;
		ll R = mid;
		if (mid - 2 >= 1) while (R + 1 <= n && x[R + 1] - x[mid - 2] <= d) R ++;
		ll L = mid;
		while (L >= 1 && x[mid + 1] - x[L] <= d) L --;
		ans = L * (r - R);
		ll l = mid;
		while (l - 1 >= 1 && x[mid + 1] - x[l - 1] <= d) l --;
		L = mid;
		if (mid + 2 <= n) while (L - 1 >= 1 && x[mid + 2] - x[L - 1] <= d) L --;
		R = mid;
		while (R <= n && x[R] - x[mid - 1] <= d) R ++;
		ans += (n - R + 1) * (L - l);
		cout << ans << '\n';
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> T;
	while (T --) {
		if (C == 11 || C == 12) solveA();
		else if (C == 13 || C == 14) solveB();
		else solve();
	}
	return 0;
}
