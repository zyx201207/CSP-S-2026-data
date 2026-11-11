#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
const int N=5e5+5,NN=1e6+6,mod=1e9+7;
int c,n,m,q,T,d;
int w[N],dist[NN];
int idx;
vector<PII>edge[NN];
int dij(int s,int t){
	priority_queue<PII,vector<PII>,greater<PII>>q;
	bitset<NN>vis{0};
	for(int i=1;i<=idx;i++){
		dist[i]=1e18;
	}
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		PII t=q.top();q.pop();
		int u=t.second;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(PII i:edge[u]){
			int v=i.first,w=i.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				if(!vis[v]){
					q.push({dist[v],v});
				}
			}
		}
	}
	return dist[t];
}
void solveA(){
	idx=n;
	for(int i=1,k;i<=m;i++){
		cin>>k;
		if(k==1){
			continue;
		}
		int a,b,x,y;
		cin>>a>>x>>b>>y;
		edge[a].pb({b,x+y});
		edge[b].pb({a,x+y});//这样的特殊样例可以简化图的大小约三分之一 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<"\n";
	}
}
void solve(){
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	if(c>=7&&c<=11){
		solveA();
		return;
	} 
	idx=n;
	for(int i=1,k;i<=m;i++){
		cin>>k;
		if(k==1){
			continue;
		}
		for(int j=1,a,t,la;j<=k;j++){
			cin>>a>>t;
			idx++;//idx代表当前的a号地铁站的分身 
			edge[a].pb({idx,t});
			edge[idx].pb({a,t});
			if(j>1){//地铁怎么会是单向的？
				edge[idx].pb({la,0});
				edge[la].pb({idx,0});
			}
			la=idx;
		}
	}
	while(q--){//1e5的询问 
		int x,y;
		cin>>x>>y;
		int ans=dij(x,y)+w[x]+w[y];//垃圾onm，有没有logn或logm的 
		cout<<ans<<"\n";
	}
}
signed main(){
	ios;
//	cin>>T;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	T=1;
	while(T--){
		solve();
	}
	return 0;
}

