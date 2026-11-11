#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, cm, ca;
char b;
int cn, s, s1;

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	cin >> n;
	vector<int> vec(n - 1);
	vector<char> c(n - 1);

	for (int i = 0; i <= n - 1; i++) {
		cin >> vec[i] >> c[i];
		cnt += vec[i];
		cm = vec[i];
		vector<char> ch(cnt);
		while (cm != 0) {
			for (int l = 0; l <= cnt - 1; l++) {
				ch[l] = c[i];
				cout << ch[l];
			}
			cm--;
		}
	}

	cout << cn;
	return 0;
}