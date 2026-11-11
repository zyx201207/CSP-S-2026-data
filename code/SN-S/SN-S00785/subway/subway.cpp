//SN-S00785
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,dis[500005],vis[505],w[505],t;
struct edge{
	long long to,w;
};
vector<edge> e[500005];
struct node{
	long long d,id;
};
operator<(const node &x,const node &y){
	return x.d>y.d;
}
void dijkstra(int s){
	priority_queue<node> q;
	for(int i=1;i<=m;i++){
		dis[i]=1e9;		
	}
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		auto noww=q.top();
		q.pop();
		long long d=noww.d;
		int id=noww.id;
		if(vis[id]){
			continue;
		}
		vis[id]=1;
		for(auto it:e[id]){
//			cout<<2<<endl;
			long long v=it.to;
			long long w=it.w;
//			cout<<v<<" "<<id<<" "<<dis[v]<<" "<<dis[id]<<endl;
			if(dis[v]>dis[id]+w){
				dis[v]=dis[id]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int u,last=0,a;
		cin>>u;
		for(int j=1;j<=u;j++){
			cin>>a>>t;
			if(last){
				e[a].push_back({last,t*2});
				e[last].push_back({a,t*2});
			}
			last=a;
		}
	}
	while(Q--){
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]-t+w[x]+w[y]<<endl;
	}
	return 0;
}
