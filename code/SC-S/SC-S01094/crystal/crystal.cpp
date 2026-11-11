#include<bits/stdc++.h>
using namespace std;

long long n, m, k = LONG_LONG_MAX, kw, kw1, m1, k1;
long long a[500001];
long long c[5001][5001], sum[500001], sum0[500001];

bool cmp(int x, int y) {
	if(x>0 || y>0) return x < y;
	return abs(x) < abs(y);
}

long long f(long long kw) {
	m1 = m;
	long long i = 2;
	while(i <= n) {
		int t = m1;
		m1 += c[kw][i];
		if(m1<0 || m1>t) {
			i--;
			break;
		}
		i++;
		if(i > n) {
			i--;
			break;
		}
	}
	return i;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			c[i][j] = a[j]-a[i];
			if(c[i][j] < 0) sum[i] += c[i][j];
			if(c[i][j] == 0) sum0[i]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(abs(-sum[i]-m)<=k) {
			k = abs(-sum[i]-m);
			kw = i;
		}
		if(sum0[i] >= k1) {
			k1 = sum0[i];
			kw1 = i;
		}
	}
	sort(c[kw]+1, c[kw]+1+n, cmp);
	sort(c[kw1]+1, c[kw1]+1+n, cmp);
	long long i1 = f(kw);
	long long i2 = f(kw1);
	printf("%lld", max(i1, i2));
	return 0;
}