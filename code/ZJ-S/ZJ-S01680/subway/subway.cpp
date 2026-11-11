#include<bits/stdc++.h>
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
const int maxm=5e5+5,maxd=25,maxn=505;
int n,m,d,Q,tot,lnk[maxn];
LL dis[maxn][maxn],G[maxn][maxn];
bool vis[maxn];
struct node{
	int cnt,to[maxd];
	LL x,w[maxd];
	void add(int x,LL y){cnt++;to[cnt]=x;w[cnt]=y;}
}a[maxm];
struct edge{
	int to,nxt;
	LL w;
}e[maxn*maxn*2];
struct QUE{
	int x;LL dis;
	bool operator<(const QUE&B)const{return dis>B.dis;}
};
priority_queue<QUE>que;
void add_e(int x,int y,LL z){e[++tot]={y,lnk[x],z};lnk[x]=tot;}
void Dijkstra(int s){
	memset(vis,0,sizeof(vis));
	que.push({s,0});dis[s][s]=0;
	while(!que.empty()){
		int x=que.top().x;que.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int j=lnk[x];j;j=e[j].nxt){
			if(dis[s][e[j].to]<=dis[s][x]+e[j].w)continue;
			dis[s][e[j].to]=dis[s][x]+e[j].w;
			if(!vis[e[j].to])que.push({e[j].to,dis[s][e[j].to]});
		}
	}
}
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int zyc_rp=read();zyc_rp++;
	n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++)a[i].x=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			int y=read();LL z=read();
			a[y].add(i,z);
		}
	}
	memset(G,0x3f,sizeof(G));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)if(a[i].cnt>1)for(int x=1;x<a[i].cnt;x++)for(int y=x+1;y<=a[i].cnt;y++)G[a[i].to[x]][a[i].to[y]]=min(G[a[i].to[x]][a[i].to[y]],a[i].w[x]+a[i].w[y]),G[a[i].to[y]][a[i].to[x]]=min(G[a[i].to[y]][a[i].to[x]],a[i].w[x]+a[i].w[y]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(j!=i&&G[i][j]!=INFLL)add_e(i,j,G[i][j]);
	for(int i=1;i<=n;i++)Dijkstra(i);
	while(Q--){
		int x=read(),y=read();LL ans=INFLL;
		for(int i=1;i<=a[x].cnt;i++)for(int j=1;j<=a[y].cnt;j++)ans=min(ans,dis[a[x].to[i]][a[y].to[j]]+a[x].x+a[y].x+a[x].w[i]+a[y].w[j]);
//		for(int i=1;i<=a[x].cnt;i++)for(int j=1;j<=a[y].cnt;j++)printf("%d %d %lld %lld %lld\n",a[x].to[i],a[y].to[j],dis[a[x].to[i]][a[y].to[j]],a[x].x+a[x].w[i],a[y].x+a[y].w[j]);
		printf("%lld\n",ans);
	}
//	printf("%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}