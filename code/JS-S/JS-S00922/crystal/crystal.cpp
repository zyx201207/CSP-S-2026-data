#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5+5;

int n; ll m; int ans;
ll a[maxn], sum;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%lld", a+i);
	sort(a, a+n);
	for (int i = 0, j = 0; i < n; ++i){
		sum += a[i];
		while (a[i] * (i-j+1) - sum > m) sum -= a[j++];
		ans = max(ans, i-j+1);
	}
	printf("%d\n", ans);
	return 0;
}
