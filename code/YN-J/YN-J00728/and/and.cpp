#include <bits/stdc++.h>
using namespace std;

int n, m, a[20001];
string s;

void er(int x) {
	int shang, i;
	string S;
	while (x >= 0) {
		S[i] = x % 2;
		x /= 2;
		i++;
	}
	int j = 0;
	for (int i = S.size(); i >= 1; i--) {
		++j;
		s[j] = s[i];
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	er(a[1]);
	for (int i = 1; i <= s.size(); i++)
		cout << s[i];

	fclose(stdin);
	fclose(stdout);
	return 0;
}