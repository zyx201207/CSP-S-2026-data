#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
long long w[N];
int t[505][505];
int a[505][505];
int k[505];
struct node{
	int v;
	long long w;
};
vector <node> g[505];
bool operator < (node x,node y){
	return x.w>y.w;
}
long long dis[N];
int vis[N];
void solve(){
	priority_queue <node> pq;
	int s,e;
	cin>>s>>e;
	for(int i=1; i<=m; i++) dis[i]=1e18,vis[i]=0;
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty()){
		node u=pq.top();
		pq.pop();
//		cout<<u.v<<" ";
		for(auto it:g[u.v]){
			int v=it.v;
			long long w=it.w;
			if(vis[v]) continue;
			vis[v]=1;
//			if(v==3) cout<<111<<" "<<w<<" ";
			if(dis[u.v]+w<dis[v]){
//				if(v==3) cout<<v<<" "<<111<<":"<<w<<" ";
				dis[v]=dis[u.v]+w;
//				cout<<dis[v]<<" ";
				pq.push({v,dis[v]});
			}
		}
	}
	cout<<dis[e]+w[s]+w[e]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<111;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		cin>>k[i];
		for(int j=1; j<=k[i]; j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int uu=1; uu<=k[i]; uu++){
			for(int vv=uu+1; vv<=k[i]; vv++){
				int u=a[i][uu],v=a[i][vv];
				long long w=t[i][uu]+t[i][vv];
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	while(q--){
		solve();
//		cout<<'\n';
	}
	return 0;
}
