#include <iostream>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define LL long long
#define int long long
using namespace std;

const int N = 2e6 + 10;
int x[N], L[N], R[N];
int n, d;

bool check(){
	int mn = 1e9;
	for (int i = n - 1; i >= 1; i--){
		if (R[i] >= mn) return 0;
		if (R[i] < L[i + 1]) return 0;
		mn = min(mn, L[i + 1]);
	}
	return 1;
}

void tc(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	map<int, int> mpl, mpr;
	for (int i = 1; i <= n; i++){
		int l = i, r = n;
		L[i] = R[i] = -1;
		while (l <= r){
			int mid = l + r >> 1;
			if (x[mid] - x[i] <= d){
				l = mid + 1;
				R[i] = mid;
			} else {
				r = mid - 1;
			}
		}
		l = 1, r = i;
		while (l <= r){
			int mid = l + r >> 1;
			if (x[i] - x[mid] <= d){
				r = mid - 1;
				L[i] = mid;
			} else {
				l = mid + 1;
			}
		}
		if (L[i] != i) mpl[L[i]] ++;
		if (R[i] != i) mpr[R[i]] ++;
	}
	LL ans = check();
	for (int i = 1; i <= n; i++){
		if (i - 1 >= 1){
			ans += mpr[i] * mpl[i - 1];
		} 
		if (i + 1 <= n){
			ans += mpl[i] * mpr[i + 1];
		}
	}	
	
	cout << ans << '\n';
	
	return ;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fast;
	int c, t;
	cin >> c >> t;
	while (t --){
		tc();
	}
	return 0;
}