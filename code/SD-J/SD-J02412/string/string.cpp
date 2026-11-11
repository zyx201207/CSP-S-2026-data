#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll t;
		char c;
		cin>>t>>c;
		for(ll j=1;j<=t;j++){
			s+=c;
		} 
	}
	ll len=s.size();
	ll len1=len/2;
    ll ans=0;
	for(ll i=0;i<len1;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
