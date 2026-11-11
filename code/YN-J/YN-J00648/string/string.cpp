#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5 + 5;
long long int a[N];
char c[N];
string str1, str2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			str1 += c[i];
		}
	}
	for (int i = str1.size() - 1; i >= 0; i--) {
		str2 += str1[i];
	}
	if (str1 == str2) {
		cout << 0;
		return 0;
	}
	int sum = 0;
	int len = (str1.size() + 1) / 2;
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i])
			sum++;
	}
	cout << sum;
	return 0;
}