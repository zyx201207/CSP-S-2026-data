#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 5;
int n , ans;
ll m , a[N] , pre[N];

int main () {
	freopen("crystal.in" , "r" , stdin); 
	freopen("crystal.out" , "w" , stdout); 
	scanf ("%d%lld" , &n , &m);
	for (int i = 1;i <= n;i++) scanf ("%lld" , &a[i]);
	sort (a + 1 , a + n + 1);
	for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1;i <= n;i++) {
		int L = 0 , R = i;
		while (L + 1 != R) {
			int mid = (L + R) >> 1;
			if ((ll)(i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m) R = mid;
			else L = mid;
		}
		ans = max(ans , i - R + 1);
	}
	printf ("%d\n" , ans); 
}