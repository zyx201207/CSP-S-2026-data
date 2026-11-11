#include <bits/stdc++.h>
using namespace std;
#define fre
//~ #define CALC
//graphic model

namespace zyc{
	#define rep(i,l,r) for(int i=(l);i<=(r);i++)
	#define per(i,r,l) for(int i=(r);i>=(l);i--)
	#define pb push_back
	typedef long long ll;
	const int N=5e2+5,M=5e5+5;
	const ll INF=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,q,k,a,x,y;
	ll dis[N][N],w[M],t;
	struct ND{
		int id;
		ll t;
	};
	vector<ND>g[M];
	void floyd(){
		rep(i,1,n)rep(j,1,n)rep(k,1,n){
			if(dis[i][k]+dis[k][j]<dis[i][j]){
				dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	int main(){
		memset(dis,0x3f,sizeof dis);
		cin>>c>>n>>m>>d>>q;
		rep(i,1,m)cin>>w[i];
		rep(i,1,n){
			cin>>k;
			rep(j,1,k){
				cin>>a>>t;
				g[a].pb({i,t});
			}
		}
		rep(i,1,n)dis[i][i]=0;
		rep(p,1,m){
			for(auto i:g[p]){
				for(auto j:g[p]){
					dis[i.id][j.id]=min(dis[i.id][j.id],i.t+j.t);
				}
			}
		}
		floyd();
		while(q--){
			cin>>x>>y;
			t=INF;
			for(auto i:g[x])for(auto j:g[y]){
				t=min(t,i.t+j.t+dis[i.id][j.id]);
			}
			t+=w[x]+w[y];
			cout<<t<<'\n';
		}
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef fre
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	zyc::main();
	return 0;
}
