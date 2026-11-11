#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll Max=1e18+5;
ll num[N];
ll sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}sort(num+1,num+1+n);
	ll jia=0-num[1];
	if(jia>0){
		for(int i=1;i<=n;i++){
			num[i]+=jia+1;
		}	
	}
	for(int i=n;i>0;i--){
		sm[i]=num[n]+1-num[i]+sm[i+1];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		ll nl=1,nr=mid;
		ll cnt=Max;
		for(;nr<=n;nr++,nl++){
			ll qzh=sm[nl]-sm[nr]-(num[n]+1-num[nr])*(nr-nl);
			if(qzh<cnt){
				cnt=qzh;
			}
		}if(cnt==m){
			printf("%lld",mid); 
			return 0;
		}else if(cnt<m){
			l=mid;
		}else{
			r=mid;
		}if(l==r-1){
			break; 
		}
	}printf("%lld",l);
	return 0;
}

