#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll ans;
	if(n==m){
		for(ll i = 1;i<n;i++)
			a[i]&=a[i+1];
		printf("%lld",a[n-1]);
		return 0;
	}
	if(m == 2)
		for(ll i = 1;i<=n;i++){
			for(ll j = i+1;j<=n;j++)
				ans = max(ans,a[i]&a[j]);
		}
	printf("%lld",ans);
	return 0;
}
