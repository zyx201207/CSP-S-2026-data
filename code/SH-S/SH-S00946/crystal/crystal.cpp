#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r, mid, ans, cnt, sum, q, a[500005];
bool b, A = 1;
long long lk(long long mid) {
	cnt = 0; sum = m; q = 0;
	b = 1;
	for(int i = n; i >= 1; i --){
		if(a[i] <= mid){
			if(q == 0) q = i;
			sum -= (mid - a[i]);
			if(sum < 0){
				return cnt;
			} else if(sum == 0) {
				return cnt + 1;
			} else {
				cnt ++;
			}
		}
	}
	if(cnt == n && sum > 0) {
		b = 0;
		return cnt - 1;
	}
	return cnt;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
			A = 0;
		}
	}
	if(A){
		long long o = a[n] - a[n - 1], oo = 0;
		bool v = 1;
		while(m > 0){
			m -= o * oo;
			oo ++;
			if(m >= 0) ans ++;
			if(ans == n){
				v = 0;
				if(m % ans) {
					cout << ans - 1;
				} else {
				    cout << ans;
				}
				break;
			}
		}
		if(v) {
			cout << ans;
		}
	} else {
		sort(a + 1, a + n + 1);
		l = a[1];
		r = a[n] + m;
		while(l < r){
			mid = l + r >> 1;
			long long h = q;
			long long check = lk(mid);
			if(!b){
				ans = max(check, ans);
				l = mid + 1;
			} else if(check > ans) {
				ans = check;
				r = mid;
			} else {
				if(q < h) l = mid + 1;
				else r = mid;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
