#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n;
ll a;
char c;
string s;
ll sz;
ll cnt;
bool isp(string t){
	string tt=t;
	reverse(t.begin(),t.end());
	if(t==tt) return 1;
	return 0;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		sz+=a;
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}
	ll l=0,r=sz-1;
	while(l<=r){
		if(isp(s)){
			cout<<cnt;
			return 0;
		}
		if(s[l]==s[r]){
			l++,r--;
		}
		while(s[l]!=s[r]&&l<=r){
			cnt++;
			l++,r--;
		}
	}
	cout<<cnt;
	return 0;
}