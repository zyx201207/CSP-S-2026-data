#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int l;
	ll t;
};
const ll INF=1LL<<62;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll>w(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	vector<vector<Node>>node(m+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int a;ll t;
			cin>>a>>t;
			node[a].push_back({i,t});
		}
	} 
	
	vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=node[i].size();
		if(sz==1)continue;
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++){
				if(j==k)continue;
				int u=node[i][j].l,v=node[i][k].l;
				ll w=node[i][j].t+node[i][k].t;
				dist[u][v]=w;
				dist[v][u]=w;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dist[i][k]==INF)continue;
			for(int j=1;j<=n;j++){
				if(dist[k][j]==INF)continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1LL<<62;
		for(Node ndx:node[x]){
			for(Node ndy:node[y]){
				ll curw=ndx.t+ndy.t;
				int lx=ndx.l,ly=ndy.l;
				curw+=dist[lx][ly]+w[x]+w[y];
				ans=min(ans,curw);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
