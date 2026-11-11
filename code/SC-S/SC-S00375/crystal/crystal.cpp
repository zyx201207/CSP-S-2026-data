#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max_n = 5e5 + 10;
int n, m;
int a[Max_n], c[Max_n];
bool check(int x){
	int sum = 0;
	for(int i = 2; i <= x; i++){
		sum += c[i] * (i - 1);
	}
	if(sum <= m) return 1;
	for(int i = x + 1, j = max(i - x, 0ll); i <= n; i++, j++){
		sum += c[i] * (x - 1);
		sum -= a[i-1] - a[j];
		if(sum <= m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) c[i] = abs(a[i] - a[i-1]);
	int l = 1, r = n, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = max(ans, mid);
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 