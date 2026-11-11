#include <iostream>
#include <string>
using namespace std;

string s = "";

int main() {
	int n, a;
	char c;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long cntall = 0;
	int bani;
	for(int i = 0; i < n; i++) {
		cin >> a >> c;
		for(int j = 0; j < a; j++) {
			s += c;
		}
	}
	int l = s.size();
	int cnt = 0;
	for(int i = 0; i < l / 2; i++) {
		if(s[i] != s[l - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
