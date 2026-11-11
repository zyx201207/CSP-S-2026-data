#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647 
long long c,n,m,D,q;
long long w[500005],k[505];
long long d[505][505];
vector<long long> g1[500005];
vector<long long> g2[500005];
long long dis[505][505];
void solve_path(int start)
{
	int i,j,cnt;
	memset(dis[start],-1,sizeof(dis[start]));
	dis[start][start]=0;
	cnt=114514;
	while(cnt!=0)
	{
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j]==-1) continue;
				if(i==j) continue;
				if(dis[start][i]!=-1)
				{
					if(dis[start][j]==-1)
					{
						dis[start][j]=dis[start][i]+d[i][j];
						cnt++;
					}
					else if(dis[start][i]+d[i][j]<dis[start][j]) 
					{
						dis[start][j]=dis[start][i]+d[i][j];
						cnt++;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>D>>q;
	long long i,j;
	long long a,t,u,v;
	long long ans,len,lu,lv;

	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			g1[a].push_back(i);
			g2[a].push_back(t);
		}
	}
	memset(d,-1,sizeof(d));
	for(i=1;i<=m;i++)
	{
		int len=g1[i].size();
		for(int i1=0;i1<len;i1++)
		{
			for(int i2=0;i2<len;i2++)
			{
				if(i1==i2) d[g1[i][i1]][g1[i][i2]]=0;
				else if(d[g1[i][i1]][g1[i][i2]]==-1) d[g1[i][i1]][g1[i][i2]]=g2[i][i1]+g2[i][i2];
				else d[g1[i][i1]][g1[i][i2]]=min(d[g1[i][i1]][g1[i][i2]],g2[i][i1]+g2[i][i2]);
			}
		}
	}
	for(i=1;i<=n;i++) solve_path(i);
	for(t=1;t<=q;t++)
	{
		cin>>u>>v;
		ans=INF;
		for(i=0;i<g1[u].size();i++)
		{
			for(j=0;j<g1[v].size();j++)
			{
				lu=g1[u][i];
				lv=g1[v][j];
				len=dis[lu][lv]+w[u]+w[v]+g2[u][i]+g2[v][j];
				if(len<ans) ans=len;
			}
		}
		printf("%lld\n",ans);
	}
}
