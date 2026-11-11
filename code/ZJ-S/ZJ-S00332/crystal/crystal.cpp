#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=5*1e5+5;
ll n,m,a[num],dif[num],pre[num];
bool check(ll x){
	ll ans=1e18,chk=0;
	for(ll i=n;i>=x;--i){
		for(ll j=i-x+1;j<=i;++j){
			chk+=pre[i]-pre[j];
		}
		ans=min(ans,chk);
		chk=0;
	}
	return (ans<=m);
}
int main(){
	memset(pre,0,sizeof pre);
	memset(dif,0,sizeof dif);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m,&a[1],&a[2]);
	ll qps=a[2]-a[1];
	bool flg=true;
	for(ll i=3;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,less<ll>());
	for(ll i=3;i<=n;++i){
		if(qps!=a[i]-a[i-1])
			flg=false;
	}
	dif[0]=0;dif[1]=0;
	for(ll i=2;i<=n;++i)
		dif[i]=a[i]-a[i-1];
	pre[0]=0;pre[1]=0;
	for(ll i=2;i<=n;++i){
		pre[i]=pre[i-1]+dif[i];
	}
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else
			r=mid-1;
	}
	printf("%lld",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}