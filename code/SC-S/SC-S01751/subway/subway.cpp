#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=5e2+5;
vector<pair<int,int>>g[MAX*MAX<<1];
int c,n,m,d,q;
int Dj(int st,int ed){
	vector<int>dis(ed+1,INT_MAX);
	vector<bool>vis(ed+1,false);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
	vis[st]=true;
	dis[st]=0;
	q.push({st,0});
	while(q.size()){
		auto u=q.top();
		q.pop();
		vis[u.first]=true;
		for(auto v:g[u.first]){
			if(vis[v.first])continue;
			vis[v.first]=true;
			if(dis[v.first]>v.second+dis[u.first]){
				dis[v.first]=v.second+dis[u.first];
				q.push({v.first,dis[v.first]});
			}
		}
	}
	return dis[ed];
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].push_back({i+n*n+n,w});
		g[i+n*n+n].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int a,t,k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[i+n*i].push_back({j+n*i,0});
			g[j+n*i].push_back({i+n*i,0});
			g[i+n*i].push_back({i+n*n+n,t});
			g[i+n*n+n].push_back({i+n*i,t});
			g[j+n*i].push_back({j+n*n+n,t});
			g[j+n*n+n].push_back({j+n*i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<Dj(x,y)<<'\n';
	}
}
#undef int
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//  cin>>T;
	while(T--)solve();
	return 0;
}