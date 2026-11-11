#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int ans;
long long check(int l,int r){
	if(l>r)return 0;
	return 1ll*a[r]*(r-l+1)-sum[r]+sum[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	int l=1,r=0;
	while(r<=n){
		while(r<n&&check(l,r+1)<=m)r++;
		ans=max(ans,r-l+1);
		l++;
		if(r<l-1)r=l-1;
	}
	cout<<ans;
}