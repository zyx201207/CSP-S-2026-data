#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll>vec(n);
	vector<ll>vac(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = i; j < n; j++) {
			char a = vec[j] + '0';
			if (s.find(a) > s.size()) {
				s += a;
			} else {
				s = s.substr(0, s.find(a));
				s += a;
			}
		}
		for (int j = 0; j < s.size(); j++) {
			int a = s[j] - '0';
			a--;
			vac[a]++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << vac[i] << " ";
	}
	return 0;
}