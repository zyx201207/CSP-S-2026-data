#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500005],sum[500005]; 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(m-(i-mid+1)*a[i]+sum[i]-sum[mid-1]>=0) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
