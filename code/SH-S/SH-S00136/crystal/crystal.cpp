//crystal
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],s[N];
bool ok(int k){
	for(int i=k;i<=n;i++){//i-k+1~k修改成k的值 
//		cout<<k*a[i]-(s[i]-s[i-k])<<endl;
		if(k*a[i]-(s[i]-s[i-k])<=m){
//			cout<<k<<" "<<i<<" "<<k*a[k]<<" "<<s[i]-s[i-k]<<endl;
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
	int l=1; int r=n; int ans=1;
	while(l<=r){
//		cout<<l<<" "<<r<<" "<<ans<<endl;
		int mid=l+(r-l)/2;
		if(ok(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
