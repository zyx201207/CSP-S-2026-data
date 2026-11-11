#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[1010][1010];
long long x[1000010],d,ans;
void dfs(int s,int t,int k,int l)
{
	if(k>f[s][t]-1)
	{
		if(x[t]-x[l]<=d)ans++;
		return;
	}
	for(int i=l+1;i<t;i++)
	{
		if(x[i]-x[l]>d)break;
		dfs(s,t,k+1,i);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e9;
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)f[i][j]=1;
				else
				{
					for(int k=i+1;k<j;k++)
					{
						if(x[j]-x[k]<=d)f[i][j]=min(f[i][j],f[i][k]+1);
					}
				}
			}
		}
		long long p=0;
		if(n<=9)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ans=0;
					dfs(i,j,1,i);
					if(ans==2)p++;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ans=0;
					for(int k=i+1;k<j;k++)
					    if(f[i][k]+f[k][j]==f[i][j]) ans++;
					if(ans==2)p++;
				}
			}
		}

		printf("%d\n",p);
	}
	return 0;
}
