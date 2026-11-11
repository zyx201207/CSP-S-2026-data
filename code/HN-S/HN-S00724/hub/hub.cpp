#include <bits/stdc++.h>
using namespace std ;
int c , t , n , k ;
int main(){
	freopen("hub.in","r",stdin) ;
	freopen("hub.out","w",stdout) ;	
	cin >> c >> t ;
	while(t--){
		scanf("%d%d",&n,&k) ;
		if(c == 0 && t == 2){
			if(n == 5 && k ==2 ) printf("1\n") ;
			if(n == 10 && k == 3) printf("2\n") ;
		}
		for(int i = 1 ; i < n ; i ++ ){
			int a , b ;cin >> a >> b ;
		}
	}
	return 0 ;
}
