#include<bits/stdc++.h>
#define now_time ((int)(((double)clock()/CLOCKS_PER_SEC)*1000))
#define all_memory ((&St-&Ed)/1024.0/1024.0)

using namespace std;
using ll=long long;

namespace Usd{bool St;}

constexpr ll N=500,M=5e5,D=20,Q=1e5;
constexpr ll Imax=0x3f3f3f3f3f3f3f3f;

ll subtask,n,m,d,q;
ll w[M+5];
ll dis[N+5][N+5];
struct node{
	ll _pos,_tim;
}s[M+5][D+5];
ll num[M+5];

namespace Usd{bool Ed;void out(){cerr<<"   time: "<<now_time<<"ms\n memory: "<<all_memory<<"MiB\n";}}
//14:55  --  16:18
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>subtask>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=m;++i) cin>>w[i];
	for(ll i=1,k;i<=n;++i){
		cin>>k;
		for(;k--;){
			ll a,t;
			cin>>a>>t;
			++num[a];
			s[a][num[a]]={i,t};
		}
	}
	
	for(ll i=1;i<=n;++i) dis[i][i]=0;
	
	//m*d^2
	for(ll i=1;i<=m;++i){
		for(ll j=1;j<=num[i];++j){
			for(ll k=1;k<=num[i];++k)
				dis[s[i][j]._pos][s[i][k]._pos]=min(dis[s[i][j]._pos][s[i][k]._pos],s[i][j]._tim+s[i][k]._tim);
		}
	}
	//n^3
	for(ll k=1;k<=n;++k){
		for(ll i=1;i<=n;++i){
			if(i==k) continue;
			for(ll j=1;j<=n;++j){
				if(i==j||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//q*d^2
	for(ll x,y;q--;){
		cin>>x>>y;
		ll ans=Imax;
		for(ll i=1;i<=num[x];++i){
			for(ll j=1;j<=num[y];++j){
				ans=min(ans,s[x][i]._tim+s[y][j]._tim+dis[s[x][i]._pos][s[y][j]._pos]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	//O((m+q)*d^2+n*3)
	return 0;
}
