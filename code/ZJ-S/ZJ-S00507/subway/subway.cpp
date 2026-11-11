#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int ii=l;ii<=r;++ii) cerr<<a[ii]<<" ";ED
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define epb emplace_back
using namespace std;
const int N=5e5+5,M=2e5+5,K=505;
const ll INF=1e18;
int c,n,m,d,q;int w[N];
vector<pii> e[N];
ll f[K][K];

inline int read() {
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) {
		w[i]=read();
	}
	for(int i=1;i<=n;++i) {
		int sz;sz=read();
		for(int j=0,x,y;j<sz;++j) {
			x=read(),y=read();
			e[x].epb(i,y);
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;++i) {
		int sz=(int)e[i].size();
		for(int x=0;x<sz;++x) {
			pii u=e[i][x];
			for(int y=x+1;y<sz;++y) {
				pii v=e[i][y];
				f[u.fi][v.fi]=min(f[u.fi][v.fi],(ll)u.se+v.se);
			}
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			ll x=min(f[i][j],f[j][i]);
			f[i][j]=f[j][i]=x;
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i==j) continue;
			for(int k=1;k<=n;++k) {
				if(i!=k&&j!=k) {
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--) {
		int x,y;ll ans=INF;
		x=read(),y=read();
		for(auto it1:e[x]) {
			for(auto it2:e[y]) {
				ans=min(ans,f[it1.fi][it2.fi]+it1.se+it2.se);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
//zhen shi wu qv a
//wo da gai hen kuai jiu hui wang le ni ba
