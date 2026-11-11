#include <bits/stdc++.h>
using namespace std;
int n, ans, cur;
long long m, lis[500010], cost;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1;i <= n;i ++){
		scanf("%lld", &lis[i]);
	}
	sort(lis + 1, lis + 1 + n);
	cur = ans = 1;
	for (int i = 2;i <= n;i ++){
		cost += (lis[i] - lis[i - 1]) * cur;
		cur ++;
		while (cost > m){
			cost -= (lis[i] - lis[i - cur + 1]);
			cur --;
		}
		ans = max(ans, cur);
	}
	printf("%d", ans);
	return 0;
}
