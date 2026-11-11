#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > g[500505];
long long dis[500505],w[500505],u,v,k,c,n,m,d,q,a,b;
void dijkstra(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pair<long long,int> p=q.top();
		q.pop();
		int u=p.second;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			long long d=g[u][i].second;
			if(dis[v]>dis[u]+d){
				dis[v]=dis[u]+d;
				q.push(make_pair(dis[v],v));
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>u>>v;
			g[u].push_back(make_pair(m+i,v));
			g[m+i].push_back(make_pair(u,v));
		}
	}
	while(q--){
		cin>>a>>b;
		dijkstra(a);
		cout<<dis[b]+w[a]+w[b]<<"\n";
	}
	return 0;
}
