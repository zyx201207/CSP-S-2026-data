#include<bits/stdc++.h>
//#define endl '\n'
//#define int long long
using namespace std;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
const int N=5e5+10;
long long w[N];
const int Q=2e4+10;
long long a[505][Q];
long long t[505][Q];
bool ym[505][Q];
struct node
{
	int to,w;
};
int dist[N];
bool vis[N];
vector<node> g[N];
bool huanc[505];
void djstl(int s,int e)
{
	vector<int> path;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=1;i<=m;i++)
	{
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=0;
	pq.push({0,s});
	vis[s]=1;
	bool ook=1;
	while(!pq.empty())
	{
		int u=pq.top().second;
		if(ook)
		{
			path.push_back(u);
		}
		if(u==e)
		{
			ook=0;
		}
		
		pq.pop();
		for(node x:g[u])
		{
			if(vis[x.to])
			{
				continue;
			}
			int dd=x.w;
			vis[x.to]=1;
			if(dist[u]+dd<dist[x.to])
			{
				dist[x.to]=dist[u]+dd;
				pq.push({dist[x.to],x.to});
			}
		}
	}
	
	for(int z=1;z<path.size()-1;z++)
	{
		int r=path[z];
		if(!huanc[r])
		{
			for(int i=1;i<=n;i++)
			{
				if(ym[i][r])
				{
					dist[e]-=(2*t[i][r]);
				}
			}
		}
	
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
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
			cin>>a[i][j];//第几条线经过哪些站 
			ym[i][a[i][j]]=1;
			cin>>t[i][j];//这条线这个站台到站厅步行时间 
		}
		for(int j=1;j<k;j++)
		{
			int u=a[i][j];
			int v=a[i][j+1];
			int distt=t[i][j]+t[i][j+1];
			g[u].push_back({v,distt});
			g[v].push_back({u,distt});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int sss=0;
		for(int j=1;j<=n;j++)
		{
			if(ym[j][i])
			{
				sss++;
			}
		}
		if(sss>1)
		{
			huanc[i]=1;
		}
	}
	bool ok;
	for(int i=1;i<=q;i++)
	{
		ok=0;
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			if(ym[j][x]&&ym[j][y])
			{
				cout<<w[x]+w[y]+t[j][x]+t[j][y]<<"\n";
				ok=1;
				break;
			}
		}
		if(ok)
		{
			continue;
		}
		djstl(x,y);
		cout<<w[x]+w[y]+dist[y]<<"\n";
	}
	return 0;
}


