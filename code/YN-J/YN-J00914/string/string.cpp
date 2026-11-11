#include <bits/stdc++.h>
using namespace std;
string s, b;
long long l, r, n, x[100005], count;
int t;

int isit(long long L, long long R, string B) {
	while (L < R) {
		if (B[L] != B[R]) {
			return 1;
		}
		L++;
		R--;
	}
	return 0;
}

long long best(string A, long long cnt) {
	if (isit(1, A.size(), A) == 0) {
		return cnt;
	}
	for (int i = A.size(); i >= 1; i--) {
		for (int j = i; j >= A.size(); j--) {
			A[j] = A[i];
			cnt++;
		}
	}
	return best(A, 0);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> s[i];
		for (int j = x[i]; j > b.size(); j--) {
			b[j] = s[i];
		}
	}
	l = 1;
	r = b.size();
	t = isit(l, r, b);
	cout << t;
	if (t != 0) {
		cout << best(b, 1);
	} else {
		cout << 0;
	}
	return 0;
}