#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 5e5 + 5;
ll a[M], pre[M], m;
int n;
bool chk(int l, int r) {
	ll len = r - l + 1, sum = pre[r] - pre[l - 1];
	if(a[r] * len - sum <= m) return true;
	else return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i, res = 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(chk(mid, i)) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
// DanseSolo 姐姐可爱喵