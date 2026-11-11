#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string str = "";
	while (n--) {
		long long v;
		char t;
		cin >> v;
		cin >> t;
		string s = "";
		for (long long i = 1; i <= v; i++) {
			s = s + t;
		}
		str = str + s;
	}
	string str2 = "";

	for (long long i = str.size() - 1; i >= 0; i--) {
		str2 = str2 + str[i];
	}
	int ans = 0;
	long long j = str.size() - 1;
//	cout << str << " " << str2;
	if (str == str2) {
		cout << 0;
		return 0;
	} else {
		for (long long i = 0; i < str.size() / 2 + 1; i++) {

			if (str[i] != str[j]) {
//				cout << str[i] << " " << str[j] << "\n";
				ans++;
			}
			j--;

		}
	}
	cout << ans;








	return 0;
}