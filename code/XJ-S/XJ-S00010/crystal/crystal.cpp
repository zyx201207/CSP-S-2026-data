#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m,sum[N],a[N];
bool ok(int s){
	int mi=1e18;
	for(int i=1;i+s-1<=n;i++){
		int l=i,r=i+s-1;
		mi=min(mi,s*a[r]-(sum[r]-sum[l-1]));
	}
	return mi<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=1e18,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ok(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
