#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],x[300001],ans[300001];
bool vis[500001],flag[300001];
int main()
{	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{	memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++)
		{	if(x[a[j]])
				for(int k=x[a[j]];k<j;k++)
				{	vis[k]=1;
					x[a[k]]=0;
				}
			x[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
			if(!vis[j])
				flag[a[j]]=1;
		for(int j=1;j<=m;j++)
			if(flag[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
