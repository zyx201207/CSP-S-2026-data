#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
string a;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int le;
		char letter;
		cin >> le >> letter;
		for (int j = 1; j <= le; j++) {
			a += letter;
		}
	}
	int la = a.length();
	int l = 0, r = la - 1;
	bool flag = true;
	long long cnt = 0;
	while (l <= r) {
		if (a[l] != a[r]) {
			flag = false;
			cnt++;
		}
		l++;
		r--;
	}
	if (flag) {
		cout << 0 ;
	} else {
		cout << cnt;
	}
	return 0;
}