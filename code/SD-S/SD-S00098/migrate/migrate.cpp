#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define ROF(i,x,y) for(int i=(x);i>=(y);i--)
#define EDGE(i,u) for(int i=head[u];~i;i=e[i].nxt)
#define pb push_back 
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
int read(){
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}

const int N=2e6+5;

// Oct31==Dec25?

int f1[N],f2[N],a[N],far[N],sum[N],dis[N],vis[N],cn[N];

int head[N],cnt;
struct edge{
	int v,w,nxt;
}e[N];
void add_edge(int u,int v,int w){
	e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=head[u],head[u]=cnt;
}

struct node{
	int dis,u;
	bool operator> (const node a) const{return dis>a.dis;}
};

void dij(int s,int n){
	priority_queue<node,vector<node>,greater<node>> q;
	FOR(i,1,n) dis[i]=INF,vis[i]=0,cn[i]=0;
	dis[s]=0,cn[s]=1;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		EDGE(i,u){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cn[v]=cn[u];
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+w){
				cn[v]+=w;
			}
		}
	}
}

void solve(){
	int n=read(),d=read();
	FOR(i,1,n) head[i]=-1;cnt=0;
	FOR(i,1,n) f1[i]=f2[i]=far[i]=0;
	FOR(i,1,n){
		a[i]=read();
	}
	int r=n;
	ROF(i,n,1){
		while(a[r]-a[i]>d) r--;
		far[i]=r;
	}
	int ans=0;
	ROF(i,n,1){
		FOR(j,i+1,far[i]) add_edge(i,j,1);
		dij(i,n);
		FOR(j,i,n) if(cn[j]==2) ans++;
	}
	print(ans),putchar('\n');
	//FOR(i,1,n) cout<<far[i]<<' ';
	//cout<<'\n';
//	ROF(i,n-1,1){
//		int rr=far[far[i]];
//		FOR(j,far[i],rr) sum[i]=0;
//		f1[i]+=far[i]-i;
//		int l=far[i];
//		FOR(j,i+1,far[i]){
//			int R=far[j];
//			if(R>l) sum[l+1]++,sum[R+1]--;
//		}
//		FOR(j,far[i]+1,rr){
//			sum[j]=sum[j-1]+sum[j];
//			if(sum[j]==1) f1[i]++,f2[i]+=f2[j];
//			if(sum[j]==2) f2[i]++,f2[i]+=f1[j];
//		}
//	}
//	int ans=0;
//	FOR(i,1,n) ans+=f2[i];
//	print(ans),putchar('\n');

	
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c=read(),t=read();
	while(t--) solve();
	
	return 0;
} 
