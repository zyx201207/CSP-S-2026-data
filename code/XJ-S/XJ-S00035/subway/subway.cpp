#include<iostream> 
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=505,M=5e5+5;
const long long Nl=505,Ml=5e5+5;
int c,n,m,d,q,vis[N];
long long w[M],dis[N][N];
struct node{
	int line;
	long long time;
};
vector<node> fp[M];
queue<int> qq;
void floyed(int st)
{
	qq.push(st);
	while(qq.size())
	{
		int u=qq.front();
		qq.pop();
		vis[u]=1;
		for(int v=1;v<=n;v++)
		{
			if(dis[u][v]==922337203685477||u==v) continue;
			if(vis[v]&&dis[st][u]+dis[u][v]>=dis[st][v]) continue;
			dis[st][v]=dis[st][u]+dis[u][v];
			qq.push(v);
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k,u,v;
	long long t;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>u>>t;
			node T;
			T.line=i;
			T.time=t;
			fp[u].push_back(T); 
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) dis[i][j]=922337203685477;
	}
	for(i=1;i<=n;i++) dis[i][i]=0;
	for(i=1;i<=m;i++)
	{
		for(auto x:fp[i])
		{
			for(auto y:fp[i])
			{
				if(x.line==y.line) continue;
				dis[x.line][y.line]=min(dis[x.line][y.line],x.time+y.time);
				dis[y.line][x.line]=min(dis[y.line][x.line],x.time+y.time);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		vis[i]=1;
		while(qq.size()) qq.pop();
		floyed(i);
	}
	while(q--)
	{
		cin>>u>>v;
		long long ans=Nl*Ml;
		for(auto x:fp[u])
		{
			for(auto y:fp[v]) ans=min(ans,x.time+y.time+dis[x.line][y.line]);
		}
		ans+=w[u];
		ans+=w[v];
		cout<<ans<<endl;
	}
	return 0;
}
