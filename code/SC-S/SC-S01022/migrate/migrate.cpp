#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+50;
int cnt = 0, ans = 0;
bool isvisit[4900][4900];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "e", stdout);
	long long t;
	long long n, d;
	int a[maxn];
	scanf("%lld", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%lld%lld", &n, &d);
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i]);
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (isvisit[i][j] == 0 && a[j] - a[i] <= d && a[j] - a[i] >= 0) {
					isvisit[i][j] = 1;
					if(isvisit[i][k]==1&&isvisit[k][j]==1){
						isvisit[i][j]=1;
						cnt++;
					}
				}
			}
		}
	}if(cnt>=2){
		printf("%d\n",cnt);
	}
	return 0;
}
