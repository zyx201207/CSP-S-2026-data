#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N];
char c[N];
int len;
struct node {
	int l, r;
	char c;
};
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; ++j) {
			s.push_back(c[i]);
		}
		len += a[i];
	}
	int mid = (len + 1) / 2;
	if (len % 2 == 1) {
		string s1 = s.substr(0, mid - 1);
		string s2 = s.substr(mid);
		reverse(s2.begin(), s2.end());
		int cnt = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) cnt++;
		}
		cout << cnt << endl;
	}
	else {
		string s1 = s.substr(0, mid);
		string s2 = s.substr(mid);
		reverse(s2.begin(), s2.end());
		int cnt = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}