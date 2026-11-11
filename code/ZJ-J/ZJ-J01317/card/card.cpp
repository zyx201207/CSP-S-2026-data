#include<bits/stdc++.h>
using namespace std ;
long long n , m , a[500005] , f[2005][2005] , l[300006] , ans[300006] , w[300006];
int main() {
	freopen("card.in","r" , stdin) ;
	freopen("card.out","w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
		for(int j = 1 ; j <= m ; j ++) {
			f[i][j] = f[i - 1][j] ;
		}
		f[i][a[i]] ++ ;
	}
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = 1 ; j <= m ; j ++) {
			l[j] = 0 ;
		}
		for(int j = i ; j <= n ; j ++) {
			if(l[a[j]] == 1) {
				for(int r = 1 ; r <= m ; r ++) {
					if(w[r] >= w[a[j]] ) {
						l[r] = 0 ;
					}
				}
			}
			l[a[j]] ++ ;
			w[a[j]] = j ;
		}
		for(int j = 1 ; j <= m ; j ++) {
			if(l[j] == 1) {
				ans[j] ++ ;
			}
		}
	}
	for(int i = 1 ; i <= m ; i ++) {
		cout << ans[i] << ' ' ;
	}
	return 0 ;
}
