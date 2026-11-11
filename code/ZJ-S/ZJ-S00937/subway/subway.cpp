#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,w[500005],d[1000005],vis[1000005],k,a[505],t;
struct node{
	int v,w;
};
vector<node>e[1000005];

int dij(int x,int y){
	for(int i=1;i<=m*m;i++){
		d[i]=1e18;
		vis[i]=0;
	}
	d[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second;
		//cout<<u<<" "<<d[u]<<"\n";
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:e[u]){
			//cout<<" "<<v.v<<" "<<d[v.v]<<"\n";
			if(d[v.v]>d[u]+v.w){
				d[v.v]=d[u]+v.w;
				pq.push({d[v.v],v.v});
			}
		}
	}
	return d[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			e[a[j]+i*m].push_back({a[j],t});
			e[a[j]].push_back({a[j]+i*m,t});
		}
		for(int j=1;j<k;j++){
			e[a[j]+i*m].push_back({a[j+1]+i*m,0});
			e[a[j+1]+i*m].push_back({a[j]+i*m,0});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=dij(x,y)+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}