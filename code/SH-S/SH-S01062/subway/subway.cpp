#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e4+10;
long long c,n,m,d,q,a[N],s,t,u,v,k,w,w1,w2,dis[N];
vector<pair<long long,long long>> g[N]; 
priority_queue<pair<long long,long long>> pq;
bool book[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>k>>u>>w1;
		for(int i=1;i<k;i++){
			cin>>v>>w2;
			g[u].push_back({v,w1+w2});
			g[v].push_back({u,w1+w2});
			if(w1!=w2) flag=0; 
		}
	}
	while(q--){
		cin>>s>>t;
		for(int i=1;i<=m;i++){
			dis[i]=1e18;
			book[i]=0;
		}
		pq.push({0,s});
		dis[s]=0;
		while(pq.size()){
			u=pq.top().second;
			pq.pop();
			if(book[u]) continue;
			book[u]=1;
			for(auto t:g[u]){
				v=t.first,w=t.second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push({-dis[v],v});
				}
			}
		}
		if(flag==1) cout<<dis[t]+a[s]+a[t]-w1-w2<<"\n";
		else cout<<dis[t]+a[s]+a[t]<<"\n";
	}
	return 0;
} 



