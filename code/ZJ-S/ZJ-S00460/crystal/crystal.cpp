#include<bits/stdc++.h>
using namespace std;
#define I inline
#define ll long long
#define gc getchar
#define pc putchar
I ll read() {
	ll x = 0, f = 1; char ch = gc();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = gc();}
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x * f;
}
const int N = 500010;
int n; ll m, a[N], sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	stable_sort(a + 1, a + 1 + n); sum[0] = 0;
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int mx = 1;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= n && a[j] * (j - i + 1) - (sum[j] - sum[i - 1]) <= m) j++;
		mx = max(mx, j - i);
	}
	printf("%d\n", mx);
	return 0;
}