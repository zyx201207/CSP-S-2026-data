#include<bits/stdc++.h>
using namespace std;
int m,n,c,D,q,w[500005],vis[25100005],hd[2*25100005],ct,to[2*25100005],nx[2*25100005],d[2*25100005],k[500005];
long long dis[25100005];
struct node{
	int v,w;
	bool operator <(const node &B)const{
		return w>B.w;
	}
};
void add(int u,int vv,int w){
	d[++ct]=w;
	to[ct]=vv;
	nx[ct]=hd[u];
	hd[u]=ct;
}
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	priority_queue<node> q;
	q.push((node){s,0});
	while(!q.empty()){
		int x=q.top().v;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=hd[x];i;i=nx[i]){
			int y=to[i];
			if(vis[y]) continue;
			if(dis[y]>dis[x]+d[i]){
				dis[y]=dis[x]+d[i];
				q.push((node){y,dis[y]});
			}
		}
		if(x<=m*2) continue;
		for(int y=(x-1)/m*m+1;y<=(x-1)/m*m+k[(x-1)/m-1];y++){
			if(vis[y]||y==x) continue;
			if(dis[y]>dis[x]){
				dis[y]=dis[x];
				q.push((node){y,dis[y]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c){
		cin>>n>>m>>D>>q;
		ct=0;
		memset(hd,0,sizeof hd);
		memset(nx,0,sizeof nx);
		memset(to,0,sizeof to);
		memset(d,0,sizeof d);
		for(int i=1;i<=m;i++){
			cin>>w[i];
			add(i,i+m,w[i]);
			add(i+m,i,w[i]);
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int sta,t;
				cin>>sta>>t;
				add(m+m*i+j,sta+m,t);
				add(sta+m,m+m*i+j,t);
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			dij(x);
			printf("%lld\n",dis[y]);
		}
	}
    return 0;
}
