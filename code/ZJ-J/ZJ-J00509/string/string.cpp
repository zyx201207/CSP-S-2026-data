#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	
	string s, c;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	
	int cnt = 0, e = s.size();
	for (int i = 0; i < e / 2; i++) {
		if (s[i] != s[e - i - 1]) cnt++;
	}
	
	cout << cnt << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}