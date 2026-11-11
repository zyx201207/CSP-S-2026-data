#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=2e4+5;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int c,n,m,d,q,w[N];
int dis[N];bool vis[505][N];
int ans,a[N],t[N];
struct edge{
	int u,v,w,ko;
}e[505][20005];
int cnt;
void add_edge(int kk,int u,int v,int w,int tok){
	e[kk][++cnt].u=u,e[kk][cnt].v=v,e[kk][cnt].w=w,e[kk][cnt].ko=kk;
}
void dij(int s,int k){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<pii,int> > q;
	dis[s]=0,q.push({{s,0},k});
	while(!q.empty()){
		pair<pii,int> tp=q.top();
		int kk=tp.sec;
		q.pop();
		if(vis[kk][tp.fir.fir]) continue;
		vis[kk][tp.fir.fir]=true;
//		for(auto i){
//			int v=i.fir,w=i.sec;
//			if(dis[v]>dis[tp.fir]+w){
//				dis[v]=dis[tp.fir]+w;
//				q.push({{v,dis[v]},k});
//			}
//		}
		for(int i=tp.fir.fir;i;i=e[kk][i].v){
			int v=e[kk][i].v,w=e[kk][i].w;
			if(dis[v]>dis[tp.fir.fir]+w){
				dis[v]=dis[tp.fir.fir]+w;
				q.push({{v,dis[v]},e[kk][v].ko});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++) a[j]=read(),t[j]=read();
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				add_edge(k,a[j],a[l],t[j],k),add_edge(k,a[l],a[j],t[l],k);
			}
		}
	}
//	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int i=1;i<=m;i++){
					if(e[j][i].u==e[k][i].u){
						add_edge(j,e[j][i].u,e[k][i].u,e[j][i].w+e[k][i].w,k);
						add_edge(k,e[j][i].u,e[k][i].u,e[j][i].w+e[k][i].w,j);
					}
				}
			}
		}
//	}
	while(q--){
		int x=read(),y=read();
		for(int i=1;i<=n;i++){
			if(e[i][x].u!=0) dij(x,i);
		}
		cout<<dis[y]+w[x]+w[y]<<"\n"; 
	}
	return 0;
}

