#include <bits/stdc++.h>
using namespace std;
long long c,t,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		long long n,d,q = 0;
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			int a;
			cin >> a;
			if((a - x[j]) <= d)
			{
				x[j] = a;
				q++;
			}
			else
			{
				break;
			}
		}
		int ans = 0;
		for(int w = 1;w < q;w++)
		{
			for(int j = w + 1;j <= q;j++)
			{
				if(((x[j] - x[w]) > d) and ((x[j] - x[w]) < (2 * d)))
				{
					if(((x[j] - x[w]) % 2 == 1) and (d % 2 == 0))
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
