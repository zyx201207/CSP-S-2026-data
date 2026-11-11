#include<iostream>
#include<cstring>
using namespace std;
int a[500005],sum[500005];
bool vis[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				memset(vis,0,sizeof(vis));
			}
			vis[a[j]]=1;
		}
		for(int k=1;k<=m;k++)
		{
			if(vis[a[k]])
			{
				sum[a[k]]++;
			}
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
} 
