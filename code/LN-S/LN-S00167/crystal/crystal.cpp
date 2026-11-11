#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m,a[N],ans=-1;
ll check(ll x){
	ll cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[x]<a[i])break;
		if(sum+a[x]-a[i]<=m){
			sum+=(a[x]-a[i]);
			cnt++;
		}
	}
	return cnt;
}		
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)ans=max(ans,check(i));	
	printf("%lld",ans);
	return 0;
}
