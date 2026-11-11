// I love HanRui
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a[200005], t[30], Max = -1;
bool pa = 1;
char c[200005];
string s;
bool pd (string s1) {
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	return s1 == s2;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (a[i] != 1) pa = 0;
		for (ll j = 1; j <= a[i]; j++)
			s += c[i];
	}
	if (pd(s)) {
		cout << 0;
		return 0;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << min(a[1], a[2]);
		return 0;
	}
	return 0;
}
//10:07
