#include <bits/stdc++.h>
#define int long long
using namespace std ;
int a[500005] , b[500005] , c[500005] ;
int n , m , ans , cnt ;
map<int , int> mp ;
signed main() {
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	std :: ios :: sync_with_stdio(0);cin.tie(0);
	cin >> n >> m ;
	int maxn = 0 ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
		maxn = std :: max(maxn , abs(a[i])) ;
	}
	if (n <= 5000) {
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				c[j] = a[i] - a[j] ;
			}
			ans = 0 ;
			std :: sort(c + 1 , c + n + 1) ;
			int mm = m ;
			for (int l = 1 ; l <= n ; l++) {
				if (c[l] >= 0) {
					if (mm >= c[l]) {
						mm -= c[l] ;
						ans++ ;
					}
				}
			}
			cnt = max(cnt , ans) ;
		}
		cout << cnt ;
		return 0 ;
	}
	std :: sort(a + 1 , a + n + 1) ;
	b[1] = 0 ;
	int ans = 0 ;
	for (int i = 2 ; i <= n ; i++) {
		b[i] = b[i - 1] + (i - 1) * abs(a[i] - a[i - 1]) ;
		if (b[i] <= m) {
			ans = max(ans , i) ;
		}
	}
	cout << ans ;
	return 0 ;
}
