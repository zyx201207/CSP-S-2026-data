#include <bits/stdc++.h>
#define ll long long
using namespace std;

//const int N = 2e6+10;
const int N = 5010;
int c, T, n, f[N][N], num[N][N];
ll d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--) {
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				f[i][j] = 1e9;
			f[i][i] = 0;
		}
		memset(num, 0, sizeof(num));
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(x[j] - x[i] <= d) f[i][j] = 1, num[i][j] = 1;
				else break;
			} 
		}
		for(int o = 2; o < n; o++) {
			for(int i = 1; i < o; i++) {
				for(int j = o + 1; j <= n; j++) {
					int dis = f[i][o] + f[o][j];
					if(f[i][j] > dis)
						num[j][i] = num[i][j] = 1, f[j][i] = f[i][j] = dis;
					else if(f[i][j] == dis)
						++num[i][j], ++num[j][i];
				}
			}
		}
		int tot = 0;
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++)
				if(num[i][j] == 2) ++tot;
		}
		printf("%d\n", tot);
	}
	return 0;
}
