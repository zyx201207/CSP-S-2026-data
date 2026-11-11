#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[50001],t=1,ans[50001]={0},sum[30001]={0};
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (m==1)
	{
		cout << n;
	}
else{
	while (n--)
	{
		for (int i=t;i<=n;i++)
		{
			ans[i]=a[i];
		}
		for (int r=t;r<=n;r++)
		{
			for (int l=t;l<r;l++)
			{
				if (ans[l]==ans[r])
				{
					for (int k=l;k<r;k++)
					{
						ans[k]=0;
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			cout << ans[i];
		}
	 	for (int i=1;i<=n;i++)
		{
			if (ans[i]!=0)
			{
				sum[ans[i]]++;
			}
		}
		t++;
	}
	for (int i=1;i<=m;i++)
	{
		cout << sum[i] << " ";
	}}
	return 0;
}
