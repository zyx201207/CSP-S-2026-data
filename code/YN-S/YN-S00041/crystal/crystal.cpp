#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], b[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, maxi = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int sum = 0, ans = 0;
		memset(b, 0, sizeof(b));
		for (int j = i; j <= n; j++) {
			sum = sum + a[i] - a[j];
			if (sum > m)
				break;
			else
				++ans;
		}
		maxi = max(maxi, ans);
	}
	cout << maxi;
	return 0;
}