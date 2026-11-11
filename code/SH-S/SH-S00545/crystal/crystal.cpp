#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
#define int long long
int n , m , a[N] , s[N];
int ans = 0;
bool ok(int i , int x){
	return (a[x] * (x - i + 1) - (s[x] - s[i - 1])) <= m;
}
int solve(int x){
//	if (x == 1){
//		return 1;
//	}
	int l = 1 , r = x , ans = -1;
	while (l <= r){
		int mid = l + ((r - l) >> 1);
		if (ok(mid,x)){
			ans = x - mid + 1;
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n ;i++){
		s[i] = s[i-1] + a[i];
	}
	for (int i = 1;i <= n;i++){
		ans = max(ans,solve(i));
	} 
	cout << ans; 
	return 0 ;
} 
