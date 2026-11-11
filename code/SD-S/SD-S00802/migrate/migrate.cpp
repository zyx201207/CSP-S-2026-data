#include <bits/stdc++.h>

using namespace std;

int c, t, n;
long long d;
long long x[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while (t > 0)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
		}
		
		if (c == 11 || c == 12 || c == 0)
		{
			long long l = x[2] - x[1];
			int s = 0;
			if (d < 2 * l)
			{
				printf("%d\n", 0);
			}
			else
			{
				int z = 0, yl = l;
				while (l <= d)
				{
					z++;
					l += yl;
				}
				d = z;
				int s = 0;
				for (int i = 1; i <= n - 3; i++)
				{
					if (i + d + d - 1 <= n) s++; 
				}
				printf("%d\n", s);
			} 
		}
		t--;
	}
		
	return 0;
} 
