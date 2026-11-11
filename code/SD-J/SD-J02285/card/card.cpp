#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll A[m]={0},B[n]={0};
	for(ll i=0;i<n;i++){
		scanf("%lld",&A[i]);
	} 
	for(ll h=1;h<=m;h++){
		ll d=0;
		for(int k=1;k<=m;k++){
			ll len=0;
			for(ll i=h-1;i<m;i++){
				bool q=false;
				for(int j=0;j<len;j++){
					if(B[j]==k){
						len=j;
						break;
					}
				}
				B[len++]=A[i];
			}
			ll ans=0;
			for(ll i=h-1;i<len;i++){
				if(B[i]==k){
					ans++;
				}
			} 
			d+=ans;
		}
		printf("%lld\n",d);
	}
	return 0;
} 
