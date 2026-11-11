#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		ll k=m;
		ll cnt=1;
		for(ll j=i-1;j>=1;j--){
			ll x=a[i]-a[j];
			if(x<=k) k-=x,cnt++;
			else break;
		}ans=max(ans,cnt);
	}printf("%d",ans);
	return 0;
}

