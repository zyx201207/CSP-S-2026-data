#include <bits/stdc++.h>
using namespace std;
char a [200010];
int c [200010];
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	long long t = 0;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> c [i] >> a [i];
	}
	int l = 1;
	int r = n;
	while (l < r) {
		if (a [l] == a [r]) {
			if (c [l] < c [r]) {
				c [r] -= c [l];
				l ++;
			}
			else if (c [l] == c [r]) {
				l ++;
				r --;
			}
			else {
				c [l] -= c [r];
				r --;
			}
		}
		else {
			if (c [l] > c [r]) {
				t += c [r];
				c [l] -= c [r];
				r --;
			}
			else if (c [l] == c [r]) {
				t += c [r];
				l ++;
				r --;
			}
			else {
				t += c [l];
				c [r] -= c [l];
				l ++;
			}
		}
	}
	cout << t;
	return 0;
} 
