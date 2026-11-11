#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int sum[1000010];
int n,m;
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
		int vis[1000010];
		int place[1000010];
		memset(vis,0,sizeof vis);
		memset(place,0,sizeof place);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=j;
				place[j]=a[j];
			}
			else{
				for(int k=vis[a[j]];k<=j;k++)
				{
					vis[place[k]]=0;
					place[k]=0;
					
				}
				place[j]=a[j];
				vis[a[j]]=j;
			}
			
		}
		for(int q=1;q<=n;q++)
		{
			sum[place[q]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
		}
	return 0;

}
