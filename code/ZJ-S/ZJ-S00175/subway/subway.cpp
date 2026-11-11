#include<bits/stdc++.h>
// #include<cassert>
#define int long long
#define maxn 550050
#define fi first
#define se second
using namespace std;
const int inf=(int)1e18+7;

int n,m,d,q,a[maxn],w[550][550];
vector<pair<int,int> >e[maxn];
inline void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			w[i][j]=(i!=j)*inf;
		}
	}
	for(int i=1;i<=n;i++){
		int len,x,w;
		cin>>len;
		while(len--){
			cin>>x>>w;
			e[x].emplace_back(i,w);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:e[i]) for(auto k:e[i]){
			w[j.fi][k.fi]=min(w[j.fi][k.fi],j.se+k.se);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				w[j][k]=min(w[j][k],w[j][i]+w[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto j:e[x]) for(auto k:e[y]){
			ans=min(ans,w[j.fi][k.fi]+j.se+k.se);
		}
		ans+=a[x]+a[y];
		cout<<ans<<'\n';
	}
}
signed main(){
	#define FILE "subway"
	// #ifdef LOCAL
	// assert(freopen("test.in","r",stdin));
	// assert(freopen("test.out","w",stdout));
	// #else
	assert(freopen(FILE".in","r",stdin));
	assert(freopen(FILE".out","w",stdout));
	// #endif
	int T=1,Cid;
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Cid;
	while(T--) solve();
	cerr<<"Time: "<<clock()*1000/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}