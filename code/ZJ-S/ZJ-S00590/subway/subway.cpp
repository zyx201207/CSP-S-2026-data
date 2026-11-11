#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],a[N],t[N],ans[N],vis[N];
struct node{
	int v,w;
	bool operator <(const node &p)const{
		return w>p.w;
	}
};
vector<node> g[N];
void dij(int x){
	priority_queue<node> q;
	q.push({x,0});
	ans[x]=0;
	while(!q.empty()){
		while(!q.empty()&&vis[q.top().v]) q.pop();
		if(q.empty()) return;
		int v=q.top().v,w=q.top().w;
		q.pop();
		vis[v]=1;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i].v;
			if(!vis[u]){
				ans[u]=min(ans[u],ans[v]+g[v][i].w);
				q.push({u,ans[u]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int u=1;u<j;u++){
				g[a[j]].push_back({a[u],t[u]+t[j]});
				g[a[u]].push_back({a[j],t[u]+t[j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			ans[i]=2e9;
			vis[i]=0;
		}
		dij(x);
		cout<<w[x]+w[y]+ans[y]<<"\n";
	}
	return 0;
}
