#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n, m, a[N], sum[N], ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
	for(int i=1; i<=n; i++){
		int l=1, r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int t=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
			// if(i==4236)cout<<i<<' '<<mid<<' '<<t<<' '<<a[i]<<' '<<sum[i]-sum[mid-1]<<'\n';
			if(t<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
		// if(i-l+1==4236)cout<<i<<' '<<l<<' '<<a[i]<<' '<<a[l]<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}