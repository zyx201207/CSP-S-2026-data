#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,a[30],b[30],ans,con;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	if(T % 2) {
		for(ll i = 1; i <= T / 2; i++) {
			ll k;
			char c;
			cin >> k >> c;
			a[c - 97] += k;
		}
		ll k;
		char c;
		cin >> k >> c;
		for(ll i = T / 2 + 2; i <= T; i++) {
			ll k;
			char c;
			cin >> k >> c;
			b[c - 97] += k;
		}
	} else {
		for(ll i = 1; i <= T / 2; i++) {
			ll k;
			char c;
			cin >> k >> c;
			a[c - 97] += k;
		}
		for(ll i = T / 2 + 1; i <= T; i++) {
			ll k;
			char c;
			cin >> k >> c;
			b[c - 97] += k;
		}
	}
	for(ll i = 0; i < 26; i++) {
		if(a[i] > b[i]) ans += a[i] - b[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
