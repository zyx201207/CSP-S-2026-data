#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;char o;
		cin>>a>>o;
		while(a--){
			s+=o;
		}
	}
	ll ans=0;
	s=' '+s;
	for(int i=1;i<s.length();i++){
		if(s[i]!=s[s.length()-i]) ans++;
	}
	cout<<ans/2;
	return 0;
}

