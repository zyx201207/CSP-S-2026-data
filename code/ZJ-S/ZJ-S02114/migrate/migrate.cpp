#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 10;
int n, d;
int a[N];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i ++)
			scanf("%lld", &a[i]);
		bool checkA = true;
		int x = a[2] - a[1];
		for(int i = 2; i <= n; i ++)
			if(a[i] - a[i - 1] != x) 
				checkA = false;
				
		sort(a + 1, a + 1 + n);
		if(checkA)
		{
			if(d < x || a[n] - a[1] + 1 < 2 * d) 
			{
				puts("0");
				continue;
			}
			else if(d >= x && d < 2 * x)
				puts("0");
			for(int i = 2; ; i ++)
			{
				if(d < i * x) break;
				if(d >= i * x && d < (i + 1) * x)
				{
					if(n - i - 1 < 0) puts("0");
					else printf("%lld\n", n - i - 1);
					break;
				}
			}
		}
		else puts("1");
	}
	return 0;
}
