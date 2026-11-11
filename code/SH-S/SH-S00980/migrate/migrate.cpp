#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long a[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n;
	long long d;
	scanf("%d%d", &c, &t);
	while(t--) {
		bool flag = 1;
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			if(i >= 3 && a[i - 1] - a[i - 2] != a[i] - a[i - 1]) flag = 0;
		}
		if(flag) {
			long long x = a[n] - a[n - 1];
			if(n == d / x * 2) printf("1");
			else if(n > d / x * 2) printf("2");
			else printf("0"); 
		}
	}
	return 0;
} 
