#include<bits/stdc++.h>
using namespace std;
int C,n,m,d,T,w[500010];
vector<pair<int,int>> e[500510];
long long dijkstra(int x,int y){
	long long dist[m+n+1];
	memset(dist,0x3f,sizeof(dist));
	dist[x]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	q.push({0ll,x});
	while(q.size()){
		pair<long long,int> z=q.top();
		q.pop();
		if(dist[z.second]<z.first) continue;
		for(auto i:e[z.second]){
			if(z.first+i.second<dist[i.first]){
				if(i.first==y){
					return z.first+i.second;
				}
				dist[i.first]=z.first+i.second;
				q.push({z.first+i.second,i.first});
			}
		}
	}
	return dist[y];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<1ll*w[x]+w[y]+dijkstra(x,y)<<'\n';
	}
}
