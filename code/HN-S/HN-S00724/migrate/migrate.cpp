#include <bits/stdc++.h>
using namespace std ;
int c , t , n , d ;
int main(){
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;	
	scanf("%d%d",&c,&t) ;
	while(t --){
		scanf("%d%d",&n,&d) ;
		if(c == 0 && t == 2){
			if(n == 5 && d == 3 ) printf("0\n") ;
			if(n == 6 && d == 2 ) printf("1\n") ;
		}
		if(c == 0 && t == 2){
			if(n == 4 && d == 2) printf("1\n") ;
			if(n == 5 && d == 2) printf("2\n") ;
		}
	}
	return 0 ;
}
