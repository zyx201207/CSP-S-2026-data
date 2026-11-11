#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n,ans;
ll m,a[N],sum[N];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++){
		int r = i, nl = 1, nr = r, ansl = r;
		ll cst = m + sum[r] - a[r] * (r + 1);
		while (nl <= nr){
			int mid = nl + nr >> 1;
			if (sum[mid - 1] - a[r] * mid <= cst) nr = mid - 1, ansl = mid;
			else nl = mid + 1;
		}
		ans = max (ans, r - ansl + 1);
	}
	cout << ans;
} 
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve(); 
	return 0;
}
