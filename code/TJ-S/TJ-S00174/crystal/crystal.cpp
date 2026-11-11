#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long sum[500005],m,a[500005];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		if(sum[i+x-1]-sum[i-1]+m>=x*a[i+x-1]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<= n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
