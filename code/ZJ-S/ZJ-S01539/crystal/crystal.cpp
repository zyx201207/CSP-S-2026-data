#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define LL long long 
#define int long long
using namespace std;

const int N = 5e5 + 10;
LL ans = 0;
int n, m;
int a[N];

bool check(int x){
	int sum = 0;
	for (int i = 1; i < x; i++){
		sum += a[x] - a[i];
//		cout << a[i] << " " << a[x] << '\n';
	}
	if (sum <= m){
		return 1;
	}
	for (int i = x + 1; i <= n; i++){
		sum = (x - 1) * (a[i] - a[i - 1]) + (sum + a[i - x]  - a[i - 1]);
		if (sum <= m) return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal_std.out", "w", stdout);
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
//	for (int i = 1; i <= n; i++){
//		cout << a[i] << " ";
//	}
	
//	cout << '\n';
	
	int l = 0, r = n;
	int ans = 0;
	while (l <= r){
		int mid = l +r >> 1;
		if (check(mid)){
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}