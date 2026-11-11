#include <bits/stdc++.h>

int n ;
int main()
{
//	freopen("hub.in", "r", stdin) ;
//	freopen("hub.out", "w", stdout) ;
	srand(time(nullptr)) ;
	scanf("%d %d", &n, &n) ;
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", rand() % 10 + 1) ;
	}
	return 0 ;
}

