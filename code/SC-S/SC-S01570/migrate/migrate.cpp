#include<bits/stdc++.h>
using namespace std;


int c/*useless*/,n/*线数*/,m/*站数*/,d/*每站最
大经过数*/,q/*询问数*/; 
const int N=500505;
int w[500005];
int t[500][N];
int dis[N],vis[N];
int f[N][20];
int depth[N];
int tdis[201][N];
int cnt;
struct node{
	int v,w;
	bool friend operator<(node a,node b)
	{
		return a.w>b.w;
	}
};


vector<node> g[500505];


void dfs(int u)
{
	depth[u]=++cnt;
	for(int i=1;i<=19;i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(node v:g[u])
	{
		if(vis[v.v])continue;
		f[v.v][0]=u;
		dfs(v.v);
	}
} 

void dij(int u)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	//sort(g[u].begin(),g[u].end(),cmp);
	q.push(node{u,0});
	vis[u]=1;
	dis[u]=0;
	while(!q.empty())
	{
		node  t=q.top();q.pop();
		//cout<<"  ?   "<<t;
		//sort(g[t].begin(),g[t].end(),cmp);
		//cout<<"   "<<g[t].empty()<<"\n";
		for(node h:g[t.v])
		{
			int v=h.v;int w=h.w;
			if(vis[v])continue;
			//cout<<"    !   "<<v<<"\n";
			//cout<<"      before"<<dis[v];
			if(t.w+w<=dis[v])
			{
				dis[v]=t.w+w;	
			}
			//cout<<"   now"<<dis[v];
			if(!vis[v])
			{
				q.push({v,dis[v]});
				vis[v]=1;
			}
		}
	}
}

int  lca(int x,int y)
{
	if(x<y)
	{
		swap(x,y);
	}
	int k=depth[x]-depth[y];
	for(int i=0;i<=19;i++)
	{
		if(k&1)
		{
			x=f[x][i];
		}
		k/=2;
	}
	if(x==y)
	{
		return x;
	}
	for(int i=19;i>0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}



int main()
{
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[m+i].push_back(node{a,t});
			g[a].push_back(node{m+i,t});
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		dij(i);
		for(int j=1;j<=m+n;j++)
		{
			tdis[i][j]=dis[j];
		}
	}
	int las=-1;
	for(int i=1;i<=q;i++)
	{
		
		int x,y;
		cin>>x>>y;
		int ans=INT_MAX;
		int ll=lca(x,y);
		for(node k:g[x])
		{
			ans=min(ans,tdis[k.v][y]+k.w+w[x]+w[y]-2*tdis[k.v][ll]);
		}
		cout<<ans;
	}
	/*for(int i=1;i<=m+n;i++)
	{
		cout<<dis[i]<<"   \n"; 
	}*/
	return 0;
}
