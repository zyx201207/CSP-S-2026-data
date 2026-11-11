#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll energy[500010];
ll diff[500010];

bool check(ll x){
	ll sum=0;
	for(ll i=1;i<=n-x+1;i++){
		for(ll j=i;j<i+x-1;j++){
			sum+=energy[i+x-1]-energy[j];
			if(sum>m){
				break;
			}
		}
		if(sum<=m){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&energy[i]);
	}
	sort(energy+1,energy+1+n);
	ll left=1,right=n;
	while(left+1!=right){
		ll mid=(right-left)/2+left;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid;
		}
	}
	printf("%lld",left);
	return 0;
}
//meow
