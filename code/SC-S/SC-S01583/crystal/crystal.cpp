#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, a[5000111], sum[500111], rem[500011];
signed main() {
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	rem[0] = 1;
	for (int r = 1; r <= n; r++) {
		int tr = r,tl = rem[r - 1];
		int mid = 0;
		if(a[r] * (r - 1) - sum[r - 1] <= m) {
			ans = max(ans,r);
			rem[r] = 1;
			continue;
		}
		while(tl < tr) {
			mid = (tl + tr) / 2;
			int need = a[r] * (r - mid - 1) - sum[r - 1] + sum[mid - 1];
			if(need <= m) {
				tl = mid + 1;
			}else {
				tr = mid;
			}
		}
//		cout << mid << " " << r << endl;
		rem[r] = mid;
		ans = max(ans,r -  mid + 1);
	}
	cout << ans;
	return 0;
}