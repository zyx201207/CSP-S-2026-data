#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		string t;
		cin>>x>>t;
		for(ll j=1;j<=x;j++){
			s+=t;
		}
	}
	ll ls=s.size();
	for(ll i=0,j=ls-1;i!=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
