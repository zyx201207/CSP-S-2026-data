#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q;
int w[N],ans,cc=1e8+10;
struct node{
	int to,val;
};
vector<node> g[N];
bool vis[N];
int dis[N];
priority_queue<node> qq;
bool operator<(node x,node y){return x.val<y.val;}
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	vis[s]=1;
	qq.push({s,0});
	while(!qq.empty()){
		node now=qq.top();
		qq.pop();
		int u=now.to;
		for(auto y:g[u]){
			int v=y.to,ww=y.val;
			if(vis[v]) continue;
			vis[v]=1;
			if(dis[v]>dis[u]+ww) dis[v]=dis[u]+ww;
			qq.push({v,dis[v]});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last_a,last_t;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(j==1){
				last_a=a;
				last_t=t;
				continue;
			}
			g[last_a].push_back({a,t+last_t});
			last_a=a;
			last_t=t;
		}
	}
	dij(1);
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<abs(dis[ed]-dis[st]+w[st]+w[ed])<<"\n";
	}
	return 0;
}