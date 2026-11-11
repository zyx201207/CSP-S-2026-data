#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=5e5+5;
vector<pair<int,int> > g[N];
bool vis[N];
int a[505][55],t[505][55],w[505];
ll dis[N];
void spfa(int x)
{
	queue<int> q;
	q.push(x);
	dis[x]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto v : g[u])
		{
			if(v.fi==u) continue;
			if(dis[v.fi]>dis[u]+v.se)
			{
				dis[v.fi]=dis[u]+v.se;
				if(!vis[v.fi]) q.push(v.fi),vis[v.fi]=1;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,l;
	cin>>c>>n>>m>>d>>l;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) 
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			
			g[a[i][j]].push_back({a[i][j]+i*m,t[i][j]});
			g[a[i][j]+i*m].push_back({a[i][j],t[i][j]});
			if(j>1)
			{
				g[a[i][j-1]+i*m].push_back({a[i][j]+i*m,0});
				g[a[i][j]].push_back({a[i][j]+i*m,t[i][j]});
			    g[a[i][j]+i*m].push_back({a[i][j],t[i][j]});
			}
		}
	}
	for(int i=1;i<=l;i++)
	{
		memset(dis,0x3f,sizeof(dis));
		int x,y;
		cin>>x>>y;
		spfa(x);
		ll ans=dis[y];
			
		ans=ans+(ll)w[x]+(ll)w[y];  
	    cout<<ans<<"\n";
	}
	return 0;
}
