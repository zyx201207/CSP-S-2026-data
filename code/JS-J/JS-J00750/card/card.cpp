#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn,ma,a[500005],ans[500005];
bool vis[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500||m<=2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(vis[a[j]]!=0)
				{
					for(int k=j-1;k>=i;k--)
					{
						if(a[k]!=a[j]) vis[a[k]]=0;
						else break;
					}
					vis[a[j]]=1;
				}
				else vis[a[j]]=1;
			}
			for(int j=1;j<=m;j++) ans[j]+=vis[j];
			for(int j=1;j<=m;j++) vis[j]=0;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1]) ans[a[i]]=i;
			else
			{
				while(a[i]==a[i+1]) i++;
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
