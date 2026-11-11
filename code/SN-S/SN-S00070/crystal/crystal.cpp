#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long n, m, a[1000000];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	ll x = a[n / 2];
	ll a2[100000] = {};
	for(ll i = 0; i < n; i ++){
		a2[i] = max(a[i] - x, x - a[i]);
	}
	sort(a2, a2 + n);
	ll tmp = 0;
	for(ll i = 0; i < n; i ++){
		if(tmp + a2[i] <= m){
			tmp += a2[i];
		}else{
			cout << i;
			break;
		}
	}
	return 0;
} 
