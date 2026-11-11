#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m; scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1; ll S=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		S+=1ll*(i-l)*(a[i]-a[i-1]);
		while(S>m){
			S-=(a[i]-a[l]); l++;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
