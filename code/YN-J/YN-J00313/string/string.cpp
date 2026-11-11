#include <bits/stdc++.h>
using namespace std;
int n, sum = 1;
long long ans;
char s[100000005];

void push(char a) {
	s[sum] = a;
	sum++;
}

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int len;
		char a;
		cin >> len >> a;
		for (int j = 1; j <= len; j++)
			push(a);
	}
	sum--;
	for (int i = 1, j = sum; i < j; i++, j--) {
		if (s[i] != s[j])
			ans++;
	}
	cout << ans;

	return 0;
}