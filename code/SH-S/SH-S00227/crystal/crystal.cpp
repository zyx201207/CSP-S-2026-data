#include <bits/stdc++.h>
#define FILE(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define DEBUG(s) freopen(s".err", "w", stderr)
#define CloseFILE fclose(stdin), fclose(stdout)
#define CloseDEBUG fclose(stderr)
#define int long long
#define endl "\n"
using namespace std;

constexpr int MAXN = 5e5+5;
int n, m, r=1, ans=1, pre[MAXN], pmax[MAXN], a[MAXN];

signed main() {
	FILE("crystal"), DEBUG("crystal");
	cin.tie(0) -> sync_with_stdio(0);
	memset(pmax, 128, sizeof(pmax));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
		pmax[i] = max(pmax[i], a[i]);
	}
	for (int l = 1; l <= n; l++) {
		while (r <= n && pmax[r]*(r-l+1)-(pre[r]-pre[l-1]) <= m) r++;  // m 点能量没用完 
		ans = max((r-1)-l+1, ans);
	}
	cout << ans << endl;
//	CloseFILE, CloseDEBUG;
	return 0;
}
