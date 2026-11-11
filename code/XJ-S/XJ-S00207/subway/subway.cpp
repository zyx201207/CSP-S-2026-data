#include<bits/stdc++.h>
using namespace std;
const int N=5e5+510;
typedef long long ll;
struct Node{
	ll v,w;
	bool operator<(const Node& other) const{
		return this->w > other.w ;
	}
};
vector<Node> Q[N];
ll c,n,m,d,q;
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			Q[a].push_back({m+i,t});
			Q[m+i].push_back({a,t});
		}
	}
	for(int t=1;t<=q;t++){
		int x,y;
		cin>>x>>y;
		vector<ll> dij(n+m+1),vis(n+m+1);
		for(int i=1;i<=n+m;i++){
			if(i!=x){
				dij[i]=INT_MAX;
			}
		}
		priority_queue<Node> q;
		q.push({x,0});
		while(!q.empty()){
			int u=q.top().v;
			q.pop();
			vis[u]=1;
			ll len=Q[u].size();
			for(int i=0;i<len;i++){
				int v=Q[u][i].v;
				if(vis[v]==0){
					dij[v]=min(dij[v],dij[u]+Q[u][i].w);
					q.push({v,dij[v]});
				}
			}
		}
		
		cout<<w[x]+w[y]+dij[y]<<'\n';
	}
	
}
