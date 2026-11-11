#include <bits/stdc++.h>
using namespace std;

//bool wen (string s) {
//	int f = 1;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] != s[s.size() - i - 1]) {
//			f = 0;
//		}
//	}
//	return f;
//}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int a[200005], n;
	char b[100005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	cout << a[0];
	return 0;
}