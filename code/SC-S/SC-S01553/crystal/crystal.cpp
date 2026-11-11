#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool aa(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++){
		sum=sum+a[mid]-a[i];
	}
	for(int i=mid+1;i<=n;i++){
		sum=sum+mid*(a[i]-a[i-1])+a[i-mid]-a[i-1];
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(aa(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}