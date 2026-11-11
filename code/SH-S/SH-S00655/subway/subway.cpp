#include <bits/stdc++.h>
using namespace std ;
int w[410000] , a[1000][1000],t[2100],s[2100] ;
int main(){
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	int c , n , m ,  d , q ;
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i] ;
	}
	for(int i = 1 ; i <= m ; i++){
		cin >> t[i] ;
		for(int j =1 ; j <= t[i]*2 ;j++){
			cin >> a[i][j] ;
			s[i]+=a[i][j] ;
		}
	}
	for(int i = 1 ; i <= q ; i++){
		int x , y ;
		cin >> x >> y ;
	}
	return 0 ;
}
