#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
bool check(long long x){
	long long nw = 0, ld = 0, ret = 1e18;
	for(int i = 1;i <= x;i++){
		ld += a[x] - a[i];
	}
	ret = ld;
	for(int i = x + 1;i <= n;i++){
		nw = ld + x * (a[i] - a[i - 1]) - (a[i] - a[i - x]);
		ld = nw;
		ret = min(ret, nw);
	}
	return m >= ret;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long l = 1, r = n, ans = 1;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
} 