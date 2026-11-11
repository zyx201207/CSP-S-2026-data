#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int c, t;
int n;
long long d;
long long x[N];

//namespace SubA
//{
//	void SolveA()
//	{
//		long long ans, D, bei;
//		
//		while(t --)
//		{
//			scanf("%d%lld", &n, &d);
//			for(int i = 1; i <= n; i ++)
//			{
//				scanf("%lld", &x[i]);
//			}
//			
//			D = x[2] - x[1];
//			bei = d / D;
//			
//			if(bei < 2)
//			{
//				puts("0");
//				continue;
//			}
//			else if(n < bei * 2)
//			{
//				puts("0");
//				continue;
//			}
//			else
//			{
//				ans = (long long)n - 2 * bei + 1;
//				printf("%lld\n", ans);
//			}
//		}
//		
//		return;
//	}
//}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	long long ans, D, bei;
		
		while(t --)
		{
			scanf("%d%lld", &n, &d);
			for(int i = 1; i <= n; i ++)
			{
				scanf("%lld", &x[i]);
			}
			
			D = x[2] - x[1];
			bei = d / D;
			
			if(bei < 2)
			{
				puts("0");
				continue;
			}
			else if(n < bei * 2)
			{
				puts("0");
				continue;
			}
			else
			{
				ans = (long long)n - 2 * bei + 1;
				printf("%lld\n", ans);
			}
		}
	
	return 0;
}