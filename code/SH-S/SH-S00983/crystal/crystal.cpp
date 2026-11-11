#include <bits/stdc++.h>
using namespace std;
long long a[500005], s[500005];
long long n, m, ans = -1;
bool check(long long x, long long y){
	if((x - y + 1) * a[x] - (s[x] - s[y - 1]) <= m){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a, a + n);
	s[0] = a[0];
	for(int i = 1;i < n;i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 0;i < n;i++){
		long long l = i + 1, r = n - 1, sum = i;
		while(l <= r){
			long long mid = (l + r) >> 1;
			if(check(mid, i)){
				sum = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		ans = max(ans, sum - i + 1);
	}
	cout << ans;
	return 0;
} 
