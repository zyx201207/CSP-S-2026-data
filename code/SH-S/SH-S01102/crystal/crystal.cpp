#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n;
long long m;
long long a[N],sum[N];
bool check(long long len){
	for(long long i=len;i<=n;i++){
		long long he=sum[i-1]-sum[i-len+1-1];
		if((len-1)*a[i]-he<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=2,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
