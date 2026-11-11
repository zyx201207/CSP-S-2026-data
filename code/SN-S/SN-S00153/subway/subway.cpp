//CSP-S 2026 B
//Last change time:18:23:05
//E(Points): 100
#include<bits/stdc++.h>
#define ps putchar(32)
#define el putchar(10)
using namespace std;
long long read(){
	long long f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return (f==1)?x:-x;
}
void write(long long x){
	if(x<0){putchar(45);x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const long long N=2e6+5,M=505,inf=LLONG_MAX/2;
long long c,n,m,d,q,cnt,head[N],w[N],k[N],vis[N],dis[M][M],dist[N],lk[M][M];
struct edge{long long to,nxt,val;}e[N];vector<pair<long long,long long> >g[N];
void add(long long u,long long v,long long w){e[++cnt]={v,head[u],w};head[u]=cnt;}
priority_queue<pair<long long,long long> >qu;
void dij(long long s){
	for(long long i=1;i<=n;i++)dist[i]=inf,vis[i]=0;
	qu.push({0,s});dist[s]=0;
	while(!qu.empty()){
		long long u=qu.top().second;qu.pop();
		if(vis[u])continue;vis[u]=1;
		for(long long i=head[u];i;i=e[i].nxt){
			long long v=e[i].to,w=e[i].val;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				qu.push({-dist[v],v});
			}
		}
	}for(long long i=1;i<=n;i++)dis[s][i]=dist[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(long long i=1;i<=m;i++)w[i]=read();
	for(long long i=1;i<=n;i++){
		k[i]=read();//polong long id:m+i
		for(long long j=1;j<=k[i];j++){
			long long a=read(),t=read();
			g[a].push_back({i,t});
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			lk[i][j]=inf;
	for(long long i=1;i<=m;i++){
		for(pair<long long,long long>x:g[i]){
			for(pair<long long,long long>y:g[i]){
				if(x.first<=y.first)break;
				long long u=x.first,v=y.first,w=x.second+y.second;
				lk[u][v]=min(lk[u][v],w);
				lk[v][u]=min(lk[v][u],w);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(lk[i][j]!=inf){
				add(i,j,lk[i][j]);
				add(j,i,lk[i][j]);
			}
		}
	}
	for(long long i=1;i<=n;i++)dij(i);
	while(q--){
		long long x=read(),y=read(),ans=inf;
		for(pair<long long,long long> u:g[x])
			for(pair<long long,long long> v:g[y])
				ans=min(ans,dis[u.first][v.first]+u.second+v.second);
		write(ans+w[x]+w[y]);el;
	}
	return 0;
}

