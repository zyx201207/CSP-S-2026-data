#include <iostream>
#include <cstdio>
#include <string>
#define ll long long
using namespace std;
ll n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for (ll j=1;j<=a;j++){
			s+=c;
		}
	}
	ll ans=0;
	for (ll i=0;i<s.size()/2;i++){
		if (s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
