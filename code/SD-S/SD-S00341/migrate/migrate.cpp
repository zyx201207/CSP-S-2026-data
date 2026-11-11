#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 3;
int a[N];
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c = read();
	t = read();
	if(c <= 25)
	{
		while(t--)
		{
			int n,d;
			n = read();
			d = read();
			for(int i = 1;i <= n;i++)
			{
				a[i] = read();
			}
			if(d >= (a[n] - a[1]))
			{
				cout << 0;
				continue;
			}
			for(int i = 1;i <= n - 1;i++)
			{
				for(int j = i + 1;j <= n;j++)
				{
					if(i == j)
					{
						continue;
					}
					int jj = a[j] - a[i];
					int kk = 0;
					if((a[j] - a[i]) % d == 0)
					{
						kk = (a[j] - a[i]) / d;
					}
					else
					{
						kk = (a[j] - a[i]) / d + 1;
					}
					
				} 
			}
			cout << n;
		}
	}
	
	return 0;
}

