#include<bits/stdc++.h>
#define ll long long
const int N=5e5+5;
using namespace std;
int n,tot=1;
ll m,a[N],sum[N];
bool check(int k){
	//能不能有k个
	for(int i=1;i<=n-k+1;i++){
		ll x=a[i+k-1]*k+sum[i+k-1]-sum[i-1];
		if(x<=m)	return 1; 
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]-a[i];
	int l=1,r=n;
	ll ans;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
}
