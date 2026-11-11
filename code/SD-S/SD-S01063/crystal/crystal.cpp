#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
bool check(int len){
	int c=1e18;
	for(int i=1;i+len-1<=n;i++){
		int tot=(len-1)*(a[i+len-1])-(sum[i+len-2]-sum[i-1]);
		c=min(c,tot);
	}
	return c<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
