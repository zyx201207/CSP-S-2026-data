#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long sum[N], a[N], n, m, maxn;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	 for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
	for(long long i = 1; i <= n; i++) {
		long long l = 1, r = i, ans = i;
		while(l <= r) {
			long long mid = (l+r)/2;
			if(1ll*(sum[i]-sum[mid-1]+m)>= 1ll*(i-mid+1)*a[i]) {
				r = mid-1; ans = mid;
			}
			else l = mid+1;
		}
		maxn = max(maxn, i-ans+1);
	}
	cout << maxn;
	return 0;
} 
