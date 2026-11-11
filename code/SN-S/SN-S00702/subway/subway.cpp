#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
vector<int> dian[N];
int w[N];
int ti;
vector<pair<int,int> > g[N];
int ans[N];
bool vis[N];
struct Node{
	int u,dis;
	bool operator<(Node a)const{
	    return dis>a.dis;
	}
};
const int inf=LLONG_MAX;
void dij(int s){
	for(int i=1;i<=m;i++){
		ans[i]=inf;
		vis[i]=false;
	}
	ans[s]=0;
	priority_queue<Node> que;
	que.push({s,0});
	while(!que.empty()){
		int u=que.top().u,dis=que.top().dis;
		que.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:g[u]){
			if(vis[v.first])continue;
			if(ans[v.first]>ans[u]+v.second){
				ans[v.first]=ans[u]+v.second;
				que.push({v.first,ans[v.first]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int ld=0;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			if(ld!=0){
				g[a].push_back({ld,0});
				g[ld].push_back({a,0});
				dian[a].push_back(ld);
				dian[ld].push_back(a);
			}
			int tim;
			cin>>tim;
		    ti=tim;
		}
	}
	for(int i=1;i<=n;i++){
		for(int d1:dian[i]){
			for(int d2:dian[i]){
				if(d1==d2)continue;
				g[d1].push_back({d2,1});
				g[d2].push_back({d1,1});
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s);
//		cout<<ans[t]*ti<<"\n";
        cout<<ans[t]*ti*2+w[s]+w[t]<<"\n";
	}
	return 0;
}
