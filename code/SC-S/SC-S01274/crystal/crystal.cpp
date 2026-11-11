#include <bits/stdc++.h>

using namespace std ;

#define i64 long long

i64 read () {
	i64 res = 0 , f = 1 ;
	char ch = getchar() ;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1 ;
		ch = getchar() ;
	}
	while (ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48) ;
		ch = getchar() ;
	}
	return res * f ;
}
int n ;
i64 m , a[500005] , s[500005] ;
int main () {
	freopen ("crystal.in" , "r" , stdin) ;
	freopen ("crystal.out" , "w" , stdout) ;
	n = read() ;
	m = read() ;
	for (int i = 1 ; i <= n ; i++) {
		a[i] = read() ;
	}
	sort (a + 1 , a + 1 + n) ;
	for (int i = 1 ; i <= n ; i++) {
		s[i] = s[i - 1] + a[i] ;
	}
	i64 ans = 1 ;
	for (int i = 1 ; i <= n ; i++) {
		int l = 1 , r = i ;
		i64 res = i ;
		while (l <= r) {
			int mid = (l + r) / 2 ;
			i64 len = i - mid + 1 ;
			if (len * a[i] - (s[i] - s[mid - 1]) <= m) {
				res = mid , r = mid - 1 ;
			} else l = mid + 1 ;
		}
		ans = max (ans , i - res + 1) ;
	}
	printf ("%lld\n" , ans) ;
	return 0 ;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/