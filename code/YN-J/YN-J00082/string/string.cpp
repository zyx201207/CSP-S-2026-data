#include <bits/stdc++.h>
using namespace std;
int n;
string str = "";
string a = "";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int minn = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			str += y;
		}
	}
	int len = str.size(); //abcd
	for (int i = 0; i < len; i++) {
		if (len % 2 == 0 && i == len / 2) {
			a += '#';
		}
		a += str[i];
	}
	int len2 = a.size();
	int mid = len2 / 2;
	int cnt = 0;
	for (int i = 1; (mid + i < len2) && (mid - i >= 0); i++) {
		if (a[mid + i] != a[mid - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}