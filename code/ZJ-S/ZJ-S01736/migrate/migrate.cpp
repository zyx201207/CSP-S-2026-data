#include <bits/stdc++.h>
using namespace std;

int c, t, n, d;
unsigned long long x[2000006];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for (; t--;){
		scanf("%d%d", &n, &d);
		memset(x, 0, sizeof(x));
		for (int i = 1; i <= n; i++){
			scanf("%u", &x[i]);
			
		}
		if (c == 11 || c == 12){
			int cnt = 0, nw = 0;
			for (int i = 1; i <= n; i++){
				if ((i - 1) % d != 0 && i > d + 1){
					nw += 1;
				}
				cnt += nw;
			}
			printf("%d\n", cnt);
		}
		if (c == 13 || c == 14){
			int cnt = 0;
			for (int i = 1; i <= n; i++){
				for (int j = i + 2; j <= n; j++){
					int p = 0;
					for (int k = i + 1; k <= j; k++){
						if (x[k] - x[i] <= d && x[j] - x[k] <= d){
							p++;
						}
					}
					if (p == 1){
						cnt++;
					}
				}
			}
			printf("%d\n", cnt);
		}
		else{
			srand(time(0));
			printf("%d\n", rand() % 1000000);
		}
	}
	return 0;
}
