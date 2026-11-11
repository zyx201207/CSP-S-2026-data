#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int u;
	int w;
};

const int Inf= -2147483647;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,n,m,d,q;  //测试编号，地铁线路数，地铁站数，最大线路数，出行计划次数。
	cin>>c>>n>>m>>d>>q;
	
	vector<int> ml(m+1,0);  //m[i]表示从第i站地铁口到站厅的距离。 
	for(int i=1;i<=m;++i) cin>>ml[i];
	vector<vector<Node>> g(m+1);  
	
	vector<vector<int>> axl(n+1); //axl[i][j]表示第i条线路经过的第j个地铁站编号。 
	vector<vector<int>> txl(n+1); //txl[i][j]表示从axl[i][j]的地铁站的第i个线路走到前厅要的时间。 
	for(int i=1;i<=n;++i)
	{
		int kii;
		cin>>kii;
		for(int j=1;j<=kii;++j)
		{
			int u,v;
			cin>>u>>v;
			axl[i].push_back(u);
			txl[i].push_back(v);
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		int len=int(axl[i].size());
		for(int j=0;j<len;j++)
		{
			for(int k=j+1;k<len;++k)
			{
				int u=axl[i][j];
				int v=axl[i][k];
				g[u].push_back({v,txl[i][j]+txl[i][k]});
				g[v].push_back({u,txl[i][j]+txl[i][k]});
			}
		}
	}
	
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		long long ans=0;
		ans=ml[s]+ml[e];
		
		vector<int> dist(m+1,-Inf);
		vector<bool> vis(m+1,0);
		dist[s]=0;
		priority_queue<
		pair<long long,int>,
		vector<pair<long long,int>>
		>p;
		p.push({0,s});
		
		while(!p.empty())
		{
			auto z=p.top();
			p.pop();
			int u=z.second;
			long long w=z.first;
			
			if(dist[u]!=w) continue;
			else vis[u]=true;
			
			for(Node v:g[u])
			{
				int nv=v.u;
				int nw=v.w;
				
				if(dist[u]+nw<dist[nv]) 
				{
					dist[nv]=dist[u]+nw;
					p.push({dist[nv],nv});
				}
			}
		}
		cout<<dist[e]+ans<<'\n';
	}
	return 0;
}
