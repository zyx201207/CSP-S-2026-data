#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500010], ans = 1, cnt1 = 1, cnt2 = 1;
bool flag = true;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i >= 3 && a[i] - a[i-1] != a[i-1]- a[i-2]) flag = false;
	}
	sort(a + 1, a + n + 1);
	if(flag){
		long long d = a[2] - a[1];
		long long xx = (m / d) * 2;
		long long l = 2, r = xx, mid = (l + r) / 2;
		while(l <= r){
			if((mid - 1) * mid >= xx && (mid - 1) * (mid - 2) <= xx) break;
			if((mid - 1) * mid < xx){
				l = mid;
				mid = (l + r) / 2;
			}
			if((mid - 1) * (mid - 2) > xx){
				r = mid;
				mid = (l + r) / 2;
			}
		}
		if((mid - 1) * mid == xx){
			cout << min(mid, 1ll * n) << endl;
			return 0;
		}
		else{
			cout << min(mid - 1, 1ll * n) <<endl;
			return 0;
		}
	} 
	for(int i = 2; i <= n; i++){
		long long x = m;
		cnt1 = cnt2;
		cnt2 = 1;
		if(a[i] ==a[i-1]){
			cnt2 = cnt1 + 1;
			ans = max(cnt2, ans);
			continue;
		}
		for(int j = i - 1; j >= 1; j--){
			x -= a[i] - a[j];
			if(x >= 0){
				cnt2++;
				ans = max(ans, cnt2);
			} else{
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
