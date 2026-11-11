#include <bits/stdc++.h>
using namespace std;
int a[35];
int flr = 30;
vector<string> st;

int n, m, ans = 0, mx = 0;
string binary(int a) {
	if (a < 2)
		return to_string(a % 2);
	return to_string(a % 2) + binary(a / 2)  ;
}

void desire(vector<string> &k) {
	for (string s : k) {
		int sz = s.size();

		for (int i = 0; i < sz; i++) {

			a[i] += s[i] - '0';
		}
	}

	for (int i = flr - 1; i >= 0; i--) {

		if (a[i] >= m) {
			flr = i;
			break;
		}
	}

	if (flr <= 0)
		return ;
	vector<string> q;

	for (int i = 0; i < k.size(); i++) {


		if (flr > k[i].size() or k[i][flr] == '0') {
			auto it = k.begin(), ite = k.begin();
			advance(it, i - 1);
			advance(ite, i);
			q.push_back(k[i]), k.erase(it, ite);
			i--;
		}
	}

	swap(q, st);

	if (k.size() > m)
		desire(k);
	return ;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	vector<string> v;
	string s;

	cin >> n >> m;

	for (int i = 0, a; i < n; i++) {

		cin >> a;
		v.push_back(binary(a));
	}

	desire(v);

	if (v.size() < m) {
		int ne = m - v.size();

		for (int i; i < ne; i++) {

			v.push_back(st[i]);
		}
	}

	for (string s : v) {
		int sz = s.size();

		for (int i = 0; i < sz; i++) {

			a[i] += s[i] - '0';
		}
	}

	for (int i = 30; i >= 0; i--) {

		ans += pow(2, i) * (a[i] >= m);
	}

	cout << ans;
	return 0;
}