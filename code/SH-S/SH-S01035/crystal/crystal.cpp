#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using i64 = long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n , m;
	cin >> n >> m;
	vector<i64> a(n + 1) , b(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i = 1; i <= n; i++){
		b[i] = b[i-1] + a[i];
	}
	auto check = [&](int p) -> int{
		int ans = p;
		int l = 1 , r = p;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[p] * (p - mid + 1) - b[p] + b[mid-1] > m){
				l = mid + 1;
			}else{
				r = mid - 1;
				ans = mid;
			}
		}
		return p - ans + 1;
//		int ans = 0;
//		i64 tm = m;
//		for(int i = p; i >= 1; i--){
//			if(tm < a[p] - a[i]){
//				return ans;
//			}
//			tm -= a[p]-a[i];
//			ans++;
//		}
//		return ans;
	};
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans , check(i));
	}
	cout << ans;
} 
