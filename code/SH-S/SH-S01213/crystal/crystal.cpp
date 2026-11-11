#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
 	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	int l = 1, r = 1, cost = 0, ans = 1;
	while(r <= n){
		if(cost <= m){
			int cnt = r - l + 1;
			cost += (a[r+1] - a[r]) * cnt;
			ans = max(ans, cnt);
			
			r++;
		} else {
			cost -= (a[r] - a[l]);
			
			l++;
		}
	}
	
	cout << ans;
	
	return 0;
}

