#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
int n;
ll a[N], m, sum[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int j = 0;int ans = 0;
	for(int i = 1;i <= n;i++){
		while(j < i && a[i] * (i - j) - (sum[i] - sum[j]) > m)j++;
		ans = max(ans, i - j);
	}
	printf("%d", ans);
	return 0;
}