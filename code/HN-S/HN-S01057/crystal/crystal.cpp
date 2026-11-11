#include<bits/stdc++.h>
using namespace std;
int n, l, r, ans;
long long m, a[500001], sum[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		l = 1, r = i;
		while(l < r){
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m)r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%d", ans);
	return 0;
}
