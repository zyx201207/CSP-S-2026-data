//string
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n , ans = 0;
	cin >> n;
	if (n==0){
		cout << 0;
		return 0;
	}
	vector<ll> a;
	vector<char> c;
	string s;
	for (ll i = 1;i <= n;i++){
		ll ta;
		char tc;
		cin >> ta >> tc;
		if (!a.empty()){
			if (c.back()==tc){
				a.back() += ta;
			}else {
				a.push_back(ta);
				c.push_back(tc);
			}
		}else {
			a.push_back(ta);
			c.push_back(tc);
		}
	}
	ll len = a.size();
	int nowl = 0 , nowr = len-1;
	while (nowl != nowr){
		if (c[nowl] == c[nowr]){
			if (a[nowl] >= a[nowr]){
				a[nowl] -= a[nowr];
				a[nowr] = 0;
				nowr -= 1;
			}else {
				a[nowr] -= a[nowl];
				a[nowl] = 0;
				nowl += 1;
			}
		}else {
			if (a[nowl] >= a[nowr]){
				a[nowl] -= a[nowr];
				ans += a[nowr];
				a[nowr] = 0;
				nowr -= 1;
			}else {
				a[nowr] -= a[nowl];
				ans += a[nowl];
				a[nowl] = 0;
				nowl += 1;
			}
		}
	}
	cout << ans;
	return 0;
} 
