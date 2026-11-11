#include <bits/stdc++.h>

#define N 500010
typedef long long LL ;
using namespace std ;

LL n , a[N] , m , ans = 0 , sum[N] ;

inline bool check(int mid , int inow) {    //求mid到inow这段区间（包含两端） 所有点要加多少次 
	LL len = inow-mid+1 ;
	LL res = a[inow]*(len-1)-(sum[inow-1]-sum[mid-1]) ;    //其实就是ainow-amid+ainow-a(mid+1)... 就等于ainow*(ainow-amid)-(sum(ainow-1)-sum(mid-1)) 
	return res <= m ;
}

int main() {
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	cin >> n >> m ;
	for(LL i = 1 ; i <= n ; ++i) {
		cin >> a[i] ;
	}
	sort(a+1 , a+1+n) ;    //题目可没有保证输入有序哦：） 
	for(LL i = 1 ; i <= n ; ++i) {
		sum[i] = sum[i-1]+a[i] ;
	}
	for(LL i = 1 ; i <= n ; ++i) {
		LL l = 1 , r = i ;
		while(l < r) {
			int mid = (l+r)>>1 ;
			if(check(mid , i)) r = mid ;
			else l = mid+1 ;
		}
		ans = max(ans , i-l+1) ;
	}
	cout << ans ;
	return 0 ;
}