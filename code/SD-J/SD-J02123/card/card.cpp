#include<bits/stdc++.h>
using namespace std ;
int a[500005] ;
int sum[300005] ;
int b[300005] ;
int w[300005] ;
int main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int n , m ;
	scanf("%d%d" , &n , &m) ;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]) ;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int p = 1 ; p <= m ; p++){
			b[p] = 0 ;
			w[p] = 0 ;
		}
		for(int j = i ; j <= n ; j++){
			if(b[a[j]] == 0){
				b[a[j]]++ ;
				sum[a[j]]++ ;
				w[a[j]] = j ; 
			}else{
				for(int k = w[a[j]]+1 ; k < j ; k++){
					if(b[a[k]] != 0){
						sum[a[k]]-- ;
					}
					b[a[k]] = 0 ;
				}
				w[a[j]] = j ;
			}
		}
	}
	for(int i = 1 ; i <= m ; i++){
		printf("%d " , sum[i]) ;
	}
	return 0 ;
}

