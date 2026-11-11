#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5;

int n;
long long w , a[maxn + 5] , pre[maxn + 5];

int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	scanf ("%d%lld" , &n , &w);
	for (int i = 1; i <= n; i++)
		scanf ("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	for (int i = 1; i <= n; i++) 
		pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0 , r = i;
		while (l < r - 1) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= w) r = mid;
			else l = mid;
		}
		ans = max(ans , i - r + 1);
	}
	printf ("%d\n" , ans);
}
