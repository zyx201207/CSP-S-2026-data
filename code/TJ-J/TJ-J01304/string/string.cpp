#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;
int n;
int a[MAXN], pos[MAXN];
char c[MAXN];
string s;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i], &c[i]);
		for (int j = 1; j <= a[i]; j++) s += c[i];
	}
	int mid = s.size() / 2, ans = 0;
	for (int i = 0, j = s.size() - 1; i < mid; i++, j--) {
		if (s[i] != s[j]) ans++;
	}
	printf("%lld", ans);
	return 0;
}

