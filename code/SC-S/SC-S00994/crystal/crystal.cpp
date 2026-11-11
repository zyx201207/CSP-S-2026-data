#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m, sum = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int cnt = -99999;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		long long b = (sum + m) / i;
		if (b < a[i])break;
		long long ans = i;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == b)ans++;
		}
		if (cnt < ans)cnt = ans;
	}
	printf("%d", cnt);
	return 0;
}