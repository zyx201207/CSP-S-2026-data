#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t;
ll n,d;
ll a[N];
ll f(ll x){
	for(ll i=1;i<=n;++i){
		if(a[i]<=x&&a[i+1]>x){
			return i;
		}
	}
}
ll g(ll x){
	for(ll i=1;i<=n;++i){
		if(a[i]<x&&a[i+1]>=x){
			return i+1;
		}
	}
}
bool cmp(ll x){
	for(ll i=1;i<=n;++i){
		if(a[i]==x){
			return true;
		}
		if(a[i]>x){
			return false;
		}
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(ll i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		ll ans=0;
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d||(a[j]-a[i])%d==0){
					continue;
				}
				int cnt=0;
				if((a[j]-a[i]+1)%d==0){
					ll x=(a[j]-a[i]+1)/d;
					for(ll flag=1;flag<=x;++flag){
						ll temp=a[i];
						for(ll k=1;k<=x;++k){
							if(k==flag){
								temp+=d-1;
							}
							else{
								temp+=d;
							}
							if(!cmp(temp)){
								--cnt;
								break;
							}
						}
						++cnt;
					}
				}
				else if((a[j]-a[i]+2)%d==0){
					ll x=(a[j]-a[i]+2)/d;
					for(ll flag=1;flag<=x;++flag){
						ll temp=a[i];
						for(ll k=1;k<=x;++k){
							if(k==flag){
								temp+=d-2;
							}
							else{
								temp+=d;
							}
							if(!cmp(temp)){
								--cnt;
								break;
							}
						}
						++cnt;
					}
					for(ll flag=1;flag<=x;++flag){
						for(ll p=flag+1;p<=x;++p){
							ll temp=a[i];
							for(ll k=1;k<=x;++k){
								if(k==flag||k==p){
									temp+=d-1;
								}
								else{
									temp+=d;
								}
								if(!cmp(temp)){
									--cnt;
									break;
								}
							}
							++cnt;
						}
					}
				}
				if(cnt==2){
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}                