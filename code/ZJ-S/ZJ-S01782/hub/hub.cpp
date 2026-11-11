#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e18;
int c,T,n,k,dis[1005][1005];
vector <int> tu[N];
bool vis[N];
int xs[N],t[N],ans=0;
bool check()
{
	int cnt=0;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=k;++i) 
	{
		vis[xs[i]]=1;bool mark=false;
		for(auto &v:tu[xs[i]]) if(vis[v]) mark=true;
		if(!mark) cnt++;
	}
	return (cnt<=2);
}
void dfs(int x,int nn,int cnt,int kk)
{
	if(x>nn)
	{
		if(cnt!=kk) return;
		if(!check()) return;
//		cout<<1;
		memset(t,0,sizeof(t));
//		for(int i=1;i<=cnt;++i) cout<<xs[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=cnt;++i) t[xs[i]]=1;
		int minn=INF,maxn=-1;
		for(int i=1;i<=n;++i)
		{
			if(t[i]) continue;
			for(int j=1;j<=cnt;++j) minn=min(minn,dis[i][xs[j]]);
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);return;
	}
	dfs(x+1,nn,cnt,kk);
	xs[cnt+1]=x;
	dfs(x+1,nn,cnt+1,kk);
	xs[cnt+1]=0;
}
void floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
signed main(void)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;ans=INF;
		for(int i=0;i<=n;++i) tu[i].clear();
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=INF;
		for(int i=1;i<=n;++i) dis[i][i]=0;
		for(int i=1;i<n;++i) 
		{
			int u,v;cin>>u>>v;
			tu[u].push_back(v);
			tu[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		floyd();dfs(1,n,0,k);
		cout<<ans<<"\n";
	}
}
