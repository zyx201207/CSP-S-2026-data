#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , p , k ;
int w[500005] , x[15] , y[15] , a[500005] , t[500005] ;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p ;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i] ;
	}
	cin >> k ;
	for(int i = 1 ; i <= k ; i++){
		cin >> a[i] >> t[i] ;
	}
	for(int i = 1 ; i <= p ; i++){
		cin >> x[i] >> y[i] ;
		cout << w[x[i]] + t[x[i]] + t[y[i]] + w[y[i]] << '\n' ;
	}
	return 0;
}