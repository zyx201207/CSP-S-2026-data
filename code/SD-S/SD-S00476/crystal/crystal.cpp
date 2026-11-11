#include <bits/stdc++.h>
#define ll long long
int n ;
ll  m;
ll a[500100];
ll pre[500100];
signed main(){
	freopen("crystal.in" , "r", stdin);
	freopen("crystal.out" , "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lld", &a[i]);
	}
	std::sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; ++ i){
		pre[i] = pre[i - 1] + a[i];
	}
	ll s=0;
	int l=1;
	ll as = 0ll;
	for(int r = 1 ; r <= n ; ++ r){
		while(1ll * (r - l + 1) * a[r] - (pre[r] - pre[l - 1]) > m){
			l++ ;
		}
		as = std::max(as , r - l + 1ll);
	}
	printf("%lld\n",as);
	return 0;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10
*/
