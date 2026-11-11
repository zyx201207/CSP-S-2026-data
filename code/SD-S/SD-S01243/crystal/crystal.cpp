#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n,ans=0;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,p=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1)) p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}//14:42
