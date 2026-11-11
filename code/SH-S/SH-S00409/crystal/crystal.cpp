#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m,a[N+10],sum[N+10],ans=0;
bool check(int l,int r) {
	return a[r]*(r-l+1)-sum[r]+sum[l-1]<=m;
} signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	} sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++) {
		while(j<=i&&(!check(j,i))) j++;
		ans=max(ans,i-j+1);
	} cout<<ans<<'\n';
	return 0;
}
