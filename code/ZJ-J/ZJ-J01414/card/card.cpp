#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;

int n,m;
int a[maxn];
int b[maxn];
int vis[maxn];
int c[maxn];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]&&vis[j]==0&&vis[b[a[j]]]==0)
			{
				for(int k=j-1;k>=b[a[j]];k--)
				{
					vis[k]=1;
				}
			}
			else
			{
				b[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[j]==0) c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	
	return 0;
}

