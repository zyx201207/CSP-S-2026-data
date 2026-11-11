#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
bool vis[100010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				for(int k=j;k>=i;k--)
				{
					if(a[k]==a[j]&&k!=j)
					{
						break;
					}
					vis[a[k]]=0;
				}
				vis[a[j]]=1;
			}
			else
			{
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(s[j]==1)
			{
				s[j]++;
			}
		}
	}
	
	
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}

