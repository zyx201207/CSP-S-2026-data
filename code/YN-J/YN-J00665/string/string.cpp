#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
int n, sum, cnt;
char s[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		scanf("%d", &x);
		cin >> c;
		for (int j = 1; j <= x; j++)
			s[++cnt] = c;
	}
	for (int i = 1; i <= cnt / 2; i++)
		if (s[i] != s[cnt + 1 - i])
			sum++;
	cout << sum << endl;
	return 0;
}