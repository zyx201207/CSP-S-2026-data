#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005];
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	int now=0;
	a[0]=a[1];
	int ans=1;
	for(int i=1;i<=n;++i){
		now+=(i-l)*(a[i]-a[i-1]);
		while(now>m){
			now-=(a[i]-a[l]);
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

