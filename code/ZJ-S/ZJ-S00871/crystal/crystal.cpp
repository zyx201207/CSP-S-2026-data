#include<bits/stdc++.h>
using namespace std;
int n, ans;
long long m, a[500010], sum[500010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 0, r = i, cur = 0;
		while(l <= r){
			int mid = (l + r) / 2;
			if((long long)(i - mid) * a[i] <= sum[i] - sum[mid] + m) r = mid - 1, cur = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - cur);
	}
	cout << ans;
	return 0;
}
