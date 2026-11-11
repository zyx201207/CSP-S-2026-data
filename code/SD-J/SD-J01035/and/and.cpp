#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
signed main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
if (m==n) {
	int ans=a[1];
	for (int i=2;i<=n;i++) {
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
if (m==1) {
	int ans=-1;
	for (int i=1;i<=n;i++) {
		ans=max(ans,a[i]);
	}
	cout<<ans;
}
if (m==2){
	int ans=-1;
	for (int i=1;i<=n-1;i++) {
		for (int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
}
	return 0;
}
