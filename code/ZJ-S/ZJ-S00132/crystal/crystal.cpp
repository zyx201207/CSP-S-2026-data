#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],s[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll l=1,r=1;
	ll ans=0;
	while(l<=n){
		while(r<=n&&a[r]*(r-l+1)-(s[r]-s[l-1])<=m)r++;
		ans=max(ans,r-l);
		l++;
	}
	cout<<ans;
	return 0;
}