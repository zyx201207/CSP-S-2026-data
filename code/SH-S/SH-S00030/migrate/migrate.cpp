#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,method,minn;
long long d;
long long x[2000005],s[20000005];
void dfs(int u,int v,int m)
{
	if(m>2)
	{
		return;
	}
	if(u==v)
	{
		method++;
		return;
	}
	for(int i=u;i<=v;i++)
	{
		if(x[i]-x[u]<=d)
		{
			dfs(i,v,m+1);
		}
		
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			s[i]=x[i]-x[1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				method=0;
				dfs(i,j,0);
				if(method==2)
				{
					ans++;
				}
			}
		} 
		cout<<ans<<endl;
	}
}
