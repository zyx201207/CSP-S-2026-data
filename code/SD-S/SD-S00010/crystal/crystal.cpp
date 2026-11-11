#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bitset>

using namespace std;
const int N = 5e5 + 5;
#define ll long long
#define endl '\n'
ll a[N], sum[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 1; ll m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++)
		sum[i] = a[i] + sum[i-1];
	
	for(int i = 2; i <= n; i++) {
		int l = 1, r = i-1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(a[i]*(i-mid+1) - (sum[i]-sum[mid-1]) <= m)
				r = mid;
			else
				l = mid+1;
		}
		ans = max(ans, i-l+1);
	}
	cout << ans << endl;
	return 0;
}

