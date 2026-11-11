#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;

ll n;
string s = "";
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int ptr = 1;
	ll sum = 0;
	int a;
	char c;
	int flag = 0;

	for (ll i = 1; i <= n; i++) {

		cin >> a >> c;
		int ls = s.size();

		if (a > 1000) {
			flag = 1;
		}

		if (flag) {
			a /= 1000;
		}

		for (int j = 1; j <= a; j++) {

			s += c;
		}
	}

	int ls = s.size();
	ll cnt = 0;

	if (ls % 2 == 0) {
		for (int i = 0; i < ls / 2; i++) {

			if (s[i] != s[ls - i - 1]) {
				cnt++;
			}
		}
	} else {
		for (int i = 0; i <= ls / 2; i++) {

			if (s[i] != s[ls - i - 1]) {
				cnt++;
			}
		}
	}



	if (flag) {
		cnt *= 1000;
	}

	cout << cnt;
	return 0;
}

