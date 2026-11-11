#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
#define lowbit(x) x&(-x)

const int N = 5e5 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, m, a[N];
int pre[N], ans = 0;

inline int calc (int l, int r) {
	int len = r - l + 1;
	return len * a[r] - (pre[r] - pre[l - 1]);
}

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		pre[i] = pre[i - 1] + a[i];
	int l = n;
	for (int i = n; i >= 1; i--) {
		while(l >= 1 && calc(l, i) <= m) l--;
		ans = max(ans, i - l);
	}
	cout << ans;
}

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; // cin >> T;
	while(T--) solve();
	return 0;
}