#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
long long sum[N], a[N], diff[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}	
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		diff[i] = a[i + 1] - a[i];
		sum[i] = sum[i - 1] + diff[i];
	}
	long long tt = 0, head = 1, cnt = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		tt += (i - head + 1) * diff[i];
		cnt++;
		while(tt > m && head < n) {
			tt -= sum[head + cnt] - sum[head];
			cnt--;
			ans = max(ans, cnt);
			head++;
		}
	}
	ans = max(ans, cnt);
	printf("%d", ans + 1);
	return 0;
}
