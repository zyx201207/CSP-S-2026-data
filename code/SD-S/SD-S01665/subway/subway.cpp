#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define int long long
using namespace std;
bool Test_MLE_Start;
constexpr int N=605,M=1e4+10,K=25;
int _=1,CID,n,m,d,Q,tot[N],head[M][N],W[M],T[M][N],dis[M][N],vis[M][N];
struct edge{int v,nxt,w;}a[M<<2][N];
struct query{int st,ed,id,ans;}q[M];
struct node{
	int dis,id,v;
	friend bool operator <(const node A,const node B){return A.dis>B.dis;}
};priority_queue<node> qu;
bool Test_MLE_End;
inline int reads(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}inline void clr(){
//	Don't Forget!

}inline void files(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void add(int u,int v,int w,int id){
	a[++tot[id]][id].v=v;
	a[tot[id]][id].w=w;
	a[tot[id]][id].nxt=head[u][id];
	head[u][id]=tot[id];
}bool cmp1(query a,query b){return a.st==b.st?a.ed<a.ed:a.st<b.st;}
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[st][i]=T[st][i],qu.push(node{T[st][i],i,st});
	while(!qu.empty()){
		int u=qu.top().v,now=qu.top().id;
		qu.pop();
		if(vis[u][now]) continue;
		vis[u][now]=1;
		for(int i=head[u][now];i;i=a[i][now].nxt){
			int v=a[i][now].v;
			if(dis[v][now]>=dis[u][now]+a[i][now].w){
				dis[v][now]=dis[u][now]+a[i][now].w;
				qu.push(node{dis[v][now],now,v});
			}
		}for(int i=1;i<=n;i++){
			if(i!=now&&T[u][i]){
				if(dis[u][i]>=dis[u][now]+T[u][i]+T[u][now]){
					dis[u][i]=dis[u][now]+T[u][i]+T[u][now];
					qu.push(node{dis[u][i],i,u});
				}
			}
		}
	}
}bool cmp2(query a,query b){return a.id<b.id;}
signed main(){
//	printf("%lf\n",(&Test_MLE_End-&Test_MLE_Start+1)/1024.0/1024.0);
	files();
//	_=reads();
	while(_--){
		clr();CID=reads(),n=reads(),m=reads(),d=reads(),Q=reads();
		for(int i=1;i<=m;i++) W[i]=reads();
		for(int i=1;i<=n;i++){
			int k,lst=-1,ai,ti;k=reads();
			for(int j=1;j<=k;j++){
				ai=reads(),ti=reads();
				if(lst!=-1) add(lst,ai,0,i),add(ai,lst,0,i);
				T[ai][i]=ti;lst=ai;			
			}
		}for(int i=1;i<=Q;i++){
			int u,v;u=reads(),v=reads();
			q[i].st=min(u,v),q[i].ed=max(u,v),q[i].id=i,q[i].ans=0x3f3f3f3f;
		}sort(q+1,q+Q+1,cmp1);
		int lst=-1;
		for(int i=1;i<=Q;i++){
			if(q[i].st!=lst) dijkstra(q[i].st),lst=q[i].st;
			for(int j=1;j<=n;j++) q[i].ans=min(q[i].ans,W[q[i].st]+W[q[i].ed]+dis[q[i].ed][j]+T[q[i].ed][j]);
		}sort(q+1,q+Q+1,cmp2);
		for(int i=1;i<=Q;i++) printf("%lld\n",q[i].ans);
	}return 0;
}
/*
15:02 statement is so long! I can't understand! I don't have patient to read it!
15:06 I understand the statement
15:27 I think it can't accepted,but I don't have better choice,I will MLE or TLE!
16:56 I think only 24pts
17:06 Why RE?
*/
