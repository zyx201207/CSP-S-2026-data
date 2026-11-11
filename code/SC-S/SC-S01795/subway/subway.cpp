#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<vector<pair<ll,ll>>> g((n+m)*3);
	ll add1=m*2+5,add2=m+1;
	//第i个出站口对应第i+n个点，第i个站点对应第i个点；
	for(int i=1,w;i<=m;i++){
		cin>>w;
		g[i].push_back({w,i+add2});
		g[i+add2].push_back({w,i});
	}for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,v,d;j<=k;j++){
			cin>>v>>d;
			g[v].push_back({d,add1+i});
			g[add1+i].push_back({d,v});
		}
	}//迪杰斯特拉
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	while(q--){
		map<ll,ll>dist;
		map<ll,bool> visited;
		ll l,r;cin>>l>>r;
		l+=add2;r+=add2;
		dist[l]=0;
		pq.push({0,l});
		while(!pq.empty()){
			ll d=pq.top().first,u=pq.top().second;
			pq.pop();
			if(visited[u])continue;
			visited[u]=true;
			for(auto x:g[u]){
				if((dist[x.second]==0)||d+x.first<dist[x.second]){
					dist[x.second]=d+x.first;
					pq.push({dist[u]+x.first,x.second});
				}
			}
		}cout<<dist[r]<<"\n";
	}return 0;
	//O(q*nlog(m+n)*log(m+n));
}