#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
