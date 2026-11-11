#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 720231
using namespace std;
const int INF = 2e18;
const int mod = 998244353;

int n, m, a[N], s[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 1, ans = 0;
	for(int r = 1; r <= n; r++){
		while(l < r && m < a[r] * (r - l + 1) - (s[r] - s[l - 1]))
			l++;
		// cout << l << ' ' << r << ' ' << a[r] * (r - l + 1) - (s[r] - s[l - 1]) << '\n';
		if(m >= a[r] * (r - l + 1) - (s[r] - s[l - 1]))
			ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--)
		solve();
	return 0;
}

// szh_ak_all is on the left side, in front of me,  orz
// and where is rongrong?
// he cannot get my identity haha
// pls dont show my test-id (duckly)
