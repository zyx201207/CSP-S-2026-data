#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,cnt=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[i]-sum[mid-1]+m>=(i-mid+1)*a[i]) cnt=mid,r=mid-1;
			else l=mid+1;
		}
		if(cnt==0) continue;
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}