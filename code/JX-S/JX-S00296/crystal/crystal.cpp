#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 7;
typedef long long ll;
typedef pair <int, int> pll;
int n;
ll m;
ll a[N], w[N], mx = 0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) w[i] = w[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i; ll res = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[i] * mid - (w[i] - w[i - mid]) <= m) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		mx = max(mx, res);
	}
	cout << mx << "\n";
	return 0;
}
