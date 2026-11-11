#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
bool f(string s){
	string s1 = s;
	reverse(s1.begin(), s1.end());
	return s1 == s;
}
ll n, _;
pair<ll, char> s1[200005];
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	int pos = 0;
	for (ll i = 0; i < n; i++){
		ll x;
		char c;
		scanf("%lld %c", &x, &c);
		if (pos != 0 && c == s1[pos - 1].second) s1[--pos].first += x;
		else s1[pos].first = x, s1[pos].second = c;
		pos++;
	}
	_ = __gcd(s1[0].first, s1[1].first);
	for (ll i = 2; i < n; i++) _ = __gcd(_, s1[i].first);
	for (ll i = 0; i < n; i++){
		ll x = s1[i].first / _;
		while (x--) s += s1[i].second;
	}
	if (f(s)){
		printf("0\n");
		return 0;
	}
	ll ans = 0;
	if (s.size() % 2){
		for (ll i = 0; i < (s.size() - 1) / 2; i++) if (s[i] != s[s.size() - i - 1]) ans++;
	} else {
		for (ll i = 0; i < s.size() / 2; i++) if (s[i] != s[s.size() - i - 1]) ans++;
	}
	printf("%lld\n", ans * _);
	return 0;
}
