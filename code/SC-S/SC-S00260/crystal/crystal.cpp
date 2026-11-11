#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010] , sum[500010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n , m , ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int x = a[i] , xx = i;
		int l = 1 , r = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(x * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) xx = mid , r = mid - 1;
			else l = mid + 1;
//			cout << i << " " << mid << "\n";
		}
		ans = max(ans , i - xx + 1);
	}
	cout << ans;
	return 0;
}