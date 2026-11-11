#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	ll a;
	char c;
};
ll n, num;
string s;
ll lenth;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	vector<node>v(n);

	for (int i = 0; i < n; i++) {

		cin >> v[i].a >> v[i].c;
	}

	bool ok = false;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < v[i].a; j++) {

			s += v[i].c;
			lenth += v[i].a;
		}
	}

	lenth = s.size();

	for (int i = 0; i < s.size() - 1 - i; i++) {

		for (int j = s.size(); j > 0 ; j--) {

			if (s[i] == s[s.size() - 1 - i]) {
				ok = true;
			}
		}

		if (ok == false)
			num++;
	}

	cout << num;
	return 0;
}
