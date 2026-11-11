#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,Q=1e5+10,mod=998244353,inf=1e12;
int c,n,m,d,que;
int p[N];
vector<pii>q[N],e[N];
int ans[Q];
int dis[N];
bool vis[N];
void dij(int s){
	for(int i=1;i<=m+n;i++)dis[i]=inf,vis[i]=0;
	priority_queue<pii>q;
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		auto [d,u]=q.top();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto &[v,w]:e[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>que;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	int k,v,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>t;
			e[m+i].push_back({v,t});
			e[v].push_back({m+i,t});
		}
	}
	for(int i=1;i<=que;i++){
		cin>>k>>v;
		if(k>v)swap(k,v);
		q[k].push_back({v,i});
	}
	for(int u=1;u<=m;u++){
		if(q[u].size()){
			dij(u);
			for(auto &[y,i]:q[u])
				ans[i]=dis[y]+p[u]+p[y];
		}
	}
	for(int i=1;i<=que;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
/*
problem illustration so good,even a devil may cry

16:00
dij
O(n^2*(n+m)*d)
<40pts
*/