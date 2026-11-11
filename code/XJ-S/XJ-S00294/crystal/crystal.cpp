#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],sum[500005],m;
int bound(int x){
	int l=1,r=x,ans=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1;i<=n;i++){
		int j=bound(i);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
