#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[100005],sum[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
				num[i]++;
			if(a[j]>i)
				continue;
		}
	}
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+num[i];
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	return 0;
}
