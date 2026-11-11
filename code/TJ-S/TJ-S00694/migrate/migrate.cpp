#include <cstdio>

const int N = 2e6+5;
int c, t, n;
long long d, xx[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while(t --)
	{
		scanf("%d%lld", &n, &d);
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", xx[i]);
		}
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
		long long num = xx[2]-xx[1];
		long long ans = 0;
		for(int i=1; i<n; i++)
		{
			long long l = xx[1], r = xx[i+1];
			long long c = (r-l)%d;
			if(r-l > d && c != 0 && (i+1-c/num)-(1+c/num)+1 == 2)
			{
				ans += n-i;
			}
		}
		printf("%lld", ans);
	}
	
	return 0;
}
