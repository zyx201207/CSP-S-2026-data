#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], sum[N], ans;
bool check(int l, int x){
	if(sum[l + x - 1] - sum[l - 1]  + m>= a[l + x - 1] * x) return 1;
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		long long l = 1, r = n - i + 1;
		 while(l < r){
		 	long long mid = (l + r) >> 1;
		 	if(check(i, mid)){
		 		l = mid + 1;
		 		ans = max(mid, ans);
			 }else {
			 	r = mid;
			 }
		 }
	}
	cout << ans;
	return 0;
}
