#include<bits/stdc++.h>
// #include<cassert>
#define int long long
#define maxn 2050050
#define fi first
#define se second
using namespace std;
const int inf=(int)1e18+7;

int n,d,a[maxn],nxt[2][maxn],f[maxn],g[maxn];
inline void solve(){
	cin>>n>>d;
	for(int i=1,j=1;i<=n;i++){
		cin>>a[i];
		while(a[i]-a[j]>d) j++;
		nxt[0][i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(a[j]-a[i]>d) j--;
		nxt[1][i]=j;
	}
	// for(int i=1;i<=n;i++) cerr<<nxt[0][i]<<' ';cerr<<'\n';
	// for(int i=1;i<=n;i++) cerr<<nxt[1][i]<<' ';cerr<<'\n';
	for(int i=1;i<=n;i++){
		f[i]=0;
		int l=nxt[0][i],r=i-1;
		if(i<n) r=min(r,nxt[0][i+1]-1);
		if(l<=r) f[i]+=r-l+1;
		if(l<i&&nxt[1][l]==i) f[i]+=f[l];
	}
	// for(int i=1;i<=n;i++) cerr<<f[i]<<' ';cerr<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++){
		g[i]=0;
		int l=nxt[0][i];
		if(l+2>i) continue;
		int L=nxt[0][l+1],R=min(l-1,nxt[0][l+2]-1);
		if(L>R) continue;
		ans+=R-L+1;
		if(nxt[0][l]==L) ans+=f[L];
		if(nxt[1][l]!=i||nxt[1][l+1]!=i) continue;
		g[i]=R-L+1;
		if(nxt[0][l]==L) g[i]+=f[L];
	}
	// cerr<<ans<<'\n';
	// for(int i=1;i<=n;i++) cerr<<g[i]<<' ';cerr<<'\n';
	for(int i=1;i<=n;i++){
		f[i]=g[i];
		if(nxt[0][i]<i&&nxt[1][nxt[0][i]]==i) f[i]+=f[nxt[0][i]];
	}
	// cerr<<ans<<'\n';
	// for(int i=1;i<=n;i++) cerr<<f[i]<<' ';cerr<<'\n';
	// g[0]=0;
	// for(int i=1;i<=n;i++) g[i]=g[i-1]+f[i];
	for(int i=1;i<=n;i++) if(nxt[0][i]<i){
		ans+=f[nxt[0][i]];
		// int l=nxt[0][i],r=i-1;
		// if(i<n) r=min(r,nxt[0][i+1]-1);
		// if(l<=r) ans+=g[r]-g[l-1];
	}
	cout<<ans<<'\n';
}
signed main(){
	#define FILE "migrate"
	assert(freopen(FILE".in","r",stdin));
	assert(freopen(FILE".out","w",stdout));
	int T=1,Cid;
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Cid>>T;
	while(T--) solve();
	cerr<<"Time: "<<clock()*1000/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}