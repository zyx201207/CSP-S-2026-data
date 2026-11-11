#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a,t;
};
long long c,n,m,d,qu;
long long w[500005];
long long kl[505];
vector<Node> l[505];
vector<pair<long long,long long>> g[500005];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
long long dist[500005];
bool vis[500005];
void Dij(long long x){
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	q.push({0,x});
	dist[x]=0;
	while(!q.empty()){
		pair<long long,long long> top=q.top();
		q.pop();
		long long u=top.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<long long,long long> i:g[u]){
			long long x=i.first;
			long long y=i.second;
			if(dist[x]>dist[u]+y){
				dist[x]=dist[u]+y;
				q.push({dist[x],x});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kl[i];
		for(int j=1;j<=kl[i];j++){
			long long a,t;
			cin>>a>>t;
			l[i].push_back({a,t});
		}
		for(int j=0;j<kl[i];j++){
			for(int k=j+1;k<kl[i];k++){
				long long u=l[i][j].a,v=l[i][k].a,w=l[i][j].t+l[i][k].t;
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	for(int i=1;i<=qu;i++){
		long long x,y;
		cin>>x>>y;
		Dij(x);
		cout<<dist[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
