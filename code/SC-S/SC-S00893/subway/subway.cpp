#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500+10;
const int MAXM = 5e5+10;
const int MAXD = 20+1;
const long long INF=1e18;

class Graph
{
private:
		
	int N,M,D,Q;
	
	int w[MAXM];
	
	long long d[MAXN][MAXN];
	
	vector<pair<int,int>> way[MAXM];
	
	inline void Add(int u,int v,long long w)
	{
		d[u][v]=min(d[u][v],w);
	}
	
	void Floyd()
	{
		for(int i=1;i<=N;i++)
		{
			d[i][i]=0;
		}
		
		for(int k=1,i,j;k<=N;k++)
		{
			for(i=1;i<=N;i++)
			{
				for(j=1;j<=N;j++)
				{
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	
	long long Calculate(int u,int v)
	{
		long long ret=INF;
		
		for(int i=0,j,x,y;i<way[u].size();i++)
		{
			for(j=0;j<way[v].size();j++)
			{
				x=way[u][i].first,y=way[v][j].first;
				long long w=way[u][i].second+way[v][j].second;
				ret=min(ret,w+d[x][y]);
			}
		}
		
		return ret;
	}
	
public:
	
	Graph()
	{
		for(int i=1,j;i<MAXN;i++)
		{
			for(j=1;j<MAXN;j++)
			{
				d[i][j]=INF;
			}
		}
	}
	
	void Solve()
	{
		cin>>N>>M>>D>>Q;
		
		for(int i=1;i<=M;i++)
		{
			cin>>w[i];
		}
		
		for(int i=1,k,j,a,t;i<=N;i++)
		{
			cin>>k;
			
			for(j=1;j<=k;j++)
			{
				cin>>a>>t;
				way[a].push_back({i,t});
			}
		}
		
		for(int i=1,x,y,u,v;i<=M;i++)
		{
			for(x=0;x<way[i].size();x++)
			{
				for(y=0;y<way[i].size();y++)
				{
					if(x==y)
					{
						continue;
					}
					
					u=way[i][x].first,v=way[i][y].first;
					long long w=way[i][x].second+way[i][y].second;
					Add(u,v,w),Add(v,u,w);
				}
			}
		}
		
		Floyd();
		
		for(int q=1,x,y;q<=Q;q++)
		{
			cin>>x>>y;
			long long ans=w[x]+w[y]+Calculate(x,y);
			cout<<ans<<'\n';
		}
	}
};

Graph g;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c;
	
	cin>>c;
	
	g.Solve();
	
	return 0;
}