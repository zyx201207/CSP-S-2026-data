#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+10,M=1e3+10,mod=1e9+7;
int c,n,m,d,q,ww[N],a[M][M],t[M][M],k[N],dis[N],mmin=LLONG_MAX;
struct node{
	int v,w;
//	bool operator<(struct &o) const{
//		return o.w>w;
//	}
};
vector<node> G[N];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			G[a[i][j]].push_back({a[i][j+1],t[i][j]+t[i][j+1]});
		}
	}
}
void dfs(int u,int v,int tme){
	if(u==v){
		mmin=min(mmin,tme);
		return ;
	}
	for(auto to:G[u]){
		dfs(to.v,v,tme+to.w);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	faster;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	init();
	while(q--){
		int x,y,mmin=LLONG_MAX;
		cin>>x>>y;
		dfs(x,y,0);
//		memset(dis,0x3f,sizeof(dis));
//		priority_queue<node> pq;
//		pq.push({x,0});
//		while(!pq.empty()){
//			int f=pq.top().v;
//			pq.pop();
//			for(auto to:G[f]){
//				if(dis[f]+to.w<dis[to.v]){
//					dis[to.v]=dis[f]+to.w;
//					pq.push({to.v,dis[to.v]});
//				}
//			}
//		}
		cout<<mmin+ww[x]+ww[y]<<endl;
	}
	return 0;
}
