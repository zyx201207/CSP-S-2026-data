#include <bits/stdc++.h>
#define int long long
#define ll long long
#define i128 __int128
#define pb push_back
#define pq priority_queue
#define pii pair<int,int>
#define fi first
#define se second
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;
const int N = 5e5+5;
int a[N];

void solve() {
	int n, m, sum = 0, l = 1, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		while (sum > m)
			sum -= a[i] - a[l], l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
}

signed main() {
	File("crystal");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	signed T = 1;
	// cin>>T;
	while (T--)
		solve();
	return 0;
}