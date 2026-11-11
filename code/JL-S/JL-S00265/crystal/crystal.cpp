#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010];
bool A(ll n){
	for(ll i=1;i<=n;i++)
		if(a[i]!=i)
			return 0;
	return 1;
}
bool B(ll n){
	for(ll i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,i,k=0;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(A(n)){
		for(i=1;i<=n;i++){
			if(i*(i-1)-(i-1)*i/2>m){
				printf("%lld",i-1);
				return 0;
			}
		}
	}
	if(B(n)){
		for(i=1;i<=n;i++){
			if(a[i]*(i-1)-(a[i-1]+a[1])*(i-1)/2>m){
				printf("%lld",i-1);
				return 0;
			}
		}
	}
	for(i=1;i<=n;i++){
		m-=(i-1)*(a[i]-k);
		k=a[i];
		if(m<0){
			printf("%lld",i-1);
			return 0;
		}
	}
	printf("1");
	return 0;
}
