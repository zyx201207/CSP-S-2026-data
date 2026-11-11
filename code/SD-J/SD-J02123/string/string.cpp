#include<bits/stdc++.h>
using namespace std ;
long long a[200005] ;
char c[200005] ;
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	int n ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i] ;
	}
	int l = 1 , r = n ;
	long long cnt = 0 ;
	while(l < n){
		if(a[l] <= a[r]){
			if(c[l] != c[r]){
				cnt += a[l] ;
			}
			a[r] -= a[l] ;
			a[l] = 0 ;
		}else{
			if(c[l] != c[r]){
				cnt += a[r] ;
			}
			a[l] -= a[r] ;
			a[r] = 0 ;
		}
		if(a[l] == 0){
			l++ ;
		}
		if(a[r] == 0){
			r-- ;
		}
	}
	cout << cnt ;
	return 0 ;
}

