#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005],kards[500005];
signed main()
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
		memset(kards,0,sizeof(kards));
		for(int j=i;j<=n;j++)
		{
			if(kards[a[j]]!=0)
			{
				for(int k=kards[a[j]];k<=j;k++)
				{
					kards[a[k]]=0;
				}
			}
			kards[a[j]]=j;
		}
		for(int i=1;i<=m;i++)
		{
			if(kards[i]!=0)
			{
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
