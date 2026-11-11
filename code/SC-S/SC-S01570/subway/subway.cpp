#include<bits/stdc++.h>
using namespace std;


int c/*useless*/,n/*线数*/,m/*站数*/,d/*每站最
大经过数*/,q/*询问数*/; 
const int N=500505;
int w[500005];
int t[500][N];
int dis[N],vis[N];
struct node{
	int v,w;
	bool friend operator<(node a,node b)
	{
		return a.w>b.w;
	}
};


vector<node> g[500505];

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



int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
	int las=-1;
	for(int i=1;i<=q;i++)
	{
		
		int x,y;
		cin>>x>>y;
		if(las==x)
		{
			cout<<dis[y]+w[x]+w[y]<<"\n";
			continue;
		}
		las=x;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	/*for(int i=1;i<=m+n;i++)
	{
		cout<<dis[i]<<"   \n"; 
	}*/
	return 0;
}
