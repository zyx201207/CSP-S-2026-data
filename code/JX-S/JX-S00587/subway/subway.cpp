#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const long long INF=1e9+7;
int C,n,m,d,q,x,y;
int w[M];
long long dis[M+505];
bool vis[M+505];
vector<pair<int,long long> >e[M+505];
void dij(int x){
	priority_queue<pair<long long,int> >q;
	q.push({0,x});
	while(!q.empty()){
		pair<long long,int> r=q.top();
		q.pop();
		int v=r.second;
		if(vis[v]) continue;
		vis[v]=1;
		for(auto p:e[v]){
			int to=p.first,w=p.second;
			if(dis[to]>dis[v]+w){
				dis[to]=dis[v]+w;
				if(to==y) return ;
				q.push({-dis[to],to});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to;
			long long t;
			cin>>to>>t;
			e[i+m].push_back({to,t});
			e[to].push_back({i+m,t});
		}
	}
	while(q--){
		for(int i=1;i<=m+n;i++) vis[i]=0,dis[i]=INF;
		cin>>x>>y;
		dis[x]=0;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
