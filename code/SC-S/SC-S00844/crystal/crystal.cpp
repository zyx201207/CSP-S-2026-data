#include <stdio.h>
#include<algorithm>
#define SIZE 500010
using namespace std;
using ll = long long;
ll N, M;
ll arr[SIZE];
ll sum[SIZE];
bool check(ll x) {
	for (int l = 0, r = x; r <= N; l++, r++) {
		if (x * arr[r] - (sum[r] - sum[l]) <= M) return true;
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", arr + i);
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1 ] + arr[i];
	}
	ll l = 1, r = N, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%lld", r - 1);
}
/*
15:03
*/