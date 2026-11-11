#include <bits/stdc++.h>
using namespace std;
const int A = 1e9 + 199999990;
int n, a, len = 1, sum;
char c, s[A];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			len++;
			s[len - 1] = c;
		}
	}
	cout << len << " ";
	int le = len - 1 ;
	le /= 2;
	sum = 0;
	for (int l = 1; l <= le ; l++) {
		int r = len - l ;
		if (s[l] != s[r]) {
			sum++;
		}
	}

	cout << sum ;

	fclose(stdin);
	fclose(stdout);
	return 0;
}