#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],sum[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((mid-1)*a[i]-sum[i-1]+sum[i-mid]<=m){
				res=mid;
				l=mid+1;
			}else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
