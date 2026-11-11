#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
const int inf=LLONG_MAX;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
} 
int n,m,q,w[N],idx;
int dis[N],s,t;
vector<pii>g[N];
map<pii,int>mp;
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	for(int i=1;i<=idx;i++)mp[{s,i}]=inf;
	mp[{s,s}]=0;q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		int w=q.top().first;
		q.pop();
		if(mp[{s,u}]<w)continue;
		for(auto p:g[u]){
			int v=p.first;
			int ww=p.second;
			if(w+ww<mp[{s,v}]){
				mp[{s,v}]=w+ww;
				q.push({mp[{s,v}],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fast_read();
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	idx=m;
	for(int i=1;i<=n;i++){
		int len;cin>>len;++idx;
		for(int j=1;j<=len;j++){
			int u,w;cin>>u>>w;
			g[u].push_back({idx,w});
			g[idx].push_back({u,w});
		}
	} 
	for(int i=1;i<=m;i++)dij(i);
	while(q--){
		cin>>s>>t;
		cout<<w[s]+w[t]+mp[{s,t}]<<'\n';
	}
	return 0;
}
