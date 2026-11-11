#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[514514], diff[514514], pre[514514], l, r, mid, ans = 1;
bool check(int x){
	for(int i = x; i <= n; i++){
		if(pre[i] - pre[i - x] - x * diff[i] <= m){
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		diff[i] = a[n] - a[i];
	}
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + diff[i];
	}
	l = 1;
	r = n;
	while(l < r){
		mid = ((l + r) >> 1);
		if(check(mid)){
			ans = max(ans, mid);
			l = mid + 1;
		} else{
			r = mid - 1;
		}
	}
	if(check(r)) ans = max(ans, r);
	printf("%lld", ans);
	return 0;
}
