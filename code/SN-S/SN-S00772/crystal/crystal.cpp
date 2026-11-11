#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long

long long n, m;
long long a[N];
long long sum[N];

inline int read() {
	char ch = getchar();
	int ans = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

bool cmp(const int a, const int b) {
	return a > b;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	long long answer = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[mid] * (mid - i) - (sum[mid - 1] - sum[i - 1]) <= m) {
				answer = max(answer, mid - i + 1);
				l = mid + 1;
			} else {
				r = mid;
			}
		}
	}
	cout << answer << '\n';
	
	return 0;
}
