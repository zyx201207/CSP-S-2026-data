#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+1;
ll t,n,d,a[N*1000],ans,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&a[1],&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i]-=a[1];
		}
	}
	ll k=d/(a[2]-a[1]);
	ans=(n-2*k-1)*(n-2*k-2);
	ans=ans>=0?ans:0;
	printf("%lld",(n-2*k-1)*(n-2*k-2));
	return 0;
}

