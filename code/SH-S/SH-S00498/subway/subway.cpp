#include<bits/stdc++.h>
using namespace std;

vector<int>w;
const int INF = 100000000;

struct point
{
	int ti;
	int id;
};

vector<vector<point>> g(500005);vector<vector<int>>f(500005);
int dist[500005],vis[500005];
int c,n,m,d,q;
void check(int x)
{
	//cout<<"now: "<<x<<"("<<dist[x]<<")"<<endl; 
	
	if(vis[x]||dist[x]==INF){return ;}
	vis[x]=1;
	//dist[x]+=w[x-1];

	int ma = INF,mi=INF,ml=INF;
	for(int i = 0;i<f[x].size();i++)
	{
		int line = f[x][i];
		
		for(int j = 0;j<g[line].size();j++)
		{
			int p = g[line][j].id;
			if(vis[p]){continue;}
			dist[p]=min(dist[p],dist[x]+g[line][p-1].ti);
			
			if(dist[x]+g[line][p-1].ti<dist[p])
			{
				dist[p]=dist[x]+g[line][p-1].ti;
			
				
			}
			
		//	cout<<p<<" -> "<<min(dist[p],dist[x]+g[line][p-1].ti)<<endl;
			if(ma>dist[p]&&!vis[p]){ma=dist[p];mi=p;
			}
		}
	}
	if(mi==	INF){return ;
	}
	check(mi);
	
}


int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	
	for(int i = 1;i<=m;i++){int s;cin>>s;w.push_back(s);}
	
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			
			int a,b;
			cin>>a>>b;
			point p;
			p.ti = b;p.id = a;
			g[i].push_back(p);
			
			f[g[i][j].id].push_back(i);
		
		}
	}
	
	
	
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;	
		
		for(int i = 1;i<=m;i++){dist[i]=INF;vis[i]=0;}
		dist[x]=w[x-1];
		
		check(x);
		cout<<dist[y]<<endl;	
		
	} 
	

	
	return 0; 
}
