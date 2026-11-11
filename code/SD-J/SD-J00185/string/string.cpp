#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ishw(string s){
	string tem=s;
	reverse(s.begin(),s.end());
	return tem==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll a;
	char c;
	string s;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}
	if(ishw(s)){
		cout<<0;
		return 0;
	}
	ll ans=0;
	ll l=1,r=s.size();
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
