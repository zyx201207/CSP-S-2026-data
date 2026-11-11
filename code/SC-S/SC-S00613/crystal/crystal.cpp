#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],sum[N],m;

bool check(long long x){
	for(long long i=x;i<=n;i++){
		if(sum[i]-sum[i-x]+m>=a[i]*x){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	long long l=0,r=n,ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
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