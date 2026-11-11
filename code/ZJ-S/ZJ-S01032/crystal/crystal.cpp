#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n ,m ,ns[N] ,s[N];

int main() {
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	scanf("%lld %lld" ,&n ,&m);	
	for (int i=1 ;i<=n ;i++) {
		scanf("%lld" ,&ns[i]);	
	}
	
	sort(ns+1 ,ns+1+n);
	for (int i=1 ;i<=n ;i++) {
		s[i] = s[i-1] + ns[i];
	}
	
	ll ans = 0;
	for (int tag=1 ;tag<=n ;tag++) {
		ll l = 1 ,r = tag ,mid ,thi_a = 0;
		for (;l <= r;) {
			mid = (l + r) >> 1;
			ll c = ns[tag] * (tag - mid + 1) - s[tag] + s[mid-1];
			if (c <= m) {
				r = mid - 1;
				thi_a = max(thi_a ,tag - mid + 1);
			}
			else {
				l = mid + 1;
			}
		}
		ans = max(ans ,thi_a);
	}
	
	printf("%lld" ,ans);
	
	
	return 0;
}