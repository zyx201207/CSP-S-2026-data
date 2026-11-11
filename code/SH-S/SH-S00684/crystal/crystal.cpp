#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int l=1,r=1;r<=n;++r){
		while((r-l+1)*a[r]-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}
