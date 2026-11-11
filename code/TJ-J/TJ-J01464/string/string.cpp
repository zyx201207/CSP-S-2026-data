#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,c=0;
	cin >> n;
	string a;
	while(n--){
		ll x;
		char r;
		cin >> x >> r;
		for (ll i = 1; i<= x; i++){
			a+=r;
		}
	}
	n=a.size();
	ll l = a.size()-1;
	for (ll i = 0; i < n/2; i++,l--){
		if (a[i]!=a[l]){
			a[l]=a[i];
			c++;
		}		
	}
	cout << c;
	return 0;
}
