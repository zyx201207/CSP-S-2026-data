#include <bits/stdc++.h>
#define MAXN int(5e5)

long long n, m, d ; //d表示增量，但是这个想法暂时废弃  
int p ;//指向与下一个元素差距最小的... 
long long maxi = -1, mini = 2147483647 ;
long long a[MAXN + 3] ;
//int cnt[1000003] ;
int ans = 1 ;
void print()
{
	printf("a[] = [") ;
	for (int i = 1; i <= n; i++)
	{
		printf("%d, ", a[i]) ;
	}
	printf("\b\b] ") ;
	return ;
}
//void dfs(int s)
//{
//	if (s > m)
//	{
////		print() ;
//		memset(cnt, 0, sizeof cnt) ;
//		for (int i = 1; i <= n; i++)
//		{
//			cnt[a[i]]++ ;
//		}
//		ans = std::max(ans, *std::max_element(cnt + 1, cnt + maxi + 1)) ;
//		return ;
//	}
//	dfs(s + 1) ;
//	for (int i = 1; i <= n; i++)
//	{
//		a[i]++ ;
//		dfs(s + 1) ;
//		a[i]-- ;
//	}
//	return ;
//}
//long long cost(int x)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i] > )
//	}
//}
//void solve2() //二分枚举最终相同的值
//{
//	long long l, r, mid ;
//	l = mini, r = maxi ;
//	while (l < r)
//	{
//		return ;
//	}
//	return ;
//} 
void solve() //滑动窗口 
{
	int l, r ;
	int u = 0 ;
	l = 1, r = 1 ;
	while (true)
	{
		if (r == n)
		{
			break ;
		}
		if (u + (r - l + 1) * (a[r + 1] - a[r]) <= m)
		{
			u += (r - l + 1) * (a[r + 1] - a[r]) ;
			r++ ;
		}
		else
		{
			l++ ;
			u -= a[r] - a[l] ;
		}
		ans = std::max(r - l + 1, ans) ;
	}
	return ;
}
int main()
{
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	scanf("%lld %lld", &n, &m) ;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]) ;
		maxi = std::max(maxi, a[i]) ;
		mini = std::min(mini, a[i]) ;
//		if (a[i] == a[i - 1])
//		{
//			i--, n-- ;
//			d++ ;
//		}
		
	}
	std::sort(a + 1, a + n + 1) ;
//	dfs(1) ;
	solve() ;
	printf("%d", ans/* + d*/) ;
	return 0 ;
}
