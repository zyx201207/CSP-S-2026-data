#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2*(1e5)+10;
ll n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	ll sum = 0;
	for(ll i = 1; i <= n; i++){
		ll num;
		cin >> num;
		sum += num;
		char c1;
		cin >> c1;
		for(ll j = 1; j <= num; j++){
			s = s + c1;
		}
	}
	ll l=0, r=sum-1;
	ll cnt = 0;
	while(l<=r){
		if(s[l] != s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
