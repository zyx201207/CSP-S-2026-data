#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=2e5+5,M=1e9;
ll n,l;
char s[N];

struct letter{
	ll a;
	char c;
}m[N]; 

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){cout<<0;return 0;}
	for(ll i=1;i<=n;i++){
		ll _a_;
		char _c_;
		cin>>_a_>>_c_;
		m[i].a=_a_;
		m[i].c=_c_;
		for(int j=1;j<=m[i].a;j++)s[++l]=m[i].c;
	}
	l=0;
	for(ll i=1;i<=n;i++)l+=m[i].a;
	bool p=true;
	for(ll i=1;i<=(l+(l%2==0?0:1))/2;i++)if(!(s[i]==s[l+1-i]))p=false;
	if(p){cout<<0;return 0;}
	if(l%2!=0){
		ll ans=0;
		for(ll i=1;i<=(l+1)/2;i++)if(!(s[i]==s[l+1-i]))ans++;
		cout<<ans;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=l/2;i++)if(!(s[i]==s[l+1-i]))ans++;
		cout<<ans;
	}
	return 0;
}
