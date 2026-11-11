#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
long long a[MAXN], k[MAXN] = {0};
bool stl(int a, int b) {
	return a < b;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m;
	scanf("%lld %lld %lld", &n, &m, &a[0]);
	for(long long i = 1; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n, stl);
	for(long long i = 1; i < n; i++) {
		k[i - 1] = a[i] - a[i - 1];
	}
	long long maxn = -1;
	for(long long j = 0; j < n; j++) {
		long long ans = 1, i = j;
		long long m1 = m;
		while(i < n) {
			i += 1;
			if(k[i - 1] * i <= m1) {
				m1 -= k[i - 1] * i;
				ans++;
			}else {
				break;
			}
		}
		maxn = max(maxn, ans);
	}
	printf("%d\n",maxn);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
