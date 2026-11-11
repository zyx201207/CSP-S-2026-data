#include <bits/stdc++.h>
using namespace std;
int n;
int a;
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	while (n--) {
		cin >> a >> s;

		for (int i = 1; i <= a; i++) {

			s1 += s;
		}
	}

	//cout << s1 << ' ';
	int len = s1.size();
	int ans = 0, art = 0;

	for (int i = 0; i  < (len - 1) / 2; i++) {

		if (s1[i] != s1[len - i - 1]) {
			ans++;
//			cout << s[i] << ' ' << i << endl;
		}


//		if (i > len / 2 + 1)
//			break;
	}

	for (int i = len - 1 ; i >= (len - 1) / 2 ; i--) {

		if (s1[i] != s1[len - i - 1]) {
			art++;
//			cout << s[i] << ' ' << i << endl;
		}

//		if (i < len / 2 - 1)
//			break;
	}

	cout << min(ans, art);
	return 0;
}