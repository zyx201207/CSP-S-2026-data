#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum[0]=a[0];
//	cout<<a[0]<<' ';
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+a[i];
//		cout<<a[i]<<' ';
	}
	int ans=0;
	for(int i=n-1;i>=0;i--){
		int l=0,r=i;
		while(l<r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]>m)l=mid+1;
			else r=mid;
		}
//		if(ans<i-l+1)cout<<i<<' '<<l<<' '<<i-l+1<<' '<<a[i]<<'\n';
		ans=max(ans,i-l+1);
//		cout<<i<<' '<<l<<'\n';
	}
	cout<<ans;
	return 0;
}
