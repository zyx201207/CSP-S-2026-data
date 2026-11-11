#include <bits/stdc++.h> 
using namespace std;
#define LL long long
const int N = 305;
int c, t, n;
LL d, x[N];
struct node{
	int num, dis;
}a[N][N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while(t--) {
		int ans = 0;
		scanf("%d %lld", &n, &d);
		for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		for(int i = 2; i <= n; i++) {
			for(int j = i - 1; j >= 1; j--) {
				a[j][i].dis = INT_MAX;
				a[j][i].num = 0;
				if(x[i] - x[j] <= d) {
					a[j][i].dis = 1;
					a[j][i].num = 1;
				}else if(j < i - 1){
					for(int k = j + 1; k <= i - 1; k++) {
						if(a[j][k].dis == INT_MAX || a[k][i].dis == INT_MAX) continue;
						if(a[j][k].dis + a[k][i].dis < a[j][i].dis) {
							a[j][i].dis = a[j][k].dis + a[k][i].dis;
							a[j][i].num = a[j][k].num * a[k][i].num;
						}else if(a[j][k].dis + a[k][i].dis == a[j][i].dis) {
							a[j][i].num += a[j][k].num * a[k][i].num;
						}
					}
				}
				if(a[j][i].num == 2) ans++;
			}
		}
		printf("%d\n", ans);
 	}
	return 0;
}
