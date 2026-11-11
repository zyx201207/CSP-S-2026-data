#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],sum[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		b[i]=a[i+1]-a[i]+b[i+1];
		sum[i]=sum[i+1]+b[i];
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sum[mid]-sum[i+1]-(i-mid+1)*b[i]<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;

	return 0;
}
