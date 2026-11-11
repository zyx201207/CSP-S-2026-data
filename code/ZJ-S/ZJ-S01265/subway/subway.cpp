#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
int n,m,c,d,q,x,y;
long long w[M],a,t,k[N],dis[N][N],f[N][N],minn,ans;
bool vis[N];
struct node{
	long long pos,ti;
};
struct node2{
	long long pos,ti;
	bool operator< (const node2 &x) const{
		return ti>x.ti;
	}
};
vector<node> v1[M],v2[N],v3[N];
priority_queue<node2>qu;
void dij(int s)
{
	for(int i=1;i<=n;++i)
	  vis[i]=0;
	vis[s]=1;
	f[s][s]=0;
	qu.push((node2){s,0});
	while(!qu.empty())
	{
		int tt=qu.top().pos;
		vis[tt]=1;
		qu.pop();
		for(int i=0;i<v3[tt].size();++i)
		{
			int v=v3[tt][i].pos,w=v3[tt][i].ti;
			if(vis[v]) continue;
			if(f[s][tt]+w<f[s][v])
			{
				f[s][v]=f[s][tt]+w;
				qu.push((node2){v,f[s][v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	  {
	  	f[i][j]=dis[i][j]=1e18;
		if(i==j) dis[i][i]=0;
	  }
	for(int i=1;i<=m;++i)
	  cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>a>>t;
			v2[i].push_back((node){a,t});
			v1[a].push_back((node){i,t});
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<v1[i].size();++j)
		  for(int k=j+1;k<v1[i].size();++k)
		  {
		  	int t1=v1[i][j].pos,t2=v1[i][k].pos;
		  	dis[t1][t2]=min(dis[t1][t2],v1[i][j].ti+v1[i][k].ti);
		  	dis[t2][t1]=dis[t1][t2];
		  }
	}
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	  	if(dis[i][j]!=1e18&&i!=j) v3[i].push_back((node){j,dis[i][j]});
	for(int i=1;i<=n;++i)
	{
		dij(i);
	}
	while(q--)
	{
		cin>>x>>y;
		minn=1e18;
		for(int i=0;i<v1[x].size();++i)
		  for(int j=0;j<v1[y].size();++j)
		  {
		  	int t1=v1[x][i].pos,t2=v1[y][j].pos,t3=v1[x][i].ti,t4=v1[y][j].ti;
		  	minn=min(minn,t3+t4+f[t1][t2]);
		  }
		ans=minn+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
