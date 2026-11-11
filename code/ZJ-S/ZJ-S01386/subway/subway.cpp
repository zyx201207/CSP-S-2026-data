#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define print(a)cout<<#a<<"= "<<a<<"\n";
#define aprint(a,l,r)cout<<#a<<"= ";rep(i,l,r)cout<<a[i]<<", ";cout<<"\n";
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=505,M=6e5+5;
ll c,n,m,d,q,w[M];
ll k[N];
vector<pair<ll,ll> >e[M];
ll dist[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll a,t;cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto y:e[i]){
			for(auto z:e[i]){
				dist[y.fi][z.fi]=dist[z.fi][y.fi]=min(dist[y.fi][z.fi],y.se+z.se);
			}
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto u:e[x]){
			for(auto v:e[y]){
				ans=min(ans,dist[u.fi][v.fi]+u.se+v.se+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	//cerr<<(double)clock()/CLOCKS_PER_SEC;
	return 0;
}
/*
froepen
chzx_AT AK NGOI!!!!!
15:37
*/