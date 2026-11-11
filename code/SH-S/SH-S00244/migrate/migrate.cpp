#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define int long long  

int a[1000010];
int f[1000010];
int cnt[1000010];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%lld%lld", &c, &T);
	while(T--)
	{
		int n, d;
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		memset(f, 0x3f, sizeof f);
		memset(cnt, 0, sizeof cnt);
		f[1] = 0;
		for(int i = 2; a[i] - a[1] <= d; i++)
		{
			f[i] = 1;
		}
		for(int i = d + 1; i <= n; i++)
		{
			for(int j = i - 1; a[i] - a[j] <= d && j > 0; j--)
			{
				if(f[j] + 1 < f[i])
				{
					if(i == 5)	cout << j << endl;
					f[i] = f[j] + 1;
					cnt[i] = 1;
				}
				else if(f[j] + 1 == f[i])
				{
					if(i == 5)	cout << j << "a" << endl;
					cnt[i]++;
				}
			}
		}
		int ans = 0;
		cout << f[2] + 1 << " " << f[3] + 1 << endl;
		for(int i = d + 1; i <= n; i++)
		{
			if(cnt[i] == 2)
			{
//				cout << i << " ";
				ans++;
			}
		}
//		cout << cnt[4] << endl;
		cout << cnt[5] << endl;
		printf("%lld\n", ans);
	}
	return 0;
}
