// I love Bocchi, game ans Rock & Roll
// Pass 100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[500005], gc, sum[500005];

bool check(int x){
	for (int l = 1; l <= n; l++){
		int r = l + x - 1;
		if (r > n) break;
		if (a[r] * x - sum[r] + sum[l-1] <= m) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	//
	bool flag = 1;
	int pre = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	//
	int ans;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	int l = 0, r = n;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	
	//
	cout << ans << '\n';
	
	return 0;
}