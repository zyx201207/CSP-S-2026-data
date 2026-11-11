#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n)  for(int i=0;i<(n);++i)
#define sizc(x) (int((x).size()))
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N=505,M=1e6+5;

int tc,n,m,_d,q;

ll w[M],dis[N][N];
vector<pair<int,ll>> vc[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>tc>>n>>m>>_d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k;cin>>k;
		rep(j,1,k){
			int p;ll t;cin>>p>>t;
			vc[p].emplace_back(i,t);
		}
	}
	rep(i,1,n)rep(j,1,n)dis[i][j]=1e18;
	rep(i,1,n)dis[i][i]=0;
	rep(i,1,m){
		for(auto p1:vc[i])
			for(auto p2:vc[i]){
				int a=p1.fir,c=p2.fir;ll b=p1.sec,d=p2.sec;
				dis[a][c]=min(dis[a][c],b+d);
				dis[c][a]=min(dis[c][a],b+d);
			}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=1e18;
		for(auto p1:vc[x])for(auto p2:vc[y]){
			int a=p1.fir,c=p2.fir;ll b=p1.sec,d=p2.sec;
			ans=min(ans,b+d+dis[a][c]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
