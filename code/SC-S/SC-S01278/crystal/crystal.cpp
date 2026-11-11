#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
ll n,m;
ll a[N];
ll ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll l=1; 
	ll sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m) sum-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
双指针l,r维护一个区间
在这个区间中把所有数的值都可以通过m变成a[r]
找区间最大值
*/
