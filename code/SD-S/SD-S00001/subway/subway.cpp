#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[505],k[505],dis[500005];
vector<pair<int,int>>a[500005];vector<int>b[505];
void dij(int s,int t){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	for(int i=1;i<=m;i++)dis[i]=1e18;
	dis[s]=0;
	while(!q.empty()){
		auto e=q.top();q.pop();
		int u=e.second;
//		cout<<u<<"\n";
		for(auto g:a[u]){
			int x=g.first,v=g.second;
			for(int o:b[x]){
				if(dis[o]>dis[u]+v){
					dis[o]=dis[u]+v;
					q.push({dis[o],o});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			b[j].push_back(x);
			a[x].push_back({j,y});
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s,t);
		cout<<dis[t]+w[s]+w[t]<<"\n";
	}
	return 0;
}

