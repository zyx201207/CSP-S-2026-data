#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int id,n,dis;
	operator<(const node&a)const{return dis<a.dis||(dis==a.dis&&id<a.id);}
};

int c,m,n,d,q,w[500005],t[505][500005];
vector<node> g[50005];

int dij(int st,int en){
	int dis[505];
	bool vis[505];
	priority_queue<node> q;
	q.push({st,-1,0});
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(auto v:g[u.id]){
			int di=0;
			if(v.n!=u.n&&u.n!=-1) di=t[v.n][u.id]+t[u.n][u.id];
			if(u.dis+di<dis[u.id]){
				dis[u.id]=u.dis+di;
				q.push({v.id,v.n,dis[u.id]});
			}
		}
	}
	return dis[en];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a>>t[i][j];
			if(last!=-1){
				g[a].push_back({last,i,0});
				g[last].push_back({a,i,0});
			}
			last=a;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}