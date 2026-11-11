#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s;
	for (long long i = 0; i < n; i++) {
		long long a;
		char b;
		cin >> a >> b;
		s += string(a, b); 
	}
	long long ans = 0;
	long long l = s.size();
	for (long long i = 0; i < l / 2; i++) {
		if (s[i] != s[l - i - 1]) ans++;
	}
	cout << ans << endl;
	return 0;
}
