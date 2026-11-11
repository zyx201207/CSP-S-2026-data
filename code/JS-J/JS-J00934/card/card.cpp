#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[200005],tong[200005],x[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(tong,0,sizeof(tong));
		for(int j=i;j<=n;j++)
		{
			tong[a[j]]++;
			if(tong[a[j]]==1)
			{
				x[a[j]]=j;
			}
			else if(tong[a[j]]==2)
			{
				for(int k=x[a[j]];k<j;k++)
				{
					if(tong[a[k]]!=0)
					{
						tong[a[k]]--;
					}
				}
			}
			
		}
		for(int k=1;k<=m;k++)
		{
			if(tong[k]>0)
			{
				ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
