#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,l;
ll a[N];
char c[N];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i){
		scanf("%lld %c",&a[i],&c[i]);
		l+=a[i];
		for(ll j=0;j<a[i];++j) s+=c[i];
	}
	ll ans=0;
	for(ll i=0;i<l/2;++i)
		if(s[i]!=s[l-i-1]) ++ans;
	printf("%lld",ans);
	return 0;
}

