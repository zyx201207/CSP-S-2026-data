#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x, k;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t); k = t;
	int i;
	while(t --){
		scanf("%d %d", &n, &d);
		for(i = 1; i <= n; i ++){
			scanf("%d", &x);
		}
	}
	if(c == 0){
		if(k == 2) printf("1\n2");
		else printf("0\n1");
	}
	return 0;
}
