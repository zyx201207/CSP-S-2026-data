#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,Q,a[N],dis[N],ans;
bool vis[N];
struct Node{
	int v,w;
};
vector<Node> f[N];
vector<Node> r[N];
vector<Node> g[N];
struct cmp{
	bool operator()(const Node& a,const Node& b){
		return a.w>b.w;
	}
};
priority_queue<Node,vector<Node>,cmp> q;
inline int read(){
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){k=k*10+(c^48);c=getchar();}
	return k*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();m=read();n=read();d=read();Q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		int op;
		op=read();
		for(int j=1;j<=op;j++){
			int x,y;
			x=read();y=read();
			f[x].push_back({i,y});
			r[i].push_back({x,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:f[i]){
			for(auto k:r[j.v]){
				if(i==k.v) continue;
				g[i].push_back({k.v,j.w+k.w});
				g[k.v].push_back({i,j.w+k.w});
			}
		}
	}
	while(Q--){
		for(int i=1;i<=n;i++){
			dis[i]=1e9;
			vis[i]=0;
		}
		int x,y;
		x=read();y=read();
		ans=a[x]+a[y];
		if(x==y){
			printf("0\n");
			continue;
		}
		dis[x]=0;
		q.push({x,0});
		while(!q.empty()){
			int u=q.top().v;
			q.pop();
			if(u==y){
				ans+=dis[y];
				printf("%d\n",ans);
				continue;	
			}
			if(vis[u]) continue;
			vis[u]=1;
			for(auto nu:g[u]){
				int nv=nu.v,nw=nu.w;
				if(dis[u]+nw<dis[nv]){
					dis[nv]=dis[u]+nw;		
					q.push({nv,dis[nv]});
				}
			}
		}
	}
	return 0;
}
