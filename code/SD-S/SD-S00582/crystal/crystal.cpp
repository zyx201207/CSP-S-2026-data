#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 5e5 + 5;
ll a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 1;
	ll m, sum = 0;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int r = 1, l = 1; r <= n; r++){
		while(sum > m && l < r){
			sum -= a[r] - a[l];
			l++;
		}
		int len = r - l + 1;
		ans = max(ans, len);
		sum += 1ll * len * (a[r + 1] - a[r]);
	}
	printf("%lld", ans);
	return 0;
} 
