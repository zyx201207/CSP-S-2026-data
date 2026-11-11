#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen(stdin,"r",string.in);
	freopen(stdout,"w",string.out);
	ll n;
	cin >> n;
	ll x;
	char q;
	ll ans=0;
	string s;
	while(n--){
		cin >> x >> q;
		for(int i=0;i<x;i++){
			s+=q;
		}
	}
	ll len=s.size();
	ll j=0;
	for(int i=len-1;i>=len/2;i--){
		if(s[i]!=s[j]){
			s[i]=s[j];
			ans++;
		}
		j++;
	}
	cout << ans;
	return 0;
}

