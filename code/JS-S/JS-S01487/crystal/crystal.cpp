#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;
int n, m, ans = 1;
int a[N], s[N];

bool check(int len){
	for(int i = 1;i + len - 1 <= n;i ++){
		int j = i + len - 1;
		if(s[j] - s[i - 1] + m >= a[j] * len) return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++){
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid, l = mid + 1;
		} else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}