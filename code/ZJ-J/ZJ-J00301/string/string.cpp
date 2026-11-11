#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		s+=string(x,c);
	}
	for(ll i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}

