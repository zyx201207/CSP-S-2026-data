#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,maxs;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n +1);
	long long f[n + 1][n + 1];
	for(int i = 1;i < n;i++)
	{
		f[i][i + 1] = a[i + 1] - a[i];
	}
	f[1][1] = 0;
	for(int i = 1;i < n;i++)
	{
		for(int j = i + 2;j <= n;j++)
		{
			f[i][j] = f[i][j - 1] + f[j - 1][j];
		}
	}
	for(int i = 1;i < n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(f[i][j] <= m)
			{
				if(maxs < (j - i + 1))
				{
					maxs = j - i + 1;
				}
			}
		}
	}
	cout << maxs;
	return 0;
}
