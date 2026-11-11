#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(auto i=(l);i<=(r);i++)
#define irep(i,l,r) for(auto i=(l);i>=(r);i--)
#define sc cerr
#define qlog(x) {sc<<#x<<"="<<(x)<<"\n";}
#define qloga(a,l,r) {sc<<#a<<": "; rep(I,l,r){sc<<a[i]<<" ";} sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<": "; for(const auto &x:a){sc<<x<<" ";} sc<<"\n";}
typedef long long ll;
typedef __int128 i128;

#define int ll
constexpr int N=1e6+550, ST=509;
int _c,n,m,_d,q;
ll w[N];

vector<pair<int,int>> sub[N]; // the subways in station x
ll d[ST][ST];
void addedge(int u,int v,ll w){
	d[u][v]=d[v][u]=min(d[u][v],w);
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	memset(d,0x3f,sizeof(d));
	cin>>_c>>n>>m>>_d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k; cin>>k;
		rep(_,1,k){
			int x,t;
			cin>>x>>t;
			sub[x].emplace_back(i,t);
		}
	}
	rep(x,1,m){
		int l=sub[x].size();
		rep(i,0,l-1)rep(j,i+1,l-1){
			int u=sub[x][i].first, v=sub[x][j].first;
			int tu=sub[x][i].second, tv=sub[x][j].second;
			addedge(u,v,tu+tv);
		}
	}
	rep(u,1,n)d[u][u]=0;
	rep(k,1,n)rep(u,1,n)rep(v,1,n){
		d[u][v]=min(d[u][v],d[u][k]+d[k][v]);
	}
	rep(_,1,q){
		int u,v; cin>>u>>v;
		ll ans=9e18;
		for(const auto &X:sub[u]){
			for(const auto &Y:sub[v]){
				ans=min(ans,d[X.first][Y.first]+X.second+Y.second+w[u]+w[v]);
			}
		}
		cout<<ans<<"\n";
	}
}
