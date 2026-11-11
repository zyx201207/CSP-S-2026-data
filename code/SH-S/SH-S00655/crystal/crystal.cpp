#include <bits/stdc++.h>
using namespace std ;
long long a[510000] , b[510000]={ };
int s1[210] , s2[210] , hk = 0 ;
long long  n , m , mx = -1000000000000000000;
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	cin >> n >> m ;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		if(a[i]==0){
			hk++ ;
		}
		mx = max(a[i],mx) ;
	}
	if(mx>100||n<=5000){
		sort(a+1,a+n+1) ;
	}
	else{
		for(long long i = 1 ; i <= n ; i++){
			if(a[i]<=0){
				s1[abs(a[i]-0)]++ ;
			}
			else{
				s2[a[i]]++ ;
			}
		}
		int cnt = 0 ;	
		for(long long i = 100 ; i >= 1; i--){
			for(int j = 1 ; j <= s1[i] ; j++){
				cnt++ ;
				a[cnt] = 0-i ;
			}
		}
		for(long long i = 1 ; i <= hk ; i++ ){
			cnt++ ;
			a[cnt] = 0 ;
		}
		for(long long i = 1 ;i <= 100 ; i++){
			for(int j =1 ; j <= s2[i] ; j++){
				cnt++ ;
				a[cnt] = i ;
			}
		}
	}
	b[1] = 0 ;
	for(int i  =2 ; i <= n ; i++){
		b[i] = a[i]-a[i-1] ;
	}
	long long ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(i+ans>=n){
			break ;
		}
		long long sum = b[i] ;
		for(int j = i+1 ; j <= n+1 ; j++){
			sum += (j-i)*b[j] ;
			if(sum<=m){
				if(j-i+1>ans){
					ans= min((int)n,j-i+1) ;
				}
			}
			if(i+ans>n){
				break ;
			}
		}
		if(i+ans>n){
			break ;
		}
	}
	cout << ans << endl ;
	return 0 ;
}
