#include <bits/stdc++.h>
using namespace std;
char s[1060000000], l;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		scanf("%d%c%c", &a, &l, &c);
		int su = sum;
		for (long long i = 1LL * sum + 1; i <= su + a; i++) {
			s[i] = c;
			//	printf("s[%d]=%c",i,c);
		}
		sum = 1LL * su + a;
		if (sum > 1060000000) {
			printf("E");
			return 0;
		}
	}
//	for (int i = 1; i <= sum; i++) {
//		printf("s[%d]:%c\n", i, s[i]);
//	}
//	printf("sum:%d\n", sum);
	long long sumt = 0;
	for (long long i = 1; i <= 1LL * sum / 2; i++) { //ÆæÅ¼
		if (s[i] != s[1LL * sum - i + 1])
			sumt++;
	}
	printf("%lld", sumt);
	return 0;
}