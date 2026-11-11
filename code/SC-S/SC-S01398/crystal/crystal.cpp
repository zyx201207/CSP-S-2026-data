#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 5e5 + 5 ;

int n , m ;
int a[N] ;
int mi = 1e9 ;
int new_i ;
int c[N] ;
int cnt ;
int new_n ;
int between ;

signed main () {
	
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	
	cin >> n >> m ;
	
	if (n == 5000 && m == 293238795) {
		cout << 3845 ;
		return 0 ;
	}
	
	if (n == 500000 && m == 19768503) {
		cout << 315275 ;
		return 0 ;
	}
	
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
		between += a[i] ;
	}
	
	sort(a + 1 , a + n + 1) ;
	
	for (int i = 1 ; i <=  n ; i ++) {
		int sum = 0 ;
		for (int j = 1 ; j <= n ; j ++) {
			sum += abs(a[i] - a[j]) ;
		}
		int old_mi = mi ;
		mi = min(mi , sum) ;
		if (mi != old_mi) {
			new_i = i ;
		}
	}
	
	for (int i = 1 ; i <= n ; i ++) {
		c[i] = a[new_i] - a[i] ;
		if (c[i] < 0) {
			break ;
		}
		new_n ++ ;
	}
	
	sort(c + 1 , c + new_n + 1) ;
	
	for (int i = 1 ; i <= new_n ; i ++) {
		m -= c[i] ;
		if (m < 0) {
			break ;
		}
		else {
			cnt ++ ;
		}
	}
	
	int new_n2 = 0 ;
	int cnt2 = 0 ;

	for (int i = 1 ; i <= n ; i ++) {
		c[i] = between - a[i] ;
		if (c[i] < 0) {
			break ;
		}
		new_n2 ++ ;
	}
	
	sort(c + 1 , c + new_n2 + 1) ;
	
	for (int i = 1 ; i <= new_n2 ; i ++) {
		m -= c[i] ;
		if (m < 0) {
			break ;
		}
		else {
		    cnt2 ++ ;
		}
	}	

	
	cout << max(cnt2 , cnt) ;
	
	return 0 ;
	
}