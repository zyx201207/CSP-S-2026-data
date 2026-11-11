#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=505,M=2e6+5,K=5e5+505;
int c,n,m,d,q,w[K],k[N],nex[M],fir[M],las[M],cnt,e[M],x,y,u,v;
bool vis[K];
int dis[K],f[N][N],mi;
struct SC{
	int x;
	int dis;
};
bool operator <(const SC &a,const SC &b){
	return a.dis>b.dis;
}

void add(int x,int y,int z){
	nex[++cnt]=y,e[cnt]=z,las[cnt]=fir[x],fir[x]=cnt;
}
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while( isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
	return res*f; 
}
void dij(int l){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<SC> p;
	p.push((SC){l,0});
	dis[l]=0;
	while(!p.empty()){
		u=p.top().x;
		p.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=fir[u];i;i=las[i]){
			v=nex[i];
			if(dis[v]>dis[u]+e[i]){
				dis[v]=dis[u]+e[i];
				p.push((SC){v,dis[v]});
			}
		}
	}
	return ;
}
int getans(int x,int y){
	mi=(1<<30);
	for(int i=fir[x];i;i=las[i]){
		u=nex[i]-m;
		for(int j=fir[y];j;j=las[j]){
			v=nex[j]-m;
			mi=min(mi,f[u][v]+e[i]+e[j]);
		}
	}
	return mi;
}
void bfs(int l){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	queue<int> p;
	dis[l]=0;
	p.push(l);
	while(!p.empty()){
		u=p.front();
		p.pop();
		vis[u]=1;
		for(int i=fir[u];i;i=las[i]){
			v=nex[i];
			if(!vis[v]){
				dis[v]=dis[u]+e[i];
				vis[v]=1;
				p.push(v);
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			x=read(),y=read();
			add(m+i,x,y);
			add(x,m+i,y);
		}
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			bfs(i+m);
			for(int j=1;j<=n;j++){
				f[i][j]=dis[j+m];
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			dij(i+m);
			for(int j=1;j<=n;j++) f[i][j]=dis[j+m];
		}
	}
	while(q--){
		x=read(),y=read();
		printf("%lld\n",getans(x,y)+w[x]+w[y]);
	}
	return 0;
} 
