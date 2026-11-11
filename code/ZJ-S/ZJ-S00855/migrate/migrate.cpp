#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d;
long long s[2010101];
long long dis[2010101];
long long vis[2010101];
void dfs(int x,int sum)
{
	if(sum==vis[x])
	{
		dis[x]++;
	}
	else if(sum<vis[x])
	{
		vis[x]=sum;
		dis[x]=1;
	}
	if(x==n) return ;
	for(int i=x+1;i<=n;i++)
	{
		if(s[i]-s[x]<=d)
		{
			dfs(i,sum+1);
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		for(int i=1;i<=n;i++)
		{
			memset(dis,0,sizeof(dis));
			memset(vis,0x7f,sizeof(vis));
			dfs(i,0);
			for(int j=i;j<=n;j++)
			{
				if(dis[j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}