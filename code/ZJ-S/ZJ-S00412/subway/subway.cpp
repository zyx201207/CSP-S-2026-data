#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005,maxm=505,maxd=25,INF=1ll<<60,TT=500000,ALLNODE=1000005;
int c,n,m,d,q,w[maxn],ans[100005];
int N,lnk[ALLNODE],tot,dis[ALLNODE],que[ALLNODE],hed,til;
bool vis[ALLNODE];
struct edge{
	int nxt,to,w;
}e[ALLNODE*2];
struct Que{
	int x,y,id;
	bool operator<(const Que&B)const{return x<B.x;}
}Q[100005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
void add_e(int x,int y,int z){
	e[++tot]={lnk[x],y,z};
	lnk[x]=tot;
}
void add(int &x){
	x=(x+1)%TT;
}
void spfa(int st){
	for(int i=1;i<=N;i++) dis[i]=INF;
	hed=0;til=1;
	que[1]=st;dis[st]=0;
	while(hed!=til){
		add(hed);
		int u=que[hed];
		vis[u]=0;
		for(int i=lnk[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]<=dis[u]+e[i].w) continue;
			dis[v]=dis[u]+e[i].w;
			if(vis[v]) continue;
			vis[v]=1;
			add(til);int tmp=hed;add(tmp);
			que[til]=v;
			if(dis[que[tmp]]>dis[v]) swap(que[tmp],que[til]);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();m=read();n=read();d=read();q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	N=n+m;
	for(int i=1;i<=m;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int id=read(),t=read();
			add_e(id,n+i,t);
			add_e(n+i,id,t);
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		if(x>y) swap(x,y);
		Q[i]={x,y,i};
	}
	sort(Q+1,Q+q+1);
	int now=0;
	for(int i=1;i<=q;i++){
		if(Q[i].x!=now){
			now=Q[i].x;
			spfa(now);
		}
		ans[Q[i].id]=w[Q[i].x]+w[Q[i].y]+dis[Q[i].y];
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}