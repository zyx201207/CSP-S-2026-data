#define MAXN 500005
#include <bits\stdc++.h>
using namespace std ;

long long n , m , maxx= 1,ans[MAXN];
long long a[MAXN] ;
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	scanf("%lld%lld",&n,&m) ;
	for(int i = 1 ; i <= n ; i ++ ) {
		scanf("%lld",&a[i]) ;
	}
	sort(a+1,a+1+n) ;
	ans[1] = 1 ;
	for(int i = 2 ; i <= n ; i ++ ) {
		if(a[i-1] == a[i]){
			ans[i]=ans[i-1]+1 ;
			maxx = max(maxx,ans[i]) ;
			continue ;
		}
		long long cnt = m ;
		ans[i] = 1 ;
		for(int j = i-1 ; cnt-(a[i]-a[j]) >= 0 && j >= 1 ; j -- ){
			cnt -= (a[i]-a[j]) ;
			ans[i] ++ ;
		}
		maxx = max(maxx,ans[i]) ;
	}
	printf("%lld",maxx) ;
	return 0 ;
}
