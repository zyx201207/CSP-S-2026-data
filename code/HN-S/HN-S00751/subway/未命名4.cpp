#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

int idx,n,m,v,w,u,val[maxn],c,d,q,len,dist[maxn*2],ux,vx,lw;
bool vis[maxn*2];
map<int,int> g[maxn];

struct pts{
	int idx,dist;
	bool operator<(const pts&x)const{
		return x.dist<dist;
	}
};

void dijk(int x,int l){
	priority_queue<pts> q;
	for(int i=1;i<=idx;i++){
		vis[i]=0;
		dist[i]=0x3f3f3f3f;
	}
	dist[x]=0;
	q.push({x,0});
	while(!q.empty()){
		u=q.top().idx;
		q.pop();
		if(u==l){
			return;
		}
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(pair<int,int> t:g[u]){
			v=t.first,w=t.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({v,dist[v]});
			}
		}
	}
}

int main(){
	freopen("subway6.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	idx=m;
	for(int i=1;i<=n;i++){
		cin>>len;
		u=0;
		while(len--){
			cin>>v>>w;
			if(u){
				if(!g[u].count(v)){
					g[u][v]=w+lw;
					g[v][u]=w+lw;
				}else{
					g[u][v]=min(g[u][v],w+lw);
					g[v][u]=min(g[v][u],w+lw);
				}
			}else{
				u=v;
				lw=w;
			}
		}
	}
	while(q--){
		cin>>ux>>vx;
		dijk(ux,vx);
		cout<<dist[vx]+val[vx]+val[ux]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

