#include<bits/stdc++.h>
using namespace std;
long long f[505][505];
long long w[500010];
int cnt[500010];
vector<long long> v[500010],tim[500010];
long long read()
{
	long long x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		long long c=read();
		while(c--)
		{
			long long a=read(),t=read();
			v[a].push_back(i);
			tim[a].push_back(t);
			cnt[a]++;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<cnt[i];j++)
		{
			for(int k=j+1;k<cnt[i];k++)
			{
				f[v[i][j]][v[i][k]]=f[v[i][k]][v[i][j]]=min(f[v[i][j]][v[i][k]],tim[i][j]+tim[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		long long x=read(),y=read();
		long long ans=LLONG_MAX;
		for(int i=0;i<cnt[x];i++)
		{
			for(int j=0;j<cnt[y];j++)
			{
				ans=min(ans,w[x]+w[y]+tim[x][i]+tim[y][j]+f[v[x][i]][v[y][j]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

