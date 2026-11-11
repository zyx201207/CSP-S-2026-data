#include<bits/stdc++.h>
// #include<cassert>
#define int long long
#define maxn 550050
using namespace std;
const int inf

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
}
signed main(){
	#define FILE "test"
	#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
	#else
	// assert(freopen(FILE".in","r",stdin));
	// assert(freopen(FILE".out","w",stdout));
	#endif
	int T=1,Cid;
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Cid;
	while(T--) solve();
	cerr<<"Time: "<<clock()*1000/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}