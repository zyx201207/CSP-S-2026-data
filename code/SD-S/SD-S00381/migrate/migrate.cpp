#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,t,d;
ll x[2000005];
int find(ll num){
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(num<=x[mid]){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int dis(ll a,ll b){
	int t=1;
	while(find(x[a]+d)!=b){
		t++;
		a=find(x[a]+d);
	};
	return t;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	scanf("%lld%lld",&c,&t);
//	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				
			}
		}
//	}
	return 0;
}
