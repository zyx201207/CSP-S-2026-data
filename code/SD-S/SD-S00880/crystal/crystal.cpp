#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+10;
int n;
ll m, a[N], s[N];

bool check(int mid) {
	for(int l = 1; l + mid - 1 <= n; l++) {
		int r = l + mid - 1;
		if(1LL * mid * a[r] - (s[r] - s[l - 1]) <= m)
			return true;
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i]; 
	int L = 0, R = n, ans = 0;
	while(L <= R) {
		int M = (L + R) / 2;
		if(check(M)) L = M + 1, ans = M;
		else R = M - 1;
	}
	printf("%d\n", ans);
	return 0;
}
