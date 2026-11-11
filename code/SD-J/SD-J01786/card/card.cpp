#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int ans[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int vis[300007]={};
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
			}
			else
			{
				for(int k=1;k<=m;k++)
				{
					if(vis[k]>vis[a[j]])
					{
						vis[k]=0;
					}
				}
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j]!=0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

