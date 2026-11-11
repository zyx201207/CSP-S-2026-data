#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],maxx;
map<ll,ll> mp;
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(abs(a[i])>2500) flag=1;
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int l=i-1;
			ll w=m,ans=1;
			while(w>=abs(a[l]-a[i])&&l>=1) w-=abs(a[l]-a[i]),l--,ans++;
			maxx=max(maxx,ans);
		}
		printf("%lld",maxx);
	}
	else if(flag==0){
		for(int i=1;i<=n;i++) mp[a[i]]++;
		for(ll i=-2500;i<=2500;i++){
			if(mp.count(i)){
				ll w=m,ans=0;
				for(ll j=i;j>=-2500;j--){
					if(mp.count(j)){
						if(w>=(abs(j-i)*mp[j])) w-=abs(j-i)*mp[j],ans+=mp[j];
						else ans=ans+w/abs(i-j),w=0;
					}
				}
				maxx=max(maxx,ans);
			}
		}
		printf("%lld",maxx);
	}
	else{
		ll k=abs(a[2]-a[1]),sum=m/k,ans=1;
		while(m>=(k*ans)) m-=(k*ans),ans++;
		printf("%lld",ans);
	}
	return 0;
}
