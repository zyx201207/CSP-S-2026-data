#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%lld",&n);
	string s = " ";
	ll l = 0;
	for(ll i = 0;i<n;i++){
		ll a;
		string c;
		scanf("%lld",&a);
		cin >> c;
		l+=a;
		for(ll i = 1;i<=a;i++)
			s += c;
	}
	ll ans=0;
	ll m;
	if(l%2==0){
		if(s[l/2]!=s[l/2+1])
			ans++;
		m = l/2-1;
	}
	else
		m = (l+1)/2;
	for(ll i = 1;i<m;++i)
		if(s[i]!=s[l-i+1])
			ans++;
	printf("%lld\n",ans);
	return 0;
}
