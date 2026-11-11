#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll now,n,m,a[N],b[N],s[N];
bool isA=1;
bool check(int mid){
	ll sum;
	for(int i=mid;i<=n;i++){
		sum=a[i]*(mid-1)-(s[i-1]-s[i-mid]);
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			isA=0;
		}
	}
	if(isA){
		for(ll i=1;i<=n;i++){
			ll k=i,kk=i+1;
			if(k*kk>2*m){
				printf("%lld\n",i);
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld\n",l-1);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 10
-5 -3 -2 -1 3 15

*/
