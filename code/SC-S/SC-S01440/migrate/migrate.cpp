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

const int N = 2e6 + 10 ;

int a[N] , n , d , s[N],  p[N] , sum[N] , s1[N] , p1[N] , dis[5010][5010] , res[5010][5010] ;

inline void solve()
{
	n = read() , d = read() ;
	queue<int> q ;
	for(int i = 1 ; i <= n ; i ++ ) a[i] = read() ;
	for(int i = 0 ; i <= n + 1 ; i ++ ) s1[i] = p1[i] = 0 ;
	int now = 1 ;
	for(int i = 1 ; i <= n ; i ++ ) 
	{
		while(a[i] - a[now] > d) now ++ ;
		p[i] = i - now + 1 ;
	}
	now = n ;
	for(int i = n ; i >= 1 ; i -- )
	{
		while(a[now] - a[i] > d) now -- ;
		s[i] = now - i + 1 ;
	}
	for(int i = 1 ; i <= n ; i ++ ) for(int j = 1 ; j <= n ; j ++ ) dis[i][j] = 1e18 , res[i][j] = 0 ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		for(int j = i - p[i] + 1 ; j < i ; j ++ ) dis[j][i] = res[j][i] = dis[i][j] = res[i][j] = 1 ;
		for(int j = i + s[i] - 1 ; j > i ; j -- ) dis[i][j] = res[i][j] = dis[j][i] = res[j][i] = 1 ;
		dis[i][i] = 1 ;
	}
//	for(int i = 1 ; i <= n ; i ++ ) 
//	{
//		for(int j = 1 ; j <= n ; j ++ ) cout << dis[i][j] << " " ; cout << endl ;
//	}
	for(int i = 1 ; i <= n ; i ++ )
	{
		for(int j = i + 1 ; j <= n ; j ++ )
		{
			for(int k = 1 ; k <= n ; k ++ )
			{
				if(k <= i || k >= j) continue ;
				int ress = dis[i][k] + dis[k][j] ;
				if(ress == dis[i][j]) res[i][j] += res[i][k] * res[k][j] ;
				else if(ress < dis[i][j]) dis[i][j] = ress , res[i][j] = res[i][k] * res[k][j] ;
				res[i][j] = min(res[i][j] , 3ll) ;
				dis[j][i] = dis[i][j] , res[j][i] = res[i][j] ;
			}
		}
	}
	int ans = 0 ;
//	cout << res[1][4] << endl ;
	for(int i = 1 ; i <= n ; i ++ ) for(int j = i + 1 ; j <= n ; j ++ ) if(res[i][j] == 2) ans ++ ;
	printf("%lld\n" , ans) ;
//	if(s[1] == 2) p1[2] = 1 ;
//	for(int i = 2 ; i <= n ; i ++ )
//	{
//		if(p[i] == 2 && s[i - 1] == 2) p1[i] = p1[i - 1] + 1 ;
//		else p1[i] = 0 ;
//	}
////	if(p[n] == 2) s1[n - 1] = 1 ;
//	for(int i = n - 1 ; i >= 1 ; i -- )
//	{
//		if(s[i] == 2 && p[i + 1] == 2) s1[i] = s1[i + 1] + 1 ;
//		else s1[i] = 0 ;
//	}
//	int ans = 0 ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << p[i] << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << s[i] << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << p1[i] << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << s1[i] << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << s[i] + i << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ ) cout << i - p[i] + 3 << " " ; cout << endl ;
//	for(int i = 1 ; i <= n ; i ++ )
//	{
//		ans += sum[i - p[i] + 3] * (s1[i] + 1) ;
////		if(sum[i - p[i] + 3] ) cout << i << endl ;
//		if(i > 1) q.push(s[i - 1] + i - 1) ;
//		if(i > 1) sum[s[i - 1] + i - 1] += p1[i - 1] + 1 ;
//	}
//	printf("%lld\n" , ans) ;
//	while(!q.empty())
//	{
//		int t = q.front() ; q.pop() ;
//		sum[t] = 0 ;
//	}
}

signed main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	int c = read() , T = read() ;
	while(T -- ) solve() ;
	return 0 ;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/