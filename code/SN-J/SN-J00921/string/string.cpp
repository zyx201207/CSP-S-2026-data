#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0;
	string s;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j=0;j<a;j++){
			s+=c;
		}
	}
	ll r=0,l=s.size()-1;
	while(r<l){
		if(s[r]!=s[l]){
			ans++;
		}r++;
		l--;
	}cout<<ans;
	return 0;
}
