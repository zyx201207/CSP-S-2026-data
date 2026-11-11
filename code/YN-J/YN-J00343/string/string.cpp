#include <bits/stdc++.h>
using namespace std;
long long n;
long long sum, m[200005];
string a, c;
char b[200005];
long long cnt, l;

int main() {
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> m[i];
		cin >> b[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m[i]; j++) {
			a[j + cnt] = b[i];
		}
		cnt += m[i];
		l += m[i];
	}
	long long top = l;
	for (long long i = 1; i <= l; i++) {
		if (a[i] == a[top]) {
			cout << sum;
			return 0;
		} else {
			sum++;
		}
		top--;
	}
	cout << sum;
	return 0;
}