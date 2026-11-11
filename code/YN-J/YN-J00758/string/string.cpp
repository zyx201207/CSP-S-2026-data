#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n;
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		char c, cc;
		cin >> x >> c;


		for (int j = 1; j <= x; j++) {
			s = s + c;
		}


	}
	long long L = s.size();
	long long cnt = 0;
	//cout << s;
	for (int i = 0; i < L; i++) {
		if (s[i] != s[L - i - 1]) {
			cnt++;
			//cout << i << ' ' << L - i + 1 << "\n";
		}
	}
	cout << cnt;
	return 0;
}