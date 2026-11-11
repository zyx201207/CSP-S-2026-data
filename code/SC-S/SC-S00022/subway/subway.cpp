#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+10,E=5e5+10,INF=1e9+7;
int n,m,c,d,q;
int k[N];
int a[N][M],t[N][M];
int w[M];
int dist[E];
bool st[E];
vector<int> z;
vector<pair<int,int> > e[E];
vector<int> nod;  
void dijkstra(int s){
	priority_queue<pair<int,int> > q;
	for(auto i:nod){
		dist[i]=INF;
		st[i]=false;
	}
	dist[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top.second;
		q.pop();
		if(st[u]) continue;
		st[u]=true;
		for(auto i:e[u]){
			int v=i.second,w=i.first;
			if(dist[v]>dist[u]+v){
				dist[v]=dist[u]+w;
				q.push({-dist[v],v});
			} 
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=6){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				z[a[i][j]].push_back(i);
				e[a[i][j]*1000+i].push_back(t[i][j],a[i][j]*1000+i);
				e[a[i][j]*1000+i].push_back({t[i][j],a[i][j]});
				nod.push_back(a[i][j]);
				nod.push_back(a[i][j]*1000+i);
			}
	
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i]-1;j++){
					e[a[i][j]].push_back({0,a[i][j+1]});
					e[a[i][j+1]].push_back({0,a[i][j]});
				}
			}
		}
		int ans,xr,yr;
		while(q--){
			cin>>xr>>yr;
			ans=w[xr]+w[yr];
			dijkstra(xr);
			ans+=dist[yr];
			cout<<ans<<endl;
		}
	}
	return 0;
}