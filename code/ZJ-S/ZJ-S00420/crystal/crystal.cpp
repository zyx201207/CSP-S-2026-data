#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], ans, g;
bool is_spea = true, is_speb = true;

bool check(int x){
	if(x * (x + 1) / 2 <= m) return true;
	return false;
}

bool check1(int x){
	if(x * (x + 1) / 2 * g <= m) return true;
	else return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != i){
			is_spea = false;
		}
	}
	g = a[2] - a[1];
	for(int i = 3;i <= n;i ++){
		if(a[i] - a[i - 1] != g){
			is_speb = false;
			break;
		}
	}
	if(is_spea == true){
		int l = 1, r = n;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << r;
		return 0;
	}
	if(is_speb == true){
		int l = 1, r = n;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << r;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i < n;i ++){
		if(a[i + 1] - a[i] <= m / i){
			m -= (a[i + 1] - a[i]) * i;
		} else {
			ans = i;
			break;
		}
	}
	if(ans == 0) ans = n;
	cout << ans;
	return 0;
}
