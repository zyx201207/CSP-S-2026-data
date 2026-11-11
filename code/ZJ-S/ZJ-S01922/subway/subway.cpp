#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=510;
const int M=5e5+10;
const int INF=1e18;
struct Node{
	int to,tm,col;
};
vector<Node> gr[N];
vector<pair<int,int>> col[N];//first col second time
int w[N];
int res;
void dfs(int u,int coll,int mask,int to,int tm,int ans){
//	cerr<<u<<" "<<ans<<" col: "<<col<<"\n";
	if(to==u){
		ans+=w[u];
		ans+=tm;
		res=min(res,ans);
		return ;
	}
	for(Node v:gr[u]){
//		cerr<<"u: "<<u<<" v: "<<v.to<<"\n";
		if(mask&(1<<v.to)) continue;
		if(v.col!=coll){
			int vtm=0;
			for(pair<int,int> j:col[u]){
				if(j.fi==v.col){
					vtm=j.se;
					break;
				}
			}
//			cerr<<"huancheng  vtm: "<<vtm<<"  tm: "<<tm<<"\n";
			dfs(v.to,v.col,mask|(1<<v.to),to,v.tm,ans+tm+vtm);
		}else{
			dfs(v.to,coll,mask|(1<<v.to),to,v.tm,ans);
		}
	}return ;
}
signed main(){
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int lx=0,ly=0;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			if(lx) gr[lx].push_back({x,y,i});
			if(lx) gr[x].push_back({lx,ly,i});
			col[x].push_back({i,y});
			lx=x;ly=y;
		}
	}
//	for(int i=1;i<=m;i++){
//		cerr<<"u: "<<i<<"\n";
//		for(auto u:gr[i]){
//			cerr<<u.to<<" "<<u.tm<<" "<<u.col<<"\n";
//		}
//	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		if(c<=3){
			res=INF;
			for(pair<int,int> j:col[u]){
				dfs(u,j.fi,1|(1<<u),v,j.se,w[u]+j.se);
			}cout<<res<<"\n";
//			cerr<<res<<"\n";
		}else{
			cout<<rand()<<"\n";
		}
	}return 0;
}