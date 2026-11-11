#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int n, m;

int a[N][30];
bool vis[N];

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < 30; j++)
		{
			if(x & (1 << j))
			{
				a[i][j] = 1;
			}
		}
	}
	int ans = 0;
	int f = 0;
	for(int j = 29; j >= 0; j--)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(f == 0)
			{
				if(a[i][j] == 1)
				{
					cnt++;
				}
			}
			else
			{
				if(a[i][j] == 1 && vis[i] == 1)
				{
					cnt++;
				}
			}
		}
		if(cnt >= m)
		{
			if(f == 0)
			{
				for(int i = 1; i <= n; i++)
				{
					if(a[i][j] == 1)
					{
						vis[i] = 1;
					}
				}
				f = 1;
			} 
			else
			{
				for(int i = 1; i <= n; i++)
				{
					if(a[i][j] == 1 && vis[i] == 1)
					{
						vis[i] = 1;
					}
					else
					{
						vis[i] = 0;
					}
				}
			}
			ans += (1 << j);
		}
	}
	cout << ans << endl;
	return 0;
} 
//Trick||Treat! 
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7
