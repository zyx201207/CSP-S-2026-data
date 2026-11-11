#include <bits/stdc++.h>
using namespace std;	
int a[500005];
int ans[300005];
bool vis[300005];
int pos[500005];
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
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=1;
				pos[++sum]=a[j];
			}
			else
			{
				bool f=0;
				int x=0;
				for(int h=1;h<=sum;h++)
				{
					if(f==1)
					{
						vis[pos[h]]=0;
						pos[h]=0;
						x++;
					}
					if(pos[h]==a[j])
					{
						f=1;
					}
				}
				sum-=x;
				x=0;
			}
		} 
		for(int j=1;j<=m;j++)
		{
			if(vis[j]==1)
			ans[j]++;
			pos[j]=0;
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout <<ans[i]<<" ";
	}
	return 0;
}
