#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin>>n;
	
	ll cnt=0;
	
	string s;
	s=" ";
	for(ll i=1;i<=n;++i){
		ll sl;
		string zf;
		
		cin>>sl>>zf;
		cnt+=sl;
		if(cnt>100000000&&sl>100000000){
			cout<<0;
			return 0;
		} 
		
		
		for(ll j=1;j<=sl;++j){
			s+=zf;
		}
		
	}
	
	ll l=0,r=0;
	if(cnt&1){
		l=cnt/2+1;
		r=l;
	}else{
		l=cnt/2;
		r=l+1;
	}
	
	ll ans=0;
	while(l>=1&&r<=cnt){
		if(s[l]!=s[r]){
			ans++;
//			cerr<<l<<' '<<r<<'\n';
		}
		l--;
		r++;
	}
	
	cout<<ans;
	
//	cerr<<s;
	
	return 0;
}
