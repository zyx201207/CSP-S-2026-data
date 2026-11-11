#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			mid=l+r>>1;
			if(sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1)) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}