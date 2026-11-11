#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	for(int i = 0; i < n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for(int j = 0; j < a; j++) {
			s += c;
		}
	}
	cout << s << endl;
	bool re_st = 1;
	for(int i = 1; i < s.size() - 1; i++) {
		if(s[i] != s[i - 1]) {
			re_st = 0;
		}
	}
	if(re_st) {
		cout << "0";
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < s.size() - 1; i++) {
		if(s[s.size() - i] != s[i]) {
			s[s.size() - i] = s[i];
			cnt++;
		}
		cout << s << endl;
	}
	cout << cnt;
	return 0;
}
