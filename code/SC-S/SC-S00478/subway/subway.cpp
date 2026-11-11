#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=505,M=5e5+5;
int c,n,m,d,q;
int dis[N][N],midis[N][N],ldis[M],vis[N];
vector<pair<int,int>> a[M];
void dij(int s)
{
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;i++) vis[i]=0;
	q.push({0,s});
	midis[s][s]=0;
	while(q.size()>0)
	{
		int u=q.top().second;q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			if(i==u) continue;
			if(midis[s][u]+dis[u][i]<midis[s][i])
			{
				midis[s][i]=midis[s][u]+dis[u][i];
				q.push({midis[s][i],i});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=midis[i][j]=1e18;
	for(int i=1;i<=m;i++) cin>>ldis[i];
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=1;j<=x;j++)
		{
			int id,t;cin>>id>>t;
			a[id].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto j:a[i])
			for(auto k:a[i]) 
			{
				int x=j.first,y=k.first;
				dis[x][y]=min(dis[x][y],j.second+k.second);
			}
	for(int i=1;i<=n;i++) dij(i);
	while(q--)
	{
		int x,y,ans=1e18;cin>>x>>y;
		for(auto i:a[x])
			for(auto j:a[y]) ans=min(ans,midis[i.first][j.first]+i.second+j.second);
		cout<<ans+ldis[x]+ldis[y]<<"\n";
	}
} 