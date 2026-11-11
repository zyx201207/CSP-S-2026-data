#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],sum[N],ans=1;
bool check(int l,int r){
	if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m){
//		cout<<l<<" "<<r<<" "<<a[r]*(r-l+1)-(sum[r]-sum[l-1])<<"\n";
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ret;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				ret=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-ret+1);
	}
	cout<<ans;
	return 0;
}
