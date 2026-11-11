#include <bits/stdc++.h>
#define int long long

using namespace std ;

inline int read()
{
	int x = 0 , f = 1 ; char ch = 0 ;
	while(!isdigit(ch)){if(ch == '-') f = -1 ; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

const int N = 5e5 + 10 ;

int a[N] , ans , n , m , q[N] , hh , tt , s[N] ;

signed main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	n = read() , m = read() ;
	for(int i = 1 ; i <= n ; i ++ ) a[i] = read() ;
	sort(a + 1 , a + 1 + n) ;
	for(int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + a[i] ;
	hh = 1 , tt = 0 ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		while(hh <= tt && (s[i] - s[q[hh] - 1] + m) < (i - q[hh] + 1) * a[i]) hh ++ ;
		q[++tt] = i ;
		ans = max(ans , i - q[hh] + 1) ;
	}
	printf("%lld\n" , ans) ;
	return 0 ;
}
