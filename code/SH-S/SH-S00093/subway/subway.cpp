
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define PII pair<int,int>
long long c,n,m,d,qe,x,y;
int w[500005],k,t[505][25],dist[500005],vis[500005];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector <int> v[505];
vector <int> g[500005];
void mem(){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while(q.size()) q.pop();
} 
void dij(int u){
	q.push({0,u});
	dist[u]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto c:g[u]){
			for(auto k:v[c]){
				if(k==u) continue;
				if(dist[k]>dist[u]+t[c][u]+t[c][k]){
					dist[k]=dist[u]+t[c][u]+t[c][k];
					q.push({dist[k],k});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//int n,m;
	cin>>c>>n>>m>>d>>qe;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			cin>>t[i][x];
			v[i].push_back(x);
			g[x].push_back(i);
		}
		
	}
	for(int i=1;i<=qe;i++){
		cin>>x>>y;
		mem();
		dij(x);
		cout<<dist[y]+w[x]+w[y]<<"\n";
		//cout<<t[1][1]<<t[1][2]<<endl;
	}
} 

