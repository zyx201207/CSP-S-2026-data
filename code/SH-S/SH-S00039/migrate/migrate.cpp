#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[N], len;
bool vis[N];
bool f()
{
	int a = x[2] - x[1];
	for(int i = 2; i <n;++i)
	{
		if(a != x[i+1] - x[i]) return 0;
	}
	return 1;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int i = 1; i<= t; ++i)
	{
		cin >> n >> d;
		for(int j = 1; j <= n; ++j)
		{
			cin >> x[j];
			if(f())
			{
				if(x[2] - x[1] > d) cout << 0;
				else 
				{
					if()
				}
			}
			if(x[j+ 1] - x[j] > d) vis[j + 1] = 1;
		}
	}
	return 0;
}
