#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx = -1e18 - 10;
int n, m;
const int ma = 1e6 + 10;
int a[ma];
int ans = 0;
int sum[ma] = {0};
//int last = 0;
bool check(int x) {
	int mid = a[x];
	int cnt = m;
	int l = x;
	while(l >= 1) {
		if(cnt >= (mid - a[l])) {
			cnt -= (mid - a[l]);
			ans ++;
			l --;
//			cout << ans << " " << cnt << " " << x << endl; 
		}else{
			break;
		}
	}
	return ans >= maxx;
}
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
	bool flag1 = true;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] != a[i - 1] && i != 1) {
			flag = false;
		}
		if(a[i] != a[i - 1] + 1 && i != 1) {
			flag1 = false;
		}
	}
	if(flag == true) {
		cout << n;
		return 0;
	}
	else if(flag1 == true){
//		for(int i = n - 1; i > = 1; i ++) {
//			sum[i] = sum[i + 1] + 1;
//		}
//		for(int i = 1; i <= n; i ++) {
//			
//			
//		}
		if(m >= ((n - 1) * n / 2)) {
			cout << n;
		}else{
			int ans1 = 1;
			int cnt = 1;
			int x = 2;
			while(cnt <= m) {
				cnt += x;
				x ++;
				if(cnt <= m) {
					ans1 ++;
				}
			
			}
			cout << ans1; 
		}
		
		return 0;
	}
	sort(a + 1, a + 1 + n);	
	for(int i = 1; i <= n; i ++) {
//		int x = a[i];
		ans = 0;
		if(check(i)) {
//			cout << ans;
			maxx = max(maxx, ans);
//			cout << maxx << " " << i << endl;
		}
	}
	cout << maxx;
	return 0;
}
/*5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/ 

