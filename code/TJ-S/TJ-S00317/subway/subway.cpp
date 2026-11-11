#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,m,n,d,q;
vector<int>cha[100010];
int jinzhan[100010];
struct sta
{
	int lin,num,tim;
	bool operator <(const sta& rhs)const
	{
		return tim>rhs.tim;
	}
};
vector<sta>g[100010][100];
int ti[100010][100];//zhantai->zhanting
int dis[100010][100];//dis i j      j hao xian i zhan de zhan tai dao chu shi zhan ting de ju li
int vis[100010][100];
void dij(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<sta>q;
	for(int i=0;i<cha[st].size();i++)
	{
		int line=cha[st][i];
		dis[st][line]=ti[st][line];
		q.push({line,st,ti[st][line]});
	}

	while(!q.empty())
	{
		int u=q.top().num;
		int line=q.top().lin;
		q.pop();
		if(vis[u][line])continue;
		vis[u][line]=1;
		for(int i=0;i<g[u][line].size();i++)
		{
			int v=g[u][line][i].num;
			int l2=g[u][line][i].lin;
			int w=g[u][line][i].tim;
			if(dis[v][l2]>dis[u][line]+w)
			{
				dis[v][l2]=dis[u][line]+w;
				q.push({l2,v,dis[v][l2]});
			}
		 } 
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>jinzhan[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int la=0;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[la][i].push_back({i,a,0});
			g[a][i].push_back({i,la,0});
			la=a;
			ti[a][i]=t;
			for(int l=0;l<cha[a].size();l++)
			{
				int line=cha[a][l];
				int w=ti[a][line]+t;
				g[a][i].push_back({line,a,w});
				g[a][line].push_back({i,a,w});	
			}
			cha[a].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dij(x);
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dis[y][i]+ti[y][i]);
		}
		cout<<ans+jinzhan[x]+jinzhan[y]<<"\n";
	}
	return 0;
}
