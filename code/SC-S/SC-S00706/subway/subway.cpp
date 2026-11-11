#include<bits/stdc++.h>
using namespace std;
const long long INF=1e16;
struct node{
	long long nxt;
	long long v;
	long long w;
}e[1000010];
long long head[500010],tot;
void add(long long u,long long v,long long w){
	tot++;
	e[tot].nxt=head[u];
	e[tot].v=v;
	e[tot].w=w;
	head[u]=tot;
}

struct pa{
	long long dis;
	long long pos;
	bool operator < (const pa &a) const{
		return a.dis<dis;
	}
};
priority_queue<pa> pq;
long long dis[500010],vis[500010];

long long c,n,m,d,q;
long long w[500010],K[500010];
void dij(long long s){
	for(long long i=0;i<=500005;i++){
		dis[i]=INF;
	}
	pa tmp;
	tmp.dis=0;
	tmp.pos=s;
	dis[s]=0;
	pq.push(tmp);
	
	while(!pq.empty()){
		tmp=pq.top();
		pq.pop();
		
		long long u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(long long i=head[u];i;i=e[i].nxt){
			long long v=e[i].v;
			long long w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					tmp.dis=dis[v];
					tmp.pos=v;
					pq.push(tmp);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(long long i=1;i<=n;i++){
		cin>>K[i];
		long long Id=0;
		for(long long j=1;j<=2*K[i];j++){
			if(j%2==1){
				cin>>Id;
			}
			else{
				long long t;
				cin>>t;
				add(Id,j/2+m+K[i]*(i-1),t);
				add(j/2+m+K[i]*(i-1),Id,t);
			}
		}
		for(int j=2;j<=K[i];j++){
			add(j+m+K[i]*(i-1),j+m+K[i]*(i-1)-1,0);
			add(j+m+K[i]*(i-1)-1,j+m+K[i]*(i-1),0);
		}
	}
	
	while(q--){
		memset(vis,0,sizeof(dis));
		long long x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}