#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],s[1000001];
bool check(int k){
	int ans=1e18;
	for(int l=1;l+k-1<=n;l++){
		int r=l+k-1;
		ans=min(ans,a[r]*k-(s[r]-s[l-1]));
	}
	if(ans<=m)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}