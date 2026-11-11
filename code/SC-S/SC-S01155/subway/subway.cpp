//CSP-S 2026 B by wyyinput
//Task name: subway
//Date: 2026/10/31
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll inf=1e18;
int C,n,m,d,q,sumk;
int w[500055];
int k[555];
vector<int> a[555];
vector<int> t[555];
vector<pii> e[1000055];
ll dis[1000055];
bool vis[1000055];
ll get_dis(int u,int v){
	for(int i=1;i<=m+sumk+5;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[u]=0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,u});
	while(!pq.empty()){
		int x=pq.top().se;
		pq.pop();
		if(vis[x]){
			continue;
		}
		if(x==v){
			break;
		}
		vis[x]=1;
		for(pii pp:e[x]){
			int y=pp.fi;
			int dxy=pp.se;
			if(dis[y]>dis[x]+dxy){
				dis[y]=dis[x]+dxy;
				pq.push({dis[y],y});
			}
		}
	}
	return dis[v];
}
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int id=m;
	sumk=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		sumk+=k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m+sumk+5;i++){
		e[i].clear();
	}
	for(int i=1;i<=n;i++){
		int fir;
		for(int j=1;j<=k[i];j++){
			//站台与站建边
			e[++id].emplace_back(a[i][j],t[i][j]);
			e[a[i][j]].emplace_back(id,t[i][j]);
			//同条地铁站台间无代价
			if(j==1){
				fir=id;
			}else{
				e[fir].emplace_back(id,0);
				e[id].emplace_back(fir,0);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=w[u]+w[v]+get_dis(u,v);
		cout<<ans<<"\n";
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C;
	solve();
	return 0;
}