#include<bits/stdc++.h>
using namespace std ;
long long n , m , a[200005] , maxx , sum ,maxa , len , ans , K[32] , FB = 1 ;
int fl(long long x) {
	int p = 0 ;
	while(x) {
		x =(x >> 1) ;
		p ++ ;
	}
	return p ;
}
int FA() {
	int T = 1 ;
	for(int i = 1 ; i <= n ; i ++) {
		int P = 0 ;
		for(int j = 0 ; j <= 30 ; j ++) {
			if(a[i] = K[j] - 1) {
				P = 1 ;
				break;
			}
		}
		if(P == 0) {
			T = 0 ;
			break ;
		}
	}
	return T ;
	
}
int KKK(long long x) {
	for(int i = 0 ; i <= 30 ; i ++) {
		if(x == K[i]) return 1 ;
		if(x < K[i]) return 0 ;
	}
}
int main() {
	freopen("and.in","r" , stdin) ;
	freopen("and.out","w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> m ;
	K[0] = 1 ;
	for(int i = 1 ; i <= 30 ; i ++) {
		K[i] = K[i - 1] * 2 ;
	} 
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
		if(a[i] != i - 1) FB = 0 ;
		maxa = max(maxa , a[i]);
	}
	if(m == 1) {
		cout << maxa ;
		return 0 ;
	} if(m == n) {
		ans = a[1] ;
		for(int i = 2 ; i <= n ; i ++) {
			ans = ans & a[i] ; 
		}
		cout << ans ;
		return 0 ;
	}
	if(m == 2 && n <= 2000) {
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = i + 1 ; j <= n ; j ++) {
				maxx = max(maxx , a[i] & a[j]) ;
			}
		}
		cout << maxx ;
		return 0 ;
	}
	len = fl(maxa) + 1;
	for(long long i = 0 ; i < (1 << len) ; i ++) {
		sum = 0 ;
		for(int j = 1 ; j <= n ; j ++) {
			int T = 1 ;
			for(int l = 0 ; l < len ; l ++) {
				if(((a[j] >> l) & 1 )< ((i >> l) & 1)) {
					T = 0 ;
					break;
				}
			}
			if(T) {
				sum ++ ;
			}
		}
		if(sum >= m) {
			maxx = i ;
		}
	}
	cout << maxx ;
	return 0 ;
}
