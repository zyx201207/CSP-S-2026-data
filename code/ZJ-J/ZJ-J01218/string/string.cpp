#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long

int n, a[200005], ans = 0, ps[200005], sf[200005];
char c[200005];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1;i <= n;i++){
		std::cin >> a[i] >> c[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for(int i = n;i >= 1;i--)
		sf[i] = sf[i + 1] + a[i];
	int l = 1, r = ps[n], lid = 1, rid = n;
	while(l < r and lid != rid){
		int jud = (ps[lid] - l + 1 == r - ps[rid - 1]);
		if(ps[lid] - l + 1 < r - ps[rid - 1]){
			r -= ps[lid] + 1 - l;
			if(c[lid] != c[rid])
				ans += ps[lid] + 1 - l;
			l = ps[lid] + 1;
			lid++;
		}
		else{
			l += r - ps[rid - 1];
//			printf("%lld %lld %lld\n", r, rid, r - ps[rid - 1]);
			if(c[lid] != c[rid])
				ans += r - ps[rid - 1];
			r = ps[rid - 1];
			rid--;
		}
//		printf("%lld %lld\n", l, r);
		lid += jud;
//		printf("%lld\n", ans);
	}
	printf("%lld", ans);
	return 0;
}