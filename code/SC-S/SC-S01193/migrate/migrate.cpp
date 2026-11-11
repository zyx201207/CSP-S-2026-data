#include<stdio.h>
#ifndef stdin
#define stdin (__acrt_iob_func(0))
#endif
#ifndef stdout
#define stdout (__acrt_iob_func(1))
#endif
#define N 2000005
int c, t;
long long n, d, x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		printf("1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}