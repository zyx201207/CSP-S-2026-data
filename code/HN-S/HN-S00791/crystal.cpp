#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
ll a[500005];
ll sum[500005];
int check(int k) {
	for(int i = k;i <= n;++i)
		if(a[i] * k - sum[i] + sum[i - k] <= m) return 1;
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
	int l = 1,r = n;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
