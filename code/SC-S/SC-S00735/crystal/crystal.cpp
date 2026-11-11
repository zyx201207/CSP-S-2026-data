#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int inf = 1e18;
const int N = 5e5 + 5;

int n, m, a[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 0, sum = 0, ans = 0;
	for( ; r <= n; r++) {
		sum += a[r];
		while(l <= r && a[r] * (r - l + 1) - sum > m) {
			sum -= a[l++];
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
	
}
