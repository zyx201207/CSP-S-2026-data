#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int sum[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++) cerr<<sum[i]<<' ';
//	cerr<<'\n';
	int ans=0;
	for(int r=1;r<=n;r++){
		int l=r;
		for(int i=1<<20;i;i>>=1){
			int nl=l-i;
			if(1<=nl&&a[r]*(r-nl+1)-(sum[r]-sum[nl-1])<=m) l=nl;
		}
//		cerr<<l<<' '<<r<<'\n';
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
}
//void clear(){
//
//}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T;T=1;
	while(T--){
		solve();
//		clear();
	}
	return 0;
}
/*

6 0
1 1 4 5 1 4

*/
