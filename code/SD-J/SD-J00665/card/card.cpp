#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int main()
{
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		for (int j=i;j<=n;j++)
		{
			int r=j+1;
			while (a[r]!=a[j] && r+1<=n)
			{
				r++;
			}
			if (a[r]==a[j])
			{
				j=r;
				x=r;
			}
		}
		for (int j=x;j<=n;j++)
		{
			ans[a[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout <<ans[i]<<" ";
	}
	return 0;
}
