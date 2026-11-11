#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cll const long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define ld long double
using namespace std;
cll M=500009,N=509;
vector<pair<ll,ll> > sta[M];
ll w[M],f[N][N];
void solve(){
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		ll k;cin>>k;
		rep(j,1,k){
			ll a,t;cin>>a>>t;
			sta[a].push_back(make_pair(i,t));
		}
	}
	rep(i,1,n)rep(j,1,n)f[i][j]=1e18; rep(i,1,n)f[i][i]=0;
	rep(i,1,m)for(auto A:sta[i]) for(auto B:sta[i]){
		ll u=A.first,v=B.first,t=A.second+B.second;
		f[u][v]=min(f[u][v],t); f[v][u]=min(f[v][u],t);
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		ll x,y;cin>>x>>y; ll ans=1e18;
		for(auto A:sta[x])for(auto B:sta[y])ans=min(ans,f[A.first][B.first]+A.second+B.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
bool B;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1; //cin>>T;
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(T--)solve();
	return 0;
}

