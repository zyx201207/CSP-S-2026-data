#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c,n,m,d,q,bu[N],st;
int dis[N][N],vis[N],rot[N][N];
vector< pair<int,int> > v[N*3];
void dijk(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
	memset(dis,0x3f,sizeof(dis));
	dis[s][s]=0;
	q.push({0,s});
	while(q.size())
	{
		int u=q.top().first;
		int w=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto g:v[u])
		{
			
			if(dis[g]>dis[u]+w)
			{
				dis[g]=dis[u]+w;
				q.push({dis[g],g});
			}
		}
	}
}
signed main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>pf[i];
		v[i].push_back({i+n,pf[i]});
		v[i+n].push_back({i,pf[i]});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		for(int j=1;j<=num;j++)
		{
			int x,y;cin>>x>>y;
			v[x+n].push_back({i+2n,y});
			rot[i][j]=x;val[i][j]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=num[i];j++)
		{
			v[rot[i][j]+n].push_back({rot[i][j]+4n,val[i][j]});
			v[rot[i][j]+4n].push_back({rot[i][j]+n,val[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=num[i];j++)
		{
			v[rot[i][j]].push_back({{val[i][j],i},rot[i][j+1]})
		}
	}
	for(int i=1;i<=m;i++) dijk(i);
	for(int i=1;i<=q;i++)
	{
		cin>>st>>end;
		cout<<dis[st][end]<<"\n";
	} 
	return 0;
}
