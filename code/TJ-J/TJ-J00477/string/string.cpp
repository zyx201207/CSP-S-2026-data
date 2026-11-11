#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,knd=0;
    cin>>n;
    char x='A';
    string s="";
    while(n--){
    	ll a;
    	char c;
    	cin>>a>>c;
		if(x!=c){
    		x=c;
    		knd++;
		} 
    	for(ll i=0;i<a;i++) s+=c;
	}	
	if(knd==1){
		cout<<0;
		return 0;
	}
	int ans=0; 
	ll l=0,r=s.size()-1;
	ll mid=(l+r)/2;
	while(l<=mid){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
