#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int res=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,p=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,p=mid;
			else l=mid+1;
		}
		res=max(res,i-p+1);
	}
	cout<<res<<endl;
	return 0;
} 