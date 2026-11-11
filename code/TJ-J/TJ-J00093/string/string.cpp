#include <bits/stdc++.h>
using namespace std;
string s = "";
using ll = long long;
ll n,a,ans = 0;char c;
bool ishuiwen(string s){
	for(ll i = 0;i<=s.length()/2-1;i++){
		if(s[i]!=s[s.length()-1-i])return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i = 1;i<=n;i++){
		cin>>a>>c;
		for(ll j = 1;j<=a;j++){
			s+=c;
		}
	}
	if(ishuiwen(s)==true){
		cout<<0;return 0;
	}
	for(ll i = 0;i<=s.length()/2-1;i++){
		if(s[i]!=s[s.length()-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
