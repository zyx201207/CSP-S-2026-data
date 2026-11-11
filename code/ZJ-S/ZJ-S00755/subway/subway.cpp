#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505;
const int M=1005;

struct edge
{
	int u,id;
};
struct node
{
	int u,d,id;
};

vector<edge> mp[M];
vector<int> li[M];

int c,n,m,d,q,w[M];
int dil[M][N],dis[M][M];

bool vis[M][N];

void bfs(int s,int line)
{
	dis[s][s]=0;
	
	queue<node> q;
	q.push({s,0,line});
	
	memset(vis,0,sizeof vis);
	vis[s][line]=1;
	
	while(!q.empty())
	{
		node t=q.front();q.pop();
		int u=t.u,d=t.d,id1=t.id;
		
		for(auto tt:mp[u])
		{
			int v=tt.u,id2=tt.id;
			
			if(vis[v][id2]==1) continue;
			vis[v][id2]=1;
			
			int w=dil[u][id1]+dil[u][id2];
			
			if(id1==id2) w=0;
			
			if(d+w+dil[v][id2]<dis[s][v])
			{
				if(id1==id2)
				dis[s][v]=d+w+dil[v][id2];
				q.push({v,d+w,id2});
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{
		int t;cin>>t;
		int u,v,w;
		cin>>v>>w;
		dil[v][i]=w;
		li[v].push_back(i);
		for(int j=2;j<=t;j++)
		{
			cin>>u>>w;
			li[u].push_back(i);
			dil[u][i]=w;
			mp[u].push_back({v,i});
			mp[v].push_back({u,i});
			v=u;
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
			
	for(int i=1;i<=n;i++) 
		for(auto j:li[i]) bfs(i,j);
		
	while(q--)
	{
		int u,v;cin>>u>>v;
		if(u==v) cout<<0<<"\n";
		else cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	
	return 0;
}