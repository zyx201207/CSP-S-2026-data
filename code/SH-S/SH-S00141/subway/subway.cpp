#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;

ll c,n,m,dd,q,w[500004],d[20003];
vector<pair<int,ll>> g[20004];
ll di[1004][1004];

ll dij(int s,int e){
	bitset<20004> vis;
	vis.reset();
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,s});
	d[s]=0;
	while(!pq.empty()){
		auto _=pq.top();
		pq.pop();
		int u=_.second;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto nxt:g[u]){
			ll v=nxt.first,w=nxt.second;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				if(v==e){
					return d[v];
				}
				pq.push({d[v],v});
			}
		}
	}
}

void dij2(int s){
	bitset<20004> vis;
	vis.reset();
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,s});
	d[s]=0;
	while(!pq.empty()){
		auto _=pq.top();
		pq.pop();
		int u=_.second;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto nxt:g[u]){
			ll v=nxt.first,w=nxt.second;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				pq.push({d[v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		vector<int> ki(k+1);
		vector<int> a(k+1);
		for(int j=1;j<=k;j++){
			cin>>a[j]>>ki[j];
		}
		for(int j=1;j<=k;j++){
			for(int x=j+1;x<=k;x++){
				g[a[j]].push_back({a[x],ki[j]+ki[x]});
				g[a[x]].push_back({a[j],ki[j]+ki[x]});
			}
		}
	}
	if(c>=9&&c<=12){
		for(int i=1;i<=n;i++){
			dij2(i);
			for(int j=1;j<=n;j++){
				di[i][j]=d[j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(c>=9&&c<=12) cout<<di[x][y]+w[x]+w[y]<<'\n';
		else cout<<dij(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}
