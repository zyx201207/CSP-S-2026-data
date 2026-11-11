#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, t;
int a[N];
int c(int x) {
	int k = n;
	for (int i = 1; i < n; i++){
		if(a[i] <= x && a[i + 1] > x) k = i;
	}
	int sum = 0, cnt = 0;
	for (int i = k; i >= 1; i--) {
		if(sum <= m && (sum + (x - a[i])) > m){
			return cnt;
		} else {
			sum += x - a[i];
			cnt++;
		}
	}
	return cnt;
}
int chai(int x, int t) {
	int j = 1, cnt = 0;
	while(x > 0 && x >= j) {
		x -= j;
		j += t;
		cnt++;
	}
	return cnt;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	cin >> n >> m;
	int s = 0, cs = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == i) s++;
	}
	
	sort(a + 1, a + n + 1);
	
	if(s == n) {
		cout << chai(m, 1) + 1;
		return 0;
	}
	
	int cha = a[2] - a[1];
	for (int i = 2; i < n; i++) {
		if(a[i + 1] - a[i] == cha) {
			cs++;
		}
	}
	if(cs == n - 2){
		if(m < cha) {
			cout << 1;
			return 0;
		}
		cout << chai(m, cha) + 1;
		return 0;
	}
	
	int ans = -1;
	for (int i = a[1]; i <= a[n]; i++) {
		ans = max(ans, c(i));
	}
	cout << ans;
	return 0;
}