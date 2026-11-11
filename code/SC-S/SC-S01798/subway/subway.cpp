#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
namespace io {
	using namespace std;
	inline ll read () {
		char x=getchar();
		ll ans=0,f=1;
		while (x<'0'||x>'9') {
			if (x=='-') {
				f=-1;
			}
			x=getchar();
		}
		while (x>='0'&&x<='9') {
			ans=(ans<<1)+(ans<<3);
			ans+=(x-'0');
			x=getchar();
		}
		return ans*f;
	}
	void print (ll x) {
		if (x<0) {
			putchar('-');
			x=-x;
		}
		if (x>=10) {
			print(x/10);
		}
		putchar(x%10+'0');
	}
}
using namespace io;
const ll N=5e5+5,mod=1e9+7,inf=2e18;
const ld eps=1e-6;
ll n,m,w[N],mx,q,dis[505][505];
vector<pll> v[N];
inline void solve () {
	n=read(),m=read(),mx=read(),q=read();
	for (ll i=1;i<=m;i++) {
		w[i]=read();
	}
	for (ll i=1;i<=n;i++) {
		for (ll j=1;j<=n;j++) {
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for (ll i=1;i<=n;i++) {
		ll kl=read();
		while (kl--) {
			ll pos=read(),wl=read();
			v[pos].push_back({i,wl});
		}
	}
	for (ll i=1;i<=m;i++) {
		for (ll j=0;j<v[i].size();j++) {
			ll pos=v[i][j].first,val=v[i][j].second;
			for (ll k=j+1;k<v[i].size();k++) {
				ll pl=v[i][k].first,vl=v[i][k].second;
				dis[pos][pl]=dis[pl][pos]=min(dis[pos][pl],vl+val);
			}
		}
	}
	for (ll k=1;k<=n;k++) {
		for (ll i=1;i<=n;i++) {
			if (dis[i][k]==inf) {
				continue;
			}
			for (ll j=1;j<=n;j++) {
				if (dis[k][j]==inf) {
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
	while (q--) {
		ll x=read(),y=read();
		ll ans=inf;
		for (auto it : v[x]) {
			ll pos=it.first,val=it.second;
			for (auto itt : v[y]) {
				ll pl=itt.first,vl=itt.second;
				ans=min(ans,dis[pos][pl]+val+vl);
			}
		}
		print(ans+w[x]+w[y]);
		puts("");
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll CL=read(),T=1;
	while (T--) {
		solve();
	}
	return 0;
}