#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int w[500001];
long long dis[501][501];
vector<pair<int,int> >train[500001]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,x,y,a,t;
	long long ans;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",w+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&a,&t);
			for(int ii=0;ii<train[a].size();ii++)
			{
				dis[train[a][ii].first][i]=min(dis[train[a][ii].first][i],0ll+train[a][ii].second+t);
				dis[i][train[a][ii].first]=min(dis[i][train[a][ii].first],0ll+train[a][ii].second+t);
			}
			train[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ans=inf;
		for(int j=0;j<train[x].size();j++)
			for(int ii=0;ii<train[y].size();ii++)
				ans=min(ans,dis[train[x][j].first][train[y][ii].first]+train[x][j].second+train[y][ii].second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
