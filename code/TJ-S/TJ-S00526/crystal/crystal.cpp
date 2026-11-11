#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+1;
ll n,m,a[N],ans=-1,c[N];
bool f1=true,f2=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)f1=false;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		c[i]=abs(a[i]-a[i-1]);
		if(i!=1&&c[i]!=c[i-1])f2=false;
	}
	if(f1){
		for(ll i=1;i<=n;i++)
			if(i*(i-1)>m*2){
				printf("%lld",i-1);
				return 0;
			}
		printf("%lld",n);
		return 0;
	}else if(f2){
		for(ll i=1;i<=n;i++)
			if(c[2]*i*(i-1)>m*2){
				printf("%lld",i-1);
				return 0;
			}
		printf("%lld",n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll e=0,cnt=1;
		for(int j=i;j<n;j++){
			if(e+c[j+1]*cnt>m) break;
			else e+=c[j+1]*cnt++;
			}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

