#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],vis[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>600)
	{
		for(int i=1;i<=n;i++)ans[a[i]]=max(i,ans[a[i]]);
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				for(int k=vis[a[j]];k<j;k++)
				{
					vis[a[k]]=0;
				}
			}
			vis[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=(vis[j]>0);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
