#include <bits/stdc++.h>
#define int long long
#define inf 1e18

using namespace std;

const int N = 5e5 + 10;

int n, m, res;
int a[N], f[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++ ){
		scanf("%lld", &a[i]);
	}
	stable_sort(a + 1, a + n + 1);
	for (int i = n - 1; i >= 1; i -- ){
		f[i] = f[i + 1] + a[n] - a[i];
	}
	for (int i = 1; i <= n; i ++ ){
		int l = i, r = n, ans = -1;
		while (l < r){
			int mid = (l + r + 1) >> 1;
			if (f[i] - (a[n] - a[mid]) * (mid - i + 1) - f[mid + 1] <= m){
				l = mid;ans = mid - i + 1;
			}else{
				r = mid - 1;
			}
		}
		res = max(res, ans);
	}
	cout << res;
	return 0;
}

