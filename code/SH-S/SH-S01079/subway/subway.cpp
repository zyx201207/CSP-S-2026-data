#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

const int maxn = 500+9;
const int maxm = 5e5+9;
const ll INF = 1e13;

int c,n,m,d,q;
ll dist[maxn][maxn];
ll w[maxm];

vector<pii> e[maxn+maxm];
priority_queue<pii> pq;

void init()
{
	for(int i=0;i<=n+5;++i)
	for(int j=0;j<=n+5;++j)
		dist[i][j]=INF;
		
	for(int i=0;i<=n+5;++i)
		dist[i][i]=0;
	
	for(int i=0;i<=n+m+5;++i)
		e[i].clear();
}

void solve()
{
	for(int i=n+1;i<=n+m;++i) //枚举地铁站 
	{
		for(int a=0;a<e[i].size();++a)
		for(int b=a+1;b<e[i].size();++b) //注意ab不是线路 
		{
			int u=e[i][a].first; 
			int v=e[i][b].first;
			ll w=e[i][a].second+e[i][b].second;
			//printf("solve i=%d u=%d v=%d w=%lld\n",i,u,v,w);
			dist[u][v]=min(dist[u][v],w);
			dist[v][u]=min(dist[v][u],w);
		}
	}
	
	//printf("dist 1,2 = %lld\n",dist[1][2]);
	
	//Floyd
	for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
	for(int k=1;k<=n;++k)
	{
		if(k==i||k==j)continue;
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); 
		dist[j][i]=min(dist[j][i],dist[i][k]+dist[k][j]); 
	}
	//printf("dist 1,2 = %lld\n",dist[1][2]);
}

ll query(ll x,ll y)
{
	x+=n; y+=n; //是站台
	 
	ll ans=INF;
	
	for(int a=0;a<e[x].size();++a) //S->a 
	for(int b=0;b<e[y].size();++b) //S->b
	{
		int u=e[x][a].first; 
		int v=e[y][b].first;
		ll w=e[x][a].second+e[y][b].second;
		//printf("query u=%d v=%d w=%lld dist=%lld\n",u,v,w,dist[u][v]);
		ans=min(ans,dist[u][v]+w); //注意这里到底要加什么 若线路 
	}
	
	return ans; //还原回来 
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;++i)
		scanf("%lld",&w[i]);
	
	init();
	
	ll k,v,t;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;++j)
		{
			scanf("%lld %lld",&v,&t);
			v+=n;
			e[i].push_back(mp(v,t)); //线的边 
			e[v].push_back(mp(i,t)); //地铁站的边 
		}
	}
	
	solve();
	
	ll xx,yy;	
	for(int r=1;r<=q;++r)
	{
		scanf("%lld %lld",&xx,&yy);
		printf("%lld\n",w[xx]+w[yy]+query(xx,yy));
	}
	
	return 0;
}
