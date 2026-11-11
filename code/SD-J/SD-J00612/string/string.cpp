#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
string s;
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	ll lens=0;
	for(ll i=1;i<=n;i++){
		ll ai;
		char ci;
		cin>>ai>>ci;
		lens+=ai;
		for(ll j=1;j<=ai;j++){
			s+=ci;
		}
	}
	ll cnt=0;
	for(ll i=(lens+1)/2-1;i>=0;i--){
		ll j=lens-1-i;
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
