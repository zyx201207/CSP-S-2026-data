#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[5005][5005];
bool cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n <= 2000)
	{
		for(int i = 1;i <= n;i++)
		{
			f[i][1] = a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 2;j <= i;j++)
			{
				f[i][j] = max(f[i-1][j],f[i-1][j-1] & a[i]);
			}
		}
	}
	else
	{
		f[n][1] = a[1];
		for(int i = 2;i <= m;i++)
		{
			f[n][i] = f[n][i-1] & a[i];
		}
	}
	cout << f[n][m];
	return 0;
}
