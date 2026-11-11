#include<bits/stdc++.h>
// #include<cassert>
#define maxn 550050
#define int long long
using namespace std;

int n,m,a[maxn];
inline void solve(){	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,sum=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
signed main(){
	#define FILE "crystal"
	// #ifdef LOCAL
	// assert(freopen("test.in","r",stdin));
	// assert(freopen("test.out","w",stdout));
	// #else
	assert(freopen(FILE".in","r",stdin));
	assert(freopen(FILE".out","w",stdout));
	// #endif
	int T=1;
	ios::sync_with_stdio(0),cin.tie(0);
	// cin>>T;
	while(T--) solve();
	cerr<<"Time: "<<clock()*1000/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}