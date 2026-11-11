#include <bits/stdc++.h>
#include <string>
using namespace std;
string str = "";
long long cnt = 0;
string str2;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	cout << str;
	for (int i = 0; i < n; i++) {
		long long temp;
		char c;
		cin >> temp >> c;
		for (long long j = 0; j < temp; j++) {
			str += c;
//			cout << str;
		}
	}
//	cout << str << endl;
	int cc = str.size();
	for (int i = 0; i < cc; i++) {
		str2[cc - i] = str[i];
	}
	for (int i = 0; i < n; i++) {
		if (str2[cc - i] != str[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}