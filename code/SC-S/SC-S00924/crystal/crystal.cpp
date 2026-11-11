#include <bits/stdc++.h> 
using namespace std;
int n,m;
long long a[500005]={0} ;
int main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out", "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]) ;
	}
	sort(a+1,a+n+1) ;
	int ans = 0;
	for(int i = 2 ; i <= n ; i++){
		int s = m ;
		int ma = 1 ;
		for(int j = i-1;j >= 1; j--){
			if(s > 0){
				int c = a[i]-a[j] ;
				if(s >= c){
					s-=c;
					ma++ ;
				}
				else{
					continue ;
				}
			}
		}
		ans = max(ma,ans);
	}
	cout << ans ;
}