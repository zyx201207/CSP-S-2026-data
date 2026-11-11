#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> twin;
constexpr int MX=1e6+1;
int c,n,m,d,q,w[MX],k[MX],x[MX],y[MX];
vector<int> a[501],t[501],dis[MX];
vector<twin> e[MX];
bool vis[MX];
void dij(int s){
	dis[s][s]=0;
	priority_queue<twin,vector<twin>,greater<twin>> q;
	for(int i=1;i<=m;++i){
		vis[i]=0;
	}
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &ei:e[u]){
			int v=ei.first,w=ei.second;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++j){
			for(int l=j+1;l<=k[i];++l){
				e[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				e[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
			}
		}
	}
	for(int i=1;i<=m;++i){
		dij(i);
	}
	for(int i=1;i<=q;++i){
		cout<<(dis[x[i]][y[i]]+w[x[i]]+w[y[i]])<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		dis[i].resize(m+1,1e17);
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		t[i].resize(k[i]+1);
		a[i].resize(k[i]+1);
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	solve1();
	return 0;
}

