#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<char>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0<<endl;
		return 0;
	}
	ll l=0;
	s.push_back(' ');
	for(int i=1;i<=n;i++){
	 	int x;cin>>x;
	 	l+=x;
		char q;cin>>q;
		for(int j=0;j<x;j++){
			s.push_back(q);
		}
	}
	ll ans=0;
	for(ll i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i])ans++;    
	}
	cout<<ans<<endl;
	return 0;
}