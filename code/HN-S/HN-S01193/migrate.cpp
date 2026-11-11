#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int N = 2e6 + 5;
int c , T;
int x[N];
int f[N];

signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	c = read() , T = read();
	while(T --)
	{
		int n , d;
		cin >> n >> d;
		memset(x , 0x3f3f3f3f , sizeof(x));
		for(int i = 1;i <= n; ++ i)
		{
			x[i] = read();	
		}
		memset(f , 0 , sizeof(f));
		int ans = 0;
		for(int i = 1;i <= n; ++ i)
		{
//			memset(dd , 0 , sizeof(dd));
			int j;
			for(j = 1;j <= n; ++ j)
			{
				if(x[j] - x[i] > d)
				{
					break;
				}
				f[i] = 1;
			}
			for(;j <= n; ++ j)
			{
				int minn = 0x3f3f3f3f3f3f3f3f , num = 0;
				for(int k = 1;x[j] - x[j - k] <= d; ++ k)
				{
					if(minn > f[j - k])
					{
						minn = f[j - k];
						num = 1;
					}
					else if(minn == f[j - k])
					{
						num ++;
					}
				}
				if(num == 2)
					ans ++;	
				f[j] = minn + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
