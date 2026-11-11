#include<bits/stdc++.h>

using namespace std;

const int MAXM=5e5+5;
const long long INF=0x3f3f3f3f3f3f3f3fLL;

struct edge{
	int v;
	long long w;
	bool operator<(const edge &other)const{
		return w>other.w;
	}
};
vector<edge> e[MAXM];

long long dist[MAXM];
bool vis[MAXM];

void dij(int s,int n){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<edge> pq;
	dist[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		edge t=pq.top();
		pq.pop();
		if(vis[t.v]) continue;
		vis[t.v]=1;
		for(auto &eg:e[t.v]){
			if(dist[eg.v]>dist[t.v]+eg.w){
				dist[eg.v]=dist[t.v]+eg.w;
				pq.push({eg.v,dist[eg.v]});
			}
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1,0);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k+1],t[k+1];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int p=1;p<=j;p++){
				e[a[p]].push_back({a[j],t[j]+t[p]});
				e[a[j]].push_back({a[p],t[j]+t[p]});
			} 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,m);
		cout<<w[x]+dist[y]+w[y]<<'\n';
	}
	
	return 0;
}
