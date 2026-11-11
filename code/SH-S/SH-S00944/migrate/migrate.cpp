#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d;
long long x[2000010];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	while(t --)
	{
		scanf("%d %lld", &n, &d);
		for(int i = 1;i <= n;i ++)
			scanf("%lld", &x[i]);
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
		if(x[n] - x[1] <= d)
		{
			printf("0\n");
			continue;
		}
		
		bool fg = 0;
		//sub b : n <= 2 * d + 1
		for(int i = 1;i <= n;i ++)//sub B
		{
			if(x[i] - x[1] <= d && x[n] - x[i] <= d)
			{
				fg = 1;
				break;				
			}
		}
		
		if(fg)
		{
			if(n != 2 * d + 1)
				printf("%lld\n", (n - d) * (n - d - 1) / 2);
			else
				printf("%lld\n", (n - d) * (n - d - 1) / 2 - 1);
			continue;		
		}
		printf("1\n");
	}
	return 0;
}
