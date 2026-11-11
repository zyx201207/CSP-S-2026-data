#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 2e5 + 5;
int n , m;
ll a[N] , ans;
bool rem[32][N];

int main () {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	scanf ("%d%d" , &n , &m);
	for (int i = 1;i <= n;i++) scanf ("%lld" , &a[i]);
	for (int i = 1;i <= n;i++) rem[31][i] = true;
	for (int i = 30;i >= 0;i--) {
		int cnt = 0;
		for (int j = 1;j <= n;j++) if (rem[i + 1][j]&&((a[j] >> i) & 1)) cnt++;
		if (cnt >= m) {
			ans += (ll)(1 << i);
			for (int j = 1;j <= n;j++) if (rem[i + 1][j]&&((a[j] >> i) & 1)) rem[i][j] = true;
		} else {
			for (int j = 1;j <= n;j++) if (rem[i + 1][j]) rem[i][j] = true;
		} 
	}
	printf ("%lld\n" , ans);
}