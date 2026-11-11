#include<bits/stdc++.h>
#define M 500005
#define N 505
using namespace std;
int n,m,c,d,q,st,ed,a[M],to,val,k,b2[M][21],c2[M][21],u,v;
vector<int> b1[N],c1[N];
long long dist[N][N],ans,sum;
long long f()
{
	ans=1e18;
	for(int i=1;i<=b2[st][0];++i)
		for(int j=1;j<=b2[ed][0];++j)
		{
			sum=(long long)dist[b2[st][i]][b2[ed][j]]+c2[st][i]+c2[ed][j];
			if(ans>sum)ans=sum;
		}
	return ans;
}
void add(int i)
{
	b2[to][++b2[to][0]]=i,
	c2[to][++c2[to][0]]=val,
	b1[i].push_back(to),
	c1[i].push_back(val);
}
void pre()
{
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
	if(i!=j)dist[i][j]=(long long)1e18;
	for(int i=1;i<=n;++i)
		for(int j=0;j<b1[i].size();++j)
			for(int k=1;k<=b2[b1[i][j]][0];++k)
			{
				u=i,v=b2[b1[i][j]][k];
				if(u==v)continue;
				sum=(long long)c1[i][j]+c2[b1[i][j]][k];
				if(dist[u][v]>sum)dist[u][v]=dist[v][u]=sum;
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<n;++j)
		{
			if(j==i)continue;
			if(dist[i][j]==0)continue;
			for(int k=j+1;k<=n;++k)
			{
				if(dist[i][k]==0)continue;
				sum=(long long)dist[i][j]+dist[i][k];
				if(sum<dist[j][k])dist[j][k]=dist[k][j]=sum;
			}
		}
}
int main()
{
	freopen("subway6.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&to,&val);
			add(i);
		}
	}
	pre();
	while(q--)
	{
		scanf("%d%d",&st,&ed);
		printf("%lld\n",(long long)a[st]+a[ed]+f());
	}
	return 0;
}