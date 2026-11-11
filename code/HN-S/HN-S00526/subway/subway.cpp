#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
const int N = 5e5 + 10,INF = 1e18;
int w[N];
struct Nod{
	int v,w;
};
int a[N][25],k[N];
int E[510][510],dis[510][510],t[N][20];
vector<Nod> e[N];
bool vis[510];

void bfs(int x)
{
	priority_queue<PII,vector<PII >,greater<PII > > q;
	q.push({0,x});
	dis[x][x] = 0;
	while(!q.empty())
	{
		int ans = q.top().first,t = q.top().second;
		q.pop();
		if(dis[x][t] < ans)continue;
		for(int i = 0 ; i < e[t].size() ; i++)
		{
			int v = e[t][i].v,w = e[t][i].w;
			if(dis[x][v] > ans + w)
			{
				dis[x][v] = ans + w;
				q.push({dis[x][v],v});
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1 ; i <= m ; i++)cin>>w[i];
	for(int i = 1 ; i <= n ; i++)
	{
		int l,x,tt;
		cin>>l;
		for(int j = 1 ; j <= l ; j++)
		{
			cin>>x>>tt;
			k[x]++;
			a[x][k[x]] = i,t[x][k[x]] = tt;
		}
	}
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			E[i][j] = dis[i][j] = INF;
	for(int i = 1 ; i <= m ; i++)
	{
		if(k[i] == 1)continue;
		for(int j = 1 ; j <= k[i] ; j++)
			for(int p = 1 ; p <= k[i] ; p++)
			{
				int x = a[i][j],y = a[i][p];
				E[x][y] = E[y][x] = min(E[x][y],t[i][j] + t[i][p]);
			}
	}
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			if(E[i][j] != INF)e[i].push_back({j,E[i][j]});
		}
	for(int i = 1 ; i <= n ; i++)bfs(i);			
	while(q--)
	{
		int st,ed,ans = INF;
		cin>>st>>ed;
		for(int i = 1 ; i <= k[st] ; i++)
			for(int j = 1 ; j <= k[ed] ; j++)
			{
				int x = a[st][i],y = a[ed][j];
				ans = min(ans,t[st][i] + t[ed][j] + dis[x][y]);
			}
		ans += w[st] + w[ed];
		cout<<ans<<endl;
	}
	return 0;
 } 
