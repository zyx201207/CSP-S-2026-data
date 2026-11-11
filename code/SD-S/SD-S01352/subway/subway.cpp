#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int M=5e2+10;
const int K=1e7+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[N],k[M];
unordered_map<int,ll> ans[N];
vector<int> temp[N];
unordered_map<int,int> a[N],t[N];
struct Gragh{
	int v,id,val;
};
vector<Gragh> G[K],nw[K];
struct node{
	int v,id;  ll w;
	unordered_map<int,int> mp;
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
int idx;
bool vis[K],flag[K];
ll dis[K];
priority_queue<node> pq;
void Dijkstra(){
	for(int i=1;i<=idx;i++) dis[i]=INF;
	unordered_map<int,int> un;
	for(auto v:temp[1]){
		dis[a[1][v]]=0;
		pq.push({a[1][v],v,0,un});
	}
	while(!pq.empty()){
		int u=pq.top().v,id=pq.top().id;
		un=pq.top().mp;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		if(flag[u]) un[u]=dis[u]-t[u][id];
		for(auto v:nw[u]){
			ans[v.val][v.id]=min(ans[v.val][v.id],dis[u]-un[v.v]+t[u][id]);
		}
		for(auto v:G[u]){
			if(dis[v.v]>dis[u]+v.val){
				dis[v.v]=dis[u]+v.val;
				pq.push({v.v,v.id,dis[v.v],un});
			}
		}
	}
}
int x[N],y[N];
int main(void){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,nw1;
			cin>>u>>nw1;
			a[u][i]=++idx;
			t[idx][i]=nw1;
			temp[u].push_back(i);
			if(j>1) G[idx-1].push_back({idx,i,0});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<(int)(temp[i].size());j++){
			G[a[i][temp[i][j-1]]].push_back({a[i][temp[i][j]],temp[i][j],t[a[i][temp[i][j-1]]][temp[i][j-1]]+t[a[i][temp[i][j]]][temp[i][j]]});
			G[a[i][temp[i][j]]].push_back({a[i][temp[i][j-1]],temp[i][j-1],t[a[i][temp[i][j-1]]][temp[i][j-1]]+t[a[i][temp[i][j]]][temp[i][j]]});
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++) ans[i][j]=INF;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(auto v:temp[x[i]]){
			flag[a[x[i]][v]]=true;
			for(auto vv:temp[y[i]]){
				nw[a[y[i]][vv]].push_back({a[x[i]][v],v,i});
			}
		}
	}
	Dijkstra();
	for(int i=1;i<=q;i++){
		ll res=INF;
		for(int j=1;j<=n;j++){
			res=min(res,ans[i][j]+w[x[i]]+w[y[i]]);
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
