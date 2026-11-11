#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, f;
int a[2000010], w[2000010];

int main()
{
 	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d, %d", &c, &t);
	while(t--)
	{
		f=0;
		scanf("%d %d", &n, &d);
		if(n<4)
		{
			printf("%d\n", 0);
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = n; i > 4; i--)
		{
			for (int k = 0; k <= i-4; k++)
			{
				memset(w, 0, sizeof(w));
				for (int j = i; j >= i-4-k; j--)
				{
					if(a[i]-a[j]<=d)
						w[j]++;
				}
				if(w[i]==2)
				{
					f++;
				}
			}
		}
		printf("%d\n", f);
	}
	return 0;
}
