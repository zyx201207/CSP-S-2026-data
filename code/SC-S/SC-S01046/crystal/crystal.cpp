#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dep(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
const int N=5e5+15;

int n,m,a[N],s[N];

void solve(){
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n,[](int x,int y){return x>y;});
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int ans=1,r=1;
	rep(l,1,n){
		if(r<l) r=l;
		while(r<n&&(r+1-l)*a[l]-(s[r+1]-s[l])<=m) r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
}

#define NAME "crystal"

signed main(){
#ifdef NAME
	freopen(NAME".in","r",stdin);
	freopen(NAME".out","w",stdout);
#endif
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}