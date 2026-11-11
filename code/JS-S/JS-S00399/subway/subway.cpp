#include<bits/stdc++.h>
using namespace std;
#define int long long
struct T{
	int c,d;
	bool operator<(const T &other)const{
		return d>other.d;
	}
};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1,0);
	for(int i=1;i<=m;i++)cin>>w[i];
	vector<vector<pair<int,int>>>edge(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k==2){
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			edge[a1].push_back({a2,t1+t2});
			edge[a2].push_back({a1,t1+t2});
		}else{
			int a1,t1;
			cin>>a1>>t1;
		}
	}
	vector<int>dis(n+1,1e9),vis(n+1,0);
	while(q--){
		int s,t;
		cin>>s>>t;
		priority_queue<T>pq;
		dis.assign(n+1,1e9);
		vis.assign(n+1,0);
		dis[s]=0;
		pq.push({s,0});
		while(!pq.empty()){
			int u=pq.top().c;
			pq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto x:edge[u]){
				int v=x.first,w=x.second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push({v,dis[v]});
				}
			}
		}
		cout<<dis[t]+w[s]+w[t]<<'\n';
	}
	return 0;
}
