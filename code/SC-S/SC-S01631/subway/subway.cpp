#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int c,n,m,d,q,T;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<vector<pii> > node(m+10);
	vector<int> w(m+10,0);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	if(c>=12&&c<=19){
		while(q--){
			int st,se,ok=0;
			cin>>st>>se;
			queue<pair<int,int> > qu;
			vector<int> dist(m+1,INT_MAX);
			qu.push({0,st});
			while(!qu.empty()){
				auto it=qu.front();
				qu.pop();
				int dis=it.first,u=it.second;
				for(auto nex:node[u]){
					int v=nex.first;
					if(dist[v]!=INT_MAX)
						continue;
					dist[v]=st+1;
					if(v==se){
						ok=1;
						break;
					}
					qu.push({dis+1,v});
				}
				if(ok)
					break;
			}
			cout<<dist[se]*T+w[st]+w[se]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> t(k+10,0),a(k+10,0);
		for(int l=1;l<=k;l++)
			cin>>a[l]>>t[l];
		T=t[1];
		for(int l=1;l<=k;l++){
			for(int j=l+1;j<=k;j++){
				node[a[l]].push_back({a[j],t[l]+t[j]});
				node[a[j]].push_back({a[l],t[l]+t[j]});
			}
		}
	}
	while(q--){
		int st,se;
		cin>>st>>se;
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		pq.push({0,st});
		vector<int> dist(m+10,INT_MAX),vis(m+10,0);
		while(!pq.empty()){
			auto it=pq.top();
			pq.pop();
			int u=it.second,dis=it.first;
			if(u==se)
				break;
			if(vis[u])
				continue;
			vis[u]=1;
			for(auto nex:node[u]){
				int v=nex.first,nw=nex.second;
				if(dis+nw<dist[v]){
					pq.push({dist[v]=dis+nw,v});
				}
			}
		}
		cout<<dist[se]+w[st]+w[se]<<'\n';
	}
}