#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }

ll c,n,m,d,q,w[500005];
vector<pair<ll,ll>>vec[500005];

ll f[505][505];

void procedure(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		ll k=read();
		while(k--){
			ll a=read(),t=read();
			vec[a].pb(i,t);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(ll i=1;i<=n;i++) f[i][i]=0;
	for(ll x=1;x<=m;x++)
		for(auto [i,t1]: vec[x])for(auto [j,t2]: vec[x])
			chkmin(f[i][j],t1+t2);
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		ll x=read(),y=read(),ans=4e18;
		for(auto [i,t1]: vec[x])for(auto [j,t2]: vec[y])
			chkmin(ans,t1+t2+f[i][j]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
int main(){
	assert(freopen("subway.in","r",stdin));
	assert(freopen("subway.out","w",stdout));

	int T=1;
	while(T--) procedure();
}