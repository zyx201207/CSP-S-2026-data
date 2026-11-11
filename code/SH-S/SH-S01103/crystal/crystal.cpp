#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],sum[N],ans=1;
int solve(int l,int r){
	return (r-l+1)*a[r]-sum[r]+sum[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int r=n;
	for(int i=n;i>=1;i--){
		while(solve(i,r)>m) r--;
		ans=max(ans,r-i+1);
	}
	cout<<ans<<'\n';
	return 0;
}
