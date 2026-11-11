#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c,n,m,d,q,dis[N],vis[N],w[N];
struct node{
	int v,w;
};
vector<node> g[N];
struct edge{
	int dis,pos;
	bool operator<(const edge&x)const{
		return x.dis<dis;
	}
};
void dj(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<edge> q;
	q.push({0,st});
	dis[st]=0;
	while(q.size()>0) {
		int tmp=q.top().pos;
		q.pop();
		if(vis[tmp]==1){
			continue;
		}
		for(int i=0;i<g[tmp].size();i++) {
			int v=g[tmp][i].v,w=g[tmp][i].w;
			if(dis[v]>dis[tmp]+w){
				dis[v]=dis[tmp]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int val,lp=0;
		cin>>val;
		for(int j=1;j<=val;j++){
			int u,z;
			cin>>u>>z;
			if(j==1){
				lp=u;
			}
			else{
				g[lp].push_back({u,z+w[u]});	
				g[u].push_back({lp,z+w[lp]});
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dj(u);
		cout<<dis[v]<<endl;
	}
	return 0;
}


