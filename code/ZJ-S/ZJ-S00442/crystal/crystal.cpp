#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,mans;
ll a[500010];
bool cmpp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmpp);
	for(ll i=1;i<=n;++i){
		int beg=i,le=m;
		ans=1;
		while(i<=n && a[i+1]==a[i]){
			++ans;++i;
		}
		for(ll j=beg-1;j>=1;--j){
			if(le>=a[beg]-a[j]){
				le-=(a[beg]-a[j]);
				++ans;
			}
			else break;
		}
		if(ans>mans) mans=ans;
	}
	printf("%lld",mans);
	fclose(stdin);fclose(stdout);
	return 0;
}