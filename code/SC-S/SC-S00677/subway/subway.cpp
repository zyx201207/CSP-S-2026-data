#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;

typedef pair<int,int> pii;

int tot,dis[maxn],w[maxn],t[550][maxn],ans[maxn],lt[maxn],dt[maxn],cnt[maxn],c,n,m,d,q;
vector<pii> que[maxn],edge[maxn];

void init(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(lt,0,sizeof(lt));
	memset(dt,0,sizeof(dt));
	memset(cnt,0,sizeof(cnt));
	dis[s]=0;
}

void dfs(int u,int idx)
{
	cnt[u]++;
	int len=edge[u].size();
	for(int i=0;i<len;i++)
	{
		int v=edge[u][i].first,id=edge[u][i].second;
		if(cnt[v]>d) continue;
//		cout<<u<<' '<<v<<' '<<id<<'\n';
		if(idx==-1 || idx==id)//起点或者是同一站点
		{
			if(dis[v]>dis[u])
			{
				dis[v]=dis[u];
				lt[v]=id;
				dt[v]=u;
			}
//			dis[v]=min(dis[v],dis[u]);
//			cout<<dis[v]<<"rrrr\n";
		}
		else
		{
			if(dis[v]>dis[u]+t[idx][u]+t[id][u])
			{
				dis[v]=dis[u]+t[idx][u]+t[id][u];
				lt[v]=id;
				dt[v]=u;
			}
		}
		dfs(v,id);
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,last=-1;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,x;
			cin>>u>>x;
			t[i][u]=x;
			if(last!=-1)
			{
				edge[last].push_back(make_pair(u,i)),
				edge[u].push_back(make_pair(last,i));
			}
			last=u;
		}
	}
//	for(int i=1;i<=5;i++)
//	{
//		for(int j=0;j<edge[i].size();j++)
//		{
//			cout<<edge[i][j].first<<' ';
//		}
//		cout<<'\n';
//	}
	
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		que[u].push_back(make_pair(i,v));
	}
	
	
	for(int i=1;i<=m;i++)
	{
		if(que[i].size()>=1)
		{
//			cout<<i<<"---------\n";
			init(i);
			dfs(i,-1);
//			for(int j=1;j<=5;j++)
//			{
//				cout<<lt[j]<<' ';
//			}
//			cout<<'\n';
			int len=que[i].size();
			for(int j=0;j<len;j++)
			{
				int id=que[i][j].first,v=que[i][j].second;
//				cout<<1111111;
				int cur=v,tmp=cur;
				while(cur!=i)
				{
					if(cur!=v) tmp=cur;
					cur=dt[cur];
//					cout<<cur<<' ';
				}
				ans[id]=dis[v]+w[i]+w[v]+t[lt[v]][v]+t[lt[tmp]][i];
//				cout<<ans[id]<<' ';
			}
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
	}
	
	return 0;
}