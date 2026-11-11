#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;
ll a[MAXN], pre[MAXN], m;
int n;
ll get_sum(int l, int i){
	return a[i] * (i - l) - (pre[i - 1] - pre[l - 1]);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int lb = 1, rb = i;
		while (lb + 5 < rb){
			int mid = (lb + rb) >> 1;
			if (get_sum(mid, i) <= m){
				rb = mid;
			}
			else{
				lb = mid;
			}
		}
		for (int j = lb; j <= rb; j++){
			if (get_sum(j, i) <= m){
				ans = max(ans, i - j + 1);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}