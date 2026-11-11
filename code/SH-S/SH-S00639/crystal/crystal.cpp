#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
ll n,m,a[N],s[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1,j=1;i<=n;i++){
		while(j<i&&(a[i]*(i-j+1)-(s[i]-s[j-1]))>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld\n",ans);
	return 0;
} 
