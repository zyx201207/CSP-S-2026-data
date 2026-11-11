#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std; 
const int N=5e5+5;
int c,n,m,d,q,w[N],t[N],x[N],dis[N],vis[N];
vector<PII> g[N];
void dijk(int s){
	priority_queue<PII,vector<PII>,greater<PII>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({s,0});
	while(q.size()){
		int u=q.top().first;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[u]+w<=dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int k_=j+1;k_<=k;k_++){
				g[x[j]].push_back({x[k_],t[j]+t[k_]});
				g[x[k_]].push_back({x[j],t[j]+t[k_]});
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijk(x);
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
	return 0;
}
