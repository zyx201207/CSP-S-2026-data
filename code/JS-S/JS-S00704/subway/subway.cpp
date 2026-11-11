#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<pair<int,int>>subs[500005];
long long dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d %d",&a,&t);
			subs[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=1e15;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(subs[i].size()>1)
		{
			for(int sa=0;sa<subs[i].size();sa++)
			{
				for(int sb=sa+1;sb<subs[i].size();sb++)
				{
					dis[subs[i][sa].first][subs[i][sb].first]=min(dis[subs[i][sa].first][subs[i][sb].first],0ll+subs[i][sa].second+subs[i][sb].second);
					dis[subs[i][sb].first][subs[i][sa].first]=min(dis[subs[i][sb].first][subs[i][sa].first],0ll+subs[i][sa].second+subs[i][sb].second);
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
			for(int j=k+1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
		for(int i=k+1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=dis[j][i]=min(dis[i][j],dis[j][i]);
		}
	}
	long long ans;
	for(int i=1;i<=q;i++)
	{
		int st,ed;
		scanf("%d %d",&st,&ed);
		ans=1e15;
		for(auto u:subs[st])
		{
			for(auto v:subs[ed])
			{
				ans=min(ans,w[st]+u.second+dis[u.first][v.first]+v.second+w[ed]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
15:23 
My solution may be correct!!! Testing 0.6sec with O2

15:43
GG I finished coding

15:56
Optimized.Why 1.6s in subway6???

16:28
Finally get <1s in subway7 with O2!!!GG
*/
