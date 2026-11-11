#include<bits/stdc++.h>//32pts
#define int long long
using namespace std;
int c,n,m,d,q,cnt,lnk[500+1000005],dis[500+10000005],vis[500+1000005];
struct ZZL{
	int d,id;
	bool operator <(const ZZL &B)const{return d>B.d;}
}a[500+1000005];
struct edge{
	int to,w,nxt;
}e[3000005];
void add_e(int x,int y,int z){e[++cnt]=(edge){y,z,lnk[x]};lnk[x]=cnt;}
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void dijkstra(int st){
	for(int i=1;i<=n+2*m;i++)dis[i]=1e18;
	memset(vis,0,sizeof vis);
	priority_queue<ZZL> que;
	que.push((ZZL){0,st}),dis[st]=0;
	while(!que.empty()){
		int u=que.top().id;que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=lnk[u];i;i=e[i].nxt){
			if(dis[u]+e[i].w<dis[e[i].to]){
				dis[e[i].to]=dis[u]+e[i].w;
				que.push((ZZL){dis[e[i].to],e[i].to});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		int ww=read();
		add_e(i,m+i,ww);
		add_e(m+i,i,ww);
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int xx=read(),yy=read();
			add_e(i+2*m,m+xx,yy);
			add_e(m+xx,i+2*m,yy);
		}
	}
	while(q--){
		int sst=read(),eed=read();
		dijkstra(sst); 
		cout<<dis[eed]<<"\n";
	}
	return 0;
}
