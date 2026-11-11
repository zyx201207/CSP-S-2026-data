#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

bool check(string f) {
	int tf = 0;
	for (int i = 0; i < f.size() / 2; i++) {
		if (f[i] != f[f.size() - i - 1]) {
			tf++;
			return 0;
		}
	}
	if (tf == 0) {
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s, s1;
	ll n, a;
	char c;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a;
		cin >> c;
		for (ll j = 0; j < a; j++) {
			s += c;
			s1 += c;
		}
	}
	int ji = 0;
	if (check(s) == 0) {
		for (ll i = 0; i < s.size() / 2; i++) {
			s1[i] = s[i];
			s1[s.size() - i - 1] = s[i];
		}
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] != s1[i]) {
				ji++;
			}
		}
	}
	cout << ji;
	return 0;
}