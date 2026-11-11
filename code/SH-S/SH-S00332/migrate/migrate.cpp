#include <bits/stdc++.h>
#define int unsigned long long

//分而治之？
/*
MsT
3.14159265358979323846264338327950288
4197169399375105820974944592307816406
286208
*/ 
int c, t, n, d, x, y ;
int a[2000003] ;
int ans ;
signed main()
{
	srand(time(nullptr)) ;
	freopen("migrate3.in", "r", stdin) ;
//	freopen("migrate.out", "w", stdout) ;
	scanf("%lld %lld", &c, &t) ;
//	for (int i = 1; i <= t; i++)
//	{
//		printf("%d\n", rand() % 3) ;
//	}
	while (t--)
	{
		scanf("%lld %lld", &n, &d) ;
		ans = 0 ;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]) ;
		}
		if (n < 4)
		{
			printf("0\n") ;
			continue ;
		}
		a[0] = a[1] ;
		a[n + 1] = a[n] ;
		for (int i = 1; i <= n - 3; i++)
		{
			if (a[i + 3] - a[i] > d)
			{
				if (a[i + 3] - a[i + 2] <= d && a[i + 1] - a[i] <= d)
				{
					if (a[i + 3] - a[i + 1] <= d && a[i + 2] - a[i] <= d)
					{
						x = y = 0 ;
						for (x = 1; x < i; x++)
						{
							if (a[i - x + 1] - a[i - x] > d || a[i] - a[i - x - 1] <= d)
							{
								x-- ;
								break ;
							}
						}
						for (y = 1; y <= n - i - 4; y++)
						{
							if (a[i + 3 + y] - a[i + 3 + y - 1] > d || a[i + 3 + y + 1] - a[i + 3] <= d)
							{
								y-- ;
								break ;
							}
						}
						if (i <= 1) x = 0 ;
						if (n - i - 4 <= 1) y = 0 ;
						ans += (x + 1) * (y + 1) ;
					}
				}
			}
		}
		printf("%lld\n", ans) ;
	}
	return 0 ;
}

