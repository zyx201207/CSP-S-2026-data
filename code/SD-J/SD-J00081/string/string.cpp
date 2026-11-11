#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, s1, s2, s3;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, sz = 0;
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++){
		ll m;
		string c;
		cin >> m >> c;
		sz += m;
		for(ll j = 1; j <= m; j++){
			s += c;
		}
	}
	for(ll i = 1; i <= sz; i++){
		s1 += s[sz - i];
	}
	for(ll i = 0; i < sz/2; i++){
		s2 += s1[i];
	}
	for(ll i = sz/2; i < sz; i++){
		s2 += s[i];
	}
	for(ll i = 0; i < sz/2; i++){
		s3 += s[i];
	}
	for(ll i = sz/2; i < sz; i++){
		s3 += s1[i];
	}
	ll ans1 = 0, ans2 = 0;
	for(ll i = 0; i < sz; i++){
		if(s[i] != s3[i])ans1++;
	}
	for(ll i = 0; i < sz; i++){
		if(s[i] != s2[i])ans2++;
	}
	cout << min(ans1, ans2);
	return 0;
}
