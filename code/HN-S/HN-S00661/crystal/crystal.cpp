#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500100], pre[500100], ans;

bool check(long long mid, int i) {
	return a[i] * (long long)(i - mid + 1) - (pre[i] - pre[mid - 1]) <= m;
} 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i ++) {
		long long l = 1, r = i;
		while(l < r) {
			long long mid = (l + r) / 2;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
