#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int n, m, a[N], cnt[N], ans, sum[N];
bool ck(int l, int r) {
	if((r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m) return 1;
	return 0;
}
signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i], cnt[a[i]] ++;
	
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	
	ans = cnt[a[1]];
	
	for(int i = 2; i <= n; i ++) {
		int l = 1, r = i;
		while(l <= r) {
			int mid = l + r >> 1;
			if(ck(mid, i)) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, i - l + 1);
//		cout << "##" << l << ' ' << i << "\n";
	}
	
	cout << ans;
	return 0;
} 
