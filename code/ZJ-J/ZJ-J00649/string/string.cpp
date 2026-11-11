#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
string s;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		char a;
		cin>>x>>a;
		for(ll j=1;j<=x;j++){
			s+=a;
		}
	}
	if(s.size()%2==0){
		ll l,r;
		l=s.size()/2-1;
		r=s.size()/2;
		while(l>=0&&r<s.size()){
			if(s[l]!=s[r]) ans++;
			l--;
			r++;
		}
	}
	else{
		ll l,r;
		l=s.size()/2;
		r=l;
		while(l>=0&&r<s.size()){
			if(s[l]!=s[r]) ans++;
			l--;
			r++;
		}
	}
	cout<<ans;
	return 0;
} 
