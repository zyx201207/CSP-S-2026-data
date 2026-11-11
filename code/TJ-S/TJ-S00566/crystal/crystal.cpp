#include <bits/stdc++.h>
using namespace std;
long long a[500005],p[500005];
int ans = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) 
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		p[i] = p[i-1] + a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		long long cost = a[i] * i - p[i];
		if (cost <= m)
			ans = max(ans,i);
		else
		{
			for (int j = 1;j <= i;j++)
			{
				if (cost <= m)
				{
					ans = max(ans,j - i);
					break;
				}
				cost -= (a[i] - a[j]);
			}	
		} 
	}
	cout << ans << endl;
	return 0;	
} 
