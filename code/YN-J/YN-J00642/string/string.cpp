#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a;
	char b;
	string s = "";
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		string cx(a, b);
		s = s + cx;
	}
	int l = s.size();
	int xg = 0;
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - i - 1])
			xg++;
	}
	cout << xg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}