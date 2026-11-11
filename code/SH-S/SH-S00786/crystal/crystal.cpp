#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5e5+10;
int n,m,a[Maxn],sum[Maxn],i,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
			 	r=mid-1,ans=max(ans,i-mid+1);
			}
			else l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
