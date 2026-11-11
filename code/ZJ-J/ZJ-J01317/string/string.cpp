#include<bits/stdc++.h>
using namespace std ;
string s ;
char c[200005] ;
long long n ,len , a[200005] , ans ;
struct ss {
	long long l , r;
	char w ;
}k[200005]; 
int main() {
	freopen("string.in","r" , stdin) ;
	freopen("string.out","w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i] >> c[i] ;
		len += a[i] ;
		k[i].l = k[i - 1].r + 1 ;
		k[i].r = k[i].l + a[i] - 1 ;
		k[i].w = c[i] ;
	}
	long long q = 1 , h = n , m = 1 ;
	while(q != h || q > h) {
		if(k[q].w != k[h].w ) {
			ans = ans + min(k[q].r - m + 1, len - m + 1 - k[h].l + 1) ;
		}
		if(k[q].r - m + 1 < len - m + 1 - k[h].l + 1) {
			m = m + k[q].r - m + 1 ;
			q ++ ;
		} else if(k[q].r - m + 1 > len - m + 1 - k[h].l + 1) {
			m = m + (len - m + 1 - k[h].l + 1) ;
			h -- ;
		} else {
			m = m + k[q].r - m + 1 ;
			q ++ ;
			h -- ;
		}
	}
	cout << ans ;
	return 0 ;
}
