#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long f[500005];
long long n,m;
bool check(long long x){
	for(long long i=x;i<=n;i++){
		long long r=i-1ll;
		long long l=i-x;
		long long xd=f[r]-f[l];
		if(m>=(x-1ll)*a[i]-xd){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1ll;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1ll,a+n+1ll);
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1ll]+a[i];
	}
	long long l=1ll,r=n;
	long long ans=1ll;
	while(l<=r){
		long long mid=(l+r)/2ll;
		if(check(mid)){
			l=mid+1ll;
			ans=mid;
		}
		else{
			r=mid-1ll;
		}
	}
	cout<<ans<<endl;
	return 0;
}
