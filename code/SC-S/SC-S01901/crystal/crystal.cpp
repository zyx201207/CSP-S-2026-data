#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long n,a[500010],sum[500010],m,res=1;
signed main(){
	ios
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(long long i=2;i<=n;i++){
		long long l=1,r=i-1,ans=-1;
		while(l<=r){
			long long mid=(l+r)/2;
			long long cst=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
//			cout<<mid<<" "<<i<<" "<<cst<<"\n";
			if(cst<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		if(ans==-1)continue;
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
} 