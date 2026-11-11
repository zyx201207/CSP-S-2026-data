#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	ll cnt = 0 , sm = 0;
	ll n , num;
	string s , str , strt;
	cin >> n;
	for (ll i = 0 ; i < n ; i ++){
		cin >> num;
		cnt += num;
		cin >> s;
		for (ll j = 0 ;j < num ; j ++) str += s[0];
	} 
	
	for (ll i = cnt-1; i >= 0; i --){
		strt += str[i];
	}
	for (ll i =0 ;i < cnt ; i ++){
		if (str[i] != strt[i]) sm ++;
	}
	cout << sm / 2;
	return 0;
}
