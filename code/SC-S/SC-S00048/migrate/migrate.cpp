#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	long long c , t ;
	cin >> c >> t ;
	while(t--){
		long long n , d ;
		cin >> n >> d;
		long long a[n] ;
		for(long long i = 0 ; i < n ; i++){
			cin >> a[i];				
		}
		long long r = 0 ;
		for(long long i = 0 ; i < n ; i++){
			for(long long j = i + 1 ; j < n ; j++){
				long long b ;
				b = a[j] - a[i] ;
				if((b % d == 0 && b / d > 2) || (b % d == 0 && b / d < 2) || (b % d != 0 && b / d + 1 > 2) || (b % d != 0 && b / d + 1 < 2) || (b % d == 0)){
					continue ;
				}
				if (j - i == 1){
					continue ;
				}
				long long q = 0;
				for(long long e = 1 ; e < b ; e++){
					for(long long f = b - e ; f >= 1 ; f--){
						if (e + f == 4){
							q++;	
						}
					}
				}
				if(q > 2){
					continue;
				}
				r++;
			}
		}
		cout << r << endl;
	}
	return 0;
}