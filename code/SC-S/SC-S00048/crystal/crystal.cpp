#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m ;
	cin >> n >> m ;
	long long c[n];
	for(long long  i = 0 ; i < n ; i++){
		cin >> c[i];
	}
	sort(c , c + n);
	long long d = 0 ;
	while(m--){
		c[0]++ ;
		sort(c , c + n) ; 
		for(long long i = 0 ; i < n ; i++){
			long long f = c[i];
			long long e = 0 ;
			for(long long j = 0 ; j < n ;j++){
				if(f == c[j]){
					e++;
				}
			}
			if(e > d){ 
				d = e ;
			}
		}
	}
	cout << d ;		
	return 0;
}
