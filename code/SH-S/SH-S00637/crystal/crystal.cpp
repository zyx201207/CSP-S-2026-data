#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int p = 1,ans = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			long long sum = 0;
			for (int k = i;k <= j;k++)
			{
				sum += a[k];
			}
			long long t = 0;
			for (int k = i;k <= j;k++)
			{
				t += abs(sum/(j-i+1)-a[k]);
			}
			if (t <= m) ans = max(ans,j-i+1); 
			else break;
		} 
	}
	cout << ans << endl;
}
