#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }

ll n,m,a[500005],s[5000005];

void procedure(){
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];

	ll ans=0;
	for(ll l=1,r=0;l<=n;l++){
		while(r<n && (r-l+1)*a[r+1]-(s[r]-s[l-1])<=m) ++r;
		chkmax(ans,r-l+1);
	}
	printf("%lld\n",ans);
}
int main(){
	assert(freopen("crystal.in","r",stdin));
	assert(freopen("crystal.out","w",stdout));

	int T=1;
	while(T--) procedure();
}