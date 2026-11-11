#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],cnt[300001],f[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int tp=0;
		f[++tp]=a[i];
		for (int j=i+1;j<=n;j++)
		{
			for (int k=1;k<=tp;k++)
			{
				if (f[k]==a[j])
				{
					tp=k-1;
					break;
				}
			}
			f[++tp]=a[j];
		}
		for (int j=1;j<=tp;j++)
		{
			cnt[f[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}