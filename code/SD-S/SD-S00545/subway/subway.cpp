#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read(){
	register int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
	return res*f;
}
const int N=2e6+9,M=509;
struct edge{
	int next,to;
	ll w;
}e[N];
int head[N],cnt;
inline void add(int u,int v,ll w){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
}
int c,n,m,d,q,k[N];
ll w[N];
int b[N][25],num[N];
ll val[N][25];
struct node{
	int u;
	ll dis;
	bool operator <(const node &x)const{
		return dis>x.dis;
	}
};
ll dis[M][M];
bitset<M> vis;
void dij(int s){
	vis.reset();
	priority_queue<node> q;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[s][v]>dis[s][u]+e[i].w){
				dis[s][v]=dis[s][u]+e[i].w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x;
		ll y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			b[x][++num[x]]=i;
			val[x][num[x]]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			for(int p=j+1;p<=num[i];p++){
				ll wi=val[i][j]+val[i][p];
				add(b[i][j],b[i][p],wi);
				add(b[i][p],b[i][j],wi);
			}
		}
	}
	memset(dis,LINF,sizeof(dis));
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=LINF;
		for(int j=1;j<=num[x];j++){
			for(int p=1;p<=num[y];p++){
				ans=min(ans,dis[b[x][j]][b[y][p]]+val[x][j]+val[y][p]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

