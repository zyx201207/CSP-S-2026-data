#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005],vis[300005],ans[300005],h[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
//			cout<<a[j]<<" ";
			if(vis[a[j]]!=1)
			{
				vis[a[j]]=1;
				h[a[j]]=j;
			}
			else
			{
//				memset(vis,0,sizeof(vis));
				for(int k=h[a[j]];k<=j;k++)
				{
					vis[a[k]]=0;
				}
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=vis[j];
		}
//		memset(vis,0,sizeof(vis));
//		for(int j=1;j<=m;j++)
//		{
//			cout<<vis[j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" "; 
	}
	return 0;
}
// 10 3 3 1 2 1 3 2 3 1 2 1
