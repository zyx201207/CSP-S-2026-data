#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 7;

inline int read()
{
	int w = 0, c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		c = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return w * c;
}

int a[MAXN];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c = read(), t = read();
	while(t--)
	{
		int n = read(), x = read();
		int d = 0;
		int f = 1;
		for(int i = 1;  i <= n;  i++)
		{
			a[i] = read();
			if(i == 2)
			{
				d = a[i] - a[i-1];
			}
			if(i >= 3)
			{
				if(d != a[i] - a[i-1])
				{
					f = 0;
				}
			}
		}
		if(f)
		{
			if(x >= 2 * d && x <= 3 * d - 1)
			{
				cout<<n-3<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	
	return 0;
}
