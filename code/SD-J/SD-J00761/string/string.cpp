#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100005];
char c[100005];
ll ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	char x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cin >> c[i];
	}
	int l = 0, r = n - 1;
	while (r > l) {
		int d = min(a[l], a[r]);
		if (c[l] != c[r]) ans += d;
		a[l] -= d;
		a[r] -= d;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	printf("%lld", ans);
	
	return 0;
}
