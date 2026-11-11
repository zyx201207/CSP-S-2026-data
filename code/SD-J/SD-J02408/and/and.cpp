#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	if(m == 1)
	{
		sort(a + 1,a + n + 1,greater<int>());
		cout<<a[1];
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,a[i] & a[j]);
			}
		}
	}
	else if(m == 3)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				for(int k = j + 1;k <= n;k++)
				{
					maxx = max(maxx,a[i] & a[j] & a[k]);
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
