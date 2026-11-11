#include <bits/stdc++.h>
using namespace std;
string s, s1;
int n, l, cnt;
//vector <char> s, s1;
//const int N = 2e5, AMAX = 1e9;
//char s[N * AMAX], s1[N * AMAX];
int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	char c;
	cin >> n;
//	int k = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> l >> c;
//		for (int j = 0; j < l; j++) s.push_back(c);
//	}
	for (int i = 0; i < n; i++) {
		cin >> l >> c;
		for (int j = 0; j < l; j++) s += c;
	}
//	for (int j = 0; j < s.size(); j++) cout << s[j];
//	cout << endl;
	s1 = s;
	reverse(s.begin(), s.end());
//	for (int j = 0; j < s.size(); j++) cout << s[j];
//	cout << endl;
//	for (int j = 0; j < s.size(); j++) cout << s[j];
//	cout << endl;
	for (long long i = 0; i < s.size() / 2; i++) if (s[i] == s1[i]) cnt++;
	printf ("%d\n", s.size() / 2 - cnt);
	return 0;
}
