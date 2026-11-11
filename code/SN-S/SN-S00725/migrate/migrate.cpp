#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+10;
const int maxm=5e6+10;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++) 
inline ll read(){
	char c=getchar(); ll t=1,k=0;
	for(;'0'>c||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;'0'<=c&&c<='9';c=getchar()) k=k*10+(c^48);
	return t*k;
}
struct node{
	int nxt,v,w;
}edge[maxm];
int c,t,n,D,cnt,ans,head[maxn],dis[maxn],d[maxn],num[maxn];
ll x[maxn];bool vis[maxn];
inline void add(int u,int v){
	edge[++cnt].v=v;
	edge[cnt].w=1;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
#define pii pair<int,int>
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		if(n<=5e3){
			memset(dis,0x3f,sizeof dis);
			memset(d,0x3f,sizeof d);
			memset(vis,0,sizeof vis);
			memset(d,0,sizeof d);
			ans=0;
			n=read(),D=read();
			for(int i=1;i<=n;i++) x[i]=read();
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(x[j]-x[i]<=D) add(i,j);
			priority_queue<pii,vector<pii>,greater<pii> > que;
			dis[1]=0; vis[1]=1;
			que.push({dis[1],1});
			while(!que.empty()){
				int u=que.top().second; que.pop();
				vis[u]=0;
				for(int i=head[u];i;i=edge[i].nxt){
					int v=edge[i].v;
					if(dis[v]>dis[u]+edge[i].w){
						dis[v]=dis[u]+edge[i].w;
						if(!vis[v])
							que.push({dis[v],v}),vis[v]=1;
					}
				}
			}
			memset(vis,0,sizeof vis);
			d[1]=0; vis[1]=1;
			que.push({d[1],1});
			while(!que.empty()){
				int u=que.top().second; que.pop();
				vis[u]=0;
				for(int i=head[u];i;i=edge[i].nxt){
					int v=edge[i].v;
					if(d[v]>d[u]+edge[i].w){
						d[v]=d[u]+edge[i].w;
						if(d[v]==dis[u]) num[v]++;
						if(!vis[v])
							que.push({d[v],v}),vis[v]=1;
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(num[i]==2) ans++;
			printf("%d\n",ans);
		}else printf("0\n");	
	} 
	return 0;
}
