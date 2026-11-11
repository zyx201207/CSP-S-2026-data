#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s2;
	int s = 0;

	for (int i = 0; i < n; i++) {

		int a;
		string s1;
		cin >> a >> s1;

		for (int j = i + s; j < a + s; j++) {

			s2[j] = s1[i];
			s = a;
		}
	}

	cout << 0;
	return 0;
}
