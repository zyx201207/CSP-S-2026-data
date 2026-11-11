#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,ans;
ll a[N];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		ll sum=0;
		for(int j=i;j<=i+(x-1)/2;j++){
			sum+=a[i*2+x-j-1]-a[j];
			cout<<x<<' '<<a[i*2+x-j-1]<<' '<<a[j]<<' '<<sum<<"\n";
		}
		if(sum<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}