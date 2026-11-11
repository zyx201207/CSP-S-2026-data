#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s="";
ll ans=0;
bool huiwen(string p){
	ll len=p.size();
	string a="";
	for(ll i=len-1;i>=0;i--){
		a+=p[i];
	}
	if(p==a) return true;
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		ll a;
		char c;
		cin>>a>>c;
		while(a--)
			s+=c;
	}
	if(huiwen(s)){
		cout<<0<<endl;
		return 0;
	}
	ll slen=s.size(),lo=floor(slen/2);
	for(ll i=0;i<slen;i++){
		if(i==lo)
		    break;
        if(s[i]!=s[slen-1-i]){
			s[slen-1-i]=s[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
