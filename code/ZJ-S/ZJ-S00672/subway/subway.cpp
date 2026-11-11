#include<bits/stdc++.h>
using namespace std;
int ca,m,n,d,qu,len[500010];
long long w[510],t[500010][30],ans=1e18,tim[510][20010];
int in[500010][30];
long long dis[20010][510],dist[1010][1010];
vector<int>a[500010];
struct point
{
	int x,line;
	long long val;
};
queue<point>q;
void solve1()
{
	while (qu--)
	{
		ans=1e18;
		int s,end;
		scanf("%d %d",&s,&end);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				dis[i][j]=1e18;
		for (int i=1;i<=in[s][0];i++)
		{
			q.push({s,in[s][i],w[s]+tim[in[s][i]][s]});
			dis[s][in[s][i]]=w[s]+tim[in[s][i]][s];
		}
		while (!q.empty())
		{
			point u=q.front();
			q.pop();
			for (int i=0;i<len[u.line];i++)
			{
				int y=a[u.line][i];
				if (y==end)
				{
					ans=min(ans,u.val+tim[u.line][end]);
					continue;
				}
				for (int j=1;j<=in[a[u.line][i]][0];j++)
				{
					point v;
					v.x=a[u.line][i];
					if (v.x==u.x) continue;
					v.line=in[v.x][j];
					if (v.line==u.line) continue;
					v.val=u.val;
					if (v.line!=u.line) v.val+=tim[u.line][v.x]+tim[v.line][v.x];
					if (dis[v.x][v.line]>v.val&&v.val<ans)
					{
						dis[v.x][v.line]=v.val;
						q.push(v);
					}
				}
			}
		}
		printf("%lld\n",ans+w[end]);
	}
}
void solve2()
{
	memset(dist,0x3f,sizeof(dist));
	for (int s=1;s<=n;s++)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				dis[i][j]=1e18;
		for (int i=1;i<=in[s][0];i++)
		{
			q.push({s,in[s][i],w[s]+tim[in[s][i]][s]});
			dis[s][in[s][i]]=w[s]+tim[in[s][i]][s];
		}
		while (!q.empty())
		{
			point u=q.front();
			q.pop();
			for (int i=0;i<len[u.line];i++)
				for (int j=1;j<=in[a[u.line][i]][0];j++)
				{
					point v;
					v.x=a[u.line][i];
					if (v.x==u.x) continue;
					v.line=in[v.x][j];
					v.val=u.val;
					if (v.line!=u.line) v.val+=tim[u.line][v.x]+tim[v.line][v.x];
					if (dis[v.x][v.line]>v.val)
					{
						dis[v.x][v.line]=v.val;
						dist[s][v.x]=min(dist[s][v.x],v.val+tim[v.line][v.x]);
						q.push(v);
					}
				}
		}
		for (int j=1;j<=n;j++) dist[s][j]+=w[j];
	}
	while (qu--)
	{
		int s,end;
		scanf("%d %d",&s,&end);
		printf("%lld\n",dist[s][end]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> ca >> m >> n >> d >> qu;
	for (int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&len[i]);
		for (int j=1;j<=len[i];j++)
		{
			int x;
			long long y;
			scanf("%d %lld",&x,&y);
			in[x][++in[x][0]]=i;
			t[x][in[x][0]]=y;
			tim[i][x]=y;
			a[i].push_back(x);
		}
	}
	if (ca<=6) solve1();
	else if (ca<=11) solve2();
	else solve1();
	return 0;
}