#include<bits/stdc++.h>
#define lowbit ((x)&(-x))
#define ls(u) ((u)<<1)
#define rs(u) (((u)<<1)|1)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

const ll N=505,D=25,M=5e5+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
const double eps=1e-9;

vector<PII> g[N];
ll c,n,m,d,q,w[M],cnt[M],id[M][D],dis[M][D],dist[N][N],st[N];
//dis[i][j]为地铁站i内站台j到站厅的距离，id[i][j]为地铁站i内站台j所属地铁线，dist[i][j]为联通块i,j间的距离
void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII> >pq;
	dist[s][s]=0;
	memset(st,0,sizeof(st));
	pq.push({dist[s][s],s});
	while(pq.size()){
		int u=pq.top().se;pq.pop();
		st[u]=1;
		for(PII t:g[u]){
			int v=t.fi,w=t.se;
			if(st[v])continue;
			if(dist[s][v]>dist[s][u]+w){
				dist[s][v]=dist[s][u]+w;
				pq.push({dist[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k,a,t;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>a>>t;
			id[a][++cnt[a]]=i,dis[a][cnt[a]]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=id[i][j],v=id[i][k],w=dis[i][j]+dis[i][k];
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	while(q--){
		ll s,e,ans=INF;
		cin>>s>>e;
		for(int i=1;i<=cnt[s];i++){
			for(int j=1;j<=cnt[e];j++){
				ans=min(ans,dist[id[s][i]][id[e][j]]+dis[s][i]+dis[e][j]+w[s]+w[e]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
