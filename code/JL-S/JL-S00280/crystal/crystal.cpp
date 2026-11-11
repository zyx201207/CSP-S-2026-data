#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];
int sum[N];

bool check(int mid, int i){
	int tmp = a[i] * (i - mid + 1);
	return (tmp - (sum[i] - sum[mid - 1])) <= m;
}

signed main(){
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, res = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, i)){
				r = mid - 1;
				res = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n";
	return 0;
}